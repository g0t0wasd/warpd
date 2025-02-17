/*
 * warpd - A modal keyboard-driven pointing system.
 *
 * © 2019 Raheman Vaiya (see: LICENSE).
 */

#include "X.h"

Display *dpy = NULL;

int hex_to_rgba(const char *str, uint8_t *r, uint8_t *g, uint8_t *b, uint8_t *a)
{
#define X2B(c) ((c >= '0' && c <= '9') ? (c & 0xF) : (((c | 0x20) - 'a') + 10))

	if (str == NULL)
		return 0;
	str = (*str == '#') ? str + 1 : str;

	ssize_t len = strlen(str);

	if (len != 6 && len != 8)
		return -1;

	*r = X2B(str[0]);
	*r <<= 4;
	*r |= X2B(str[1]);

	*g = X2B(str[2]);
	*g <<= 4;
	*g |= X2B(str[3]);

	*b = X2B(str[4]);
	*b <<= 4;
	*b |= X2B(str[5]);

	*a = 255;
	if (len == 8) {
		*a = X2B(str[6]);
		*a <<= 4;
		*a |= X2B(str[7]);
	}

	return 0;
}

uint32_t parse_xcolor(const char *s, uint8_t *opacity)
{
	XColor col;

	uint8_t r, g, b, a;

	hex_to_rgba(s, &r, &g, &b, &a);

	if (opacity)
		*opacity = a;

	col.red = (int)r << 8;
	col.green = (int)g << 8;
	col.blue = (int)b << 8;
	col.flags = DoRed | DoGreen | DoBlue;

	assert(
	    XAllocColor(dpy, XDefaultColormap(dpy, DefaultScreen(dpy)), &col));

	return col.pixel;
}

/*
 * Disable shadows for compton based compositors.
 *
 * Ref:
 * https://github.com/yshui/picom/blob/aa316aa3601a4f3ce9c1ca79932218ab574e61a7/src/win.c#L850
 */
static void disable_compton_shadow(Display *dpy, Window w)
{
	Atom _COMPTON_SHADOW = XInternAtom(dpy, "_COMPTON_SHADOW", False);
	unsigned int v = 0;

	XChangeProperty(dpy, w, _COMPTON_SHADOW, XA_CARDINAL, 32,
			PropModeReplace, (unsigned char *)&v, 1L);
}

static void set_opacity(Display *dpy, Window w, uint8_t _opacity)
{
	Atom OPACITY_ATOM = XInternAtom(dpy, "_NET_WM_WINDOW_OPACITY", False);

	unsigned int opacity =
	    (unsigned int)(((double)_opacity / 255) * (double)0xffffffff);

	XChangeProperty(dpy, w, OPACITY_ATOM, XA_CARDINAL, 32, PropModeReplace,
			(unsigned char *)&opacity, 1L);
}

void platform_copy_selection()
{
	XTestFakeKeyEvent(dpy, XKeysymToKeycode(dpy, XK_Control_L), True,
			  CurrentTime);
	XTestFakeKeyEvent(dpy, XKeysymToKeycode(dpy, XK_Insert), True,
			  CurrentTime);

	XTestFakeKeyEvent(dpy, XKeysymToKeycode(dpy, XK_Control_L), False,
			  CurrentTime);
	XTestFakeKeyEvent(dpy, XKeysymToKeycode(dpy, XK_Insert), False,
			  CurrentTime);
	XSync(dpy, False);

	system("xclip -o|xclip -selection CLIPBOARD");
}

void platform_scroll(int direction)
{
	int btn = 0;

	switch (direction) {
	case SCROLL_UP:
		btn = 4;
		break;
	case SCROLL_DOWN:
		btn = 5;
		break;
	case SCROLL_RIGHT:
		btn = 7;
		break;
	case SCROLL_LEFT:
		btn = 6;
		break;
	}

	XTestFakeButtonEvent(dpy, btn, True, CurrentTime);
	XTestFakeButtonEvent(dpy, btn, False, CurrentTime);
}

Window create_window(const char *color)
{
	uint32_t col = 0;
	XClassHint *hint;
	uint8_t opacity;

	col = parse_xcolor(color, &opacity);

	Window win = XCreateWindow(
	    dpy, DefaultRootWindow(dpy), 0, 0, 1, 1, 0,
	    DefaultDepth(dpy, DefaultScreen(dpy)), InputOutput,
	    DefaultVisual(dpy, DefaultScreen(dpy)),
	    CWOverrideRedirect | CWBackPixel | CWBackingStore | CWBackingPixel,
	    &(XSetWindowAttributes){
		.backing_pixel = col,
		.background_pixel = col,
		.backing_store = Always,
		.override_redirect = 1,
	    });

	/* Requires a compositor. */
	set_opacity(dpy, win, opacity);

	disable_compton_shadow(dpy, win);

	hint = XAllocClassHint();
	hint->res_name = "warpd";
	hint->res_class = "warpd";
	XSetClassHint(dpy, win, hint);

	XFree(hint);

	return win;
}

void platform_run(void (*init)(void))
{
	dpy = XOpenDisplay(NULL);

	/* TODO: account for screen hotplugging */
	init_screens();
	init();
}

void platform_commit() 
{
	XSync(dpy, False); 
}
