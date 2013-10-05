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

void TRGui_motion_func( int x, int y );
void TRGui_mouse_func( int button, int state, int x, int y );

void TRGui_simulate_click(widget_t* widget);

void TRGui_init();

widget_bounding_box_t TRGui_get_bb(widget_t* widget);
void TRGui_draw_text(char* text, int active, coord_t coord);
coord_t get_absolute(coord_t coord, int asc, int desc);

int TRGui_get_window_height();
int TRGui_get_window_width();

int TRGui_joystick_enabled();
double TRGui_get_joystick_x();
double TRGui_get_joystick_y();
int TRGui_joystick_button_down(int button);

#ifdef __cplusplus
}
#endif

#endif