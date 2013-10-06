#ifndef GUI_ABSTRACTION_H
#define GUI_ABSTRACTION_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "gui_mgr.h"

/*typedef struct font_metrics_t
{
	int asc, desc, width;
} font_metrics_t;
*/

void GameMenu_motion_func( int x, int y );
void GameMenu_mouse_func( int button, int state, int x, int y );

void GameMenu_keypress( int key );

void GameMenu_simulate_click(widget_t* widget);

void GameMenu_init();

widget_bounding_box_t GameMenu_get_bb(widget_t* widget);
void GameMenu_draw_text(char* text, int active, coord_t coord);
coord_t get_absolute(coord_t coord, int asc, int desc);

int GameMenu_get_window_height();
int GameMenu_get_window_width();

#ifdef __cplusplus
}
#endif

#endif