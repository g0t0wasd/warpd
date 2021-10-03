//GENERATED BY gen_assets.py

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "cfg.h"

static int kvp(char *line, char **key, char **val) {
  *key = NULL;
  *val = NULL;
  
  for(;*line != '\0';line++) {
    if(*line != ' ' && !*key)
      *key = line;
    
    if(*line == ':' && !*val) {
      *line++ = '\0';
      for(;isspace(*line);line++);
      *val = line;
    }
  }
  
  if(*(line - 1) == '\n')
    *(line - 1) = '\0';
  
  if(!(*val && *key))
    return -1;
  
  return 0;
}

struct cfg* parse_cfg(const char *fname) {
    char *line = NULL;
    size_t n = 0, ln = 0;
    struct cfg *cfg = malloc(sizeof(struct cfg));

    cfg->hint_activation_key = "A-M-x";
    cfg->grid_activation_key = "A-M-z";
    cfg->normal_activation_key = "A-M-c";
    cfg->movement_increment = 20;
    cfg->buttons = "m,comma,period,q,e,r,t";
    cfg->exit = "Escape";
    cfg->double_click_timeout = 300;
    cfg->drag_key = "v";
    cfg->grid_nr = 2;
    cfg->grid_nc = 2;
    cfg->grid_up = "w";
    cfg->grid_left = "a";
    cfg->grid_down = "s";
    cfg->grid_right = "d";
    cfg->grid_keys = "u,i,j,k";
    cfg->grid_color = "#ff0000";
    cfg->grid_mouse_color = "#00ff00";
    cfg->grid_pointer_size = 20;
    cfg->grid_line_width = 5;
    cfg->hint_width = 40;
    cfg->hint_height = 30;
    cfg->hint_bgcolor = "#00ff00";
    cfg->hint_fgcolor = "#000000";
    cfg->hint_characters = "asdfghjkl;'zxcvbm,./";
    cfg->hint_opacity = 100;
    cfg->hint_border_radius = 0;
    cfg->normal_oneshot = "n";
    cfg->normal_left_word = "b";
    cfg->normal_right_word = "w";
    cfg->normal_down_word = "S-j";
    cfg->normal_up_word = "S-k";
    cfg->normal_left = "h";
    cfg->normal_down = "j";
    cfg->normal_up = "k";
    cfg->normal_right = "l";
    cfg->normal_color = "#00ff00";
    cfg->normal_size = 20;
    cfg->normal_home = "S-h";
    cfg->normal_middle = "S-m";
    cfg->normal_last = "S-l";
    cfg->normal_beginning = "S-6";
    cfg->normal_end = "S-4";
    cfg->normal_word_size = 80;
    cfg->normal_hint_key = "x";
    cfg->normal_grid_key = "g";
    cfg->normal_hist_back = "C-o";
    cfg->normal_hist_forward = "C-i";
    cfg->scroll_fling_timeout = 150;
    cfg->scroll_fling_velocity = 40;
    cfg->scroll_fling_acceleration = 10;
    cfg->scroll_fling_deceleration = 30;
    cfg->scroll_velocity = 10;
    cfg->scroll_acceleration = 30;
    cfg->scroll_down_key = "M-A-j";
    cfg->scroll_up_key = "M-A-k";
    cfg->scroll_right_key = "M-A-l";
    cfg->scroll_left_key = "M-A-h";

