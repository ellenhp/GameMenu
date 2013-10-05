#include <stdlib.h>
#include <string.h>
#include "gui_button.h"

widget_t* create_slider(char* text, widget_click_callback_t down_cb,  widget_click_callback_t up_cb)
{
	widget_t* btn=(widget_t*)malloc(sizeof(widget_t));
	btn->text=0;
	widget_set_text(btn, text);
	btn->callback1=up_cb;
	btn->callback2=down_cb;
	btn->type=SLIDER;
	return btn;
}
