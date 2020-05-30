//GENERATED BY gen_assets.py.

#ifndef _CFG_H_
#define _CFG_H_

struct cfg {
    char* hint_activation_key;
    char* grid_activation_key;
    char* discrete_activation_key;
    int movement_increment;
    char* buttons;
    int double_click_timeout;
    int grid_nr;
    int grid_nc;
    char* grid_up;
    char* grid_left;
    char* grid_down;
    char* grid_right;
    char* grid_keys;
    char* grid_col;
    char* grid_mouse_col;
    int grid_pointer_size;
    int grid_line_width;
    int hint_width;
    int hint_height;
    char* hint_up;
    char* hint_left;
    char* hint_down;
    char* hint_right;
    char* hint_bgcol;
    char* hint_fgcol;
    char* hint_characters;
    int hint_opacity;
    char* discrete_left;
    char* discrete_down;
    char* discrete_up;
    char* discrete_right;
    char* discrete_indicator_color;
    int discrete_indicator_size;
};

struct cfg* parse_cfg(const char *fname);

#endif
