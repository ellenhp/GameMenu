#ifndef GUI_BUTTON_H
#define GUI_BUTTON_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "gui_mgr.h"

widget_t* create_slider(char* text, widget_click_callback_t down_cb, widget_click_callback_t up_cb);

#ifdef __cplusplus
}
#endif

#endif
