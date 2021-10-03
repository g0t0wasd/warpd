//GENERATED BY gen_assets.py.

#ifndef _CFG_H_
#define _CFG_H_

struct cfg {
    char* hint_activation_key;
    char* grid_activation_key;
    char* normal_activation_key;
    int movement_increment;
    char* buttons;
    char* exit;
    int double_click_timeout;
    char* drag_key;
    int grid_nr;
    int grid_nc;
    char* grid_up;
    char* grid_left;
    char* grid_down;
    char* grid_right;
    char* grid_keys;
    char* grid_color;
    char* grid_mouse_color;
    int grid_pointer_size;
    int grid_line_width;
    int hint_width;
    int hint_height;
    char* hint_bgcolor;
    char* hint_fgcolor;
    char* hint_characters;
    int hint_opacity;
    int hint_border_radius;
    char* normal_oneshot;
    char* normal_left_word;
    char* normal_right_word;
    char* normal_down_word;
    char* normal_up_word;
    char* normal_left;
    char* normal_down;
    char* normal_up;
    char* normal_right;
    char* normal_color;
    int normal_size;
    char* normal_home;
    char* normal_middle;
    char* normal_last;
    char* normal_beginning;
    char* normal_end;
    int normal_word_size;
    char* normal_hint_key;
    char* normal_grid_key;
    char* normal_hist_back;
    char* normal_hist_forward;
    int scroll_fling_timeout;
    int scroll_fling_velocity;
    int scroll_fling_acceleration;
    int scroll_fling_deceleration;
    int scroll_velocity;
    int scroll_acceleration;
    char* scroll_down_key;
    char* scroll_up_key;
    char* scroll_right_key;
    char* scroll_left_key;
};

struct cfg* parse_cfg(const char *fname);

#endif