    FILE *fp = fopen(fname, "r");
    if(!fp) return cfg; //Return defaults if no config file xists..
    while(getline(&line, &n, fp) != -1) {
        ln++;
        char *key, *val;

        if(line[0] == '\n' || line[0] == '\0') continue;

        if(kvp(line, &key, &val)) {
            fprintf(stderr, "Invalid entry in %s at line %lu.\n", fname, ln);
            exit(1);
        }

        if(!strcmp(key, "hint_activation_key"))
            cfg->hint_activation_key = strdup(val);
        else if(!strcmp(key, "grid_activation_key"))
            cfg->grid_activation_key = strdup(val);
        else if(!strcmp(key, "normal_activation_key"))
            cfg->normal_activation_key = strdup(val);
        else if(!strcmp(key, "movement_increment"))
            cfg->movement_increment = atoi(val);
        else if(!strcmp(key, "buttons"))
            cfg->buttons = strdup(val);
        else if(!strcmp(key, "exit"))
            cfg->exit = strdup(val);
        else if(!strcmp(key, "double_click_timeout"))
            cfg->double_click_timeout = atoi(val);
        else if(!strcmp(key, "drag_key"))
            cfg->drag_key = strdup(val);
        else if(!strcmp(key, "grid_nr"))
            cfg->grid_nr = atoi(val);
        else if(!strcmp(key, "grid_nc"))
            cfg->grid_nc = atoi(val);
        else if(!strcmp(key, "grid_up"))
            cfg->grid_up = strdup(val);
        else if(!strcmp(key, "grid_left"))
            cfg->grid_left = strdup(val);
        else if(!strcmp(key, "grid_down"))
            cfg->grid_down = strdup(val);
        else if(!strcmp(key, "grid_right"))
            cfg->grid_right = strdup(val);
        else if(!strcmp(key, "grid_keys"))
            cfg->grid_keys = strdup(val);
        else if(!strcmp(key, "grid_color"))
            cfg->grid_color = strdup(val);
        else if(!strcmp(key, "grid_mouse_color"))
            cfg->grid_mouse_color = strdup(val);
        else if(!strcmp(key, "grid_pointer_size"))
            cfg->grid_pointer_size = atoi(val);
        else if(!strcmp(key, "grid_line_width"))
            cfg->grid_line_width = atoi(val);
        else if(!strcmp(key, "hint_width"))
            cfg->hint_width = atoi(val);
        else if(!strcmp(key, "hint_height"))
            cfg->hint_height = atoi(val);
        else if(!strcmp(key, "hint_bgcolor"))
            cfg->hint_bgcolor = strdup(val);
        else if(!strcmp(key, "hint_fgcolor"))
            cfg->hint_fgcolor = strdup(val);
        else if(!strcmp(key, "hint_characters"))
            cfg->hint_characters = strdup(val);
        else if(!strcmp(key, "hint_opacity"))
            cfg->hint_opacity = atoi(val);
        else if(!strcmp(key, "hint_border_radius"))
            cfg->hint_border_radius = atoi(val);
        else if(!strcmp(key, "normal_oneshot"))
            cfg->normal_oneshot = strdup(val);
        else if(!strcmp(key, "normal_left_word"))
            cfg->normal_left_word = strdup(val);
        else if(!strcmp(key, "normal_right_word"))
            cfg->normal_right_word = strdup(val);
        else if(!strcmp(key, "normal_down_word"))
            cfg->normal_down_word = strdup(val);
        else if(!strcmp(key, "normal_up_word"))
            cfg->normal_up_word = strdup(val);
        else if(!strcmp(key, "normal_left"))
            cfg->normal_left = strdup(val);
        else if(!strcmp(key, "normal_down"))
            cfg->normal_down = strdup(val);
        else if(!strcmp(key, "normal_up"))
            cfg->normal_up = strdup(val);
        else if(!strcmp(key, "normal_right"))
            cfg->normal_right = strdup(val);
        else if(!strcmp(key, "normal_color"))
            cfg->normal_color = strdup(val);
        else if(!strcmp(key, "normal_size"))
            cfg->normal_size = atoi(val);
        else if(!strcmp(key, "normal_home"))
            cfg->normal_home = strdup(val);
        else if(!strcmp(key, "normal_middle"))
            cfg->normal_middle = strdup(val);
        else if(!strcmp(key, "normal_last"))
            cfg->normal_last = strdup(val);
        else if(!strcmp(key, "normal_beginning"))
            cfg->normal_beginning = strdup(val);
        else if(!strcmp(key, "normal_end"))
            cfg->normal_end = strdup(val);
        else if(!strcmp(key, "normal_word_size"))
            cfg->normal_word_size = atoi(val);
        else if(!strcmp(key, "normal_hint_key"))
            cfg->normal_hint_key = strdup(val);
        else if(!strcmp(key, "normal_grid_key"))
            cfg->normal_grid_key = strdup(val);
        else if(!strcmp(key, "normal_hist_back"))
            cfg->normal_hist_back = strdup(val);
        else if(!strcmp(key, "normal_hist_forward"))
            cfg->normal_hist_forward = strdup(val);
        else if(!strcmp(key, "scroll_fling_timeout"))
            cfg->scroll_fling_timeout = atoi(val);
        else if(!strcmp(key, "scroll_fling_velocity"))
            cfg->scroll_fling_velocity = atoi(val);
        else if(!strcmp(key, "scroll_fling_acceleration"))
            cfg->scroll_fling_acceleration = atoi(val);
        else if(!strcmp(key, "scroll_fling_deceleration"))
            cfg->scroll_fling_deceleration = atoi(val);
        else if(!strcmp(key, "scroll_velocity"))
            cfg->scroll_velocity = atoi(val);
        else if(!strcmp(key, "scroll_acceleration"))
            cfg->scroll_acceleration = atoi(val);
        else if(!strcmp(key, "scroll_down_key"))
            cfg->scroll_down_key = strdup(val);
        else if(!strcmp(key, "scroll_up_key"))
            cfg->scroll_up_key = strdup(val);
        else if(!strcmp(key, "scroll_right_key"))
            cfg->scroll_right_key = strdup(val);
        else if(!strcmp(key, "scroll_left_key"))
            cfg->scroll_left_key = strdup(val);

        free(line);
        line = NULL;
        n = 0;
    }

    return cfg;
}
