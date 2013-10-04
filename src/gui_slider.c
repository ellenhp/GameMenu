#include <stdlib.h>
#include <string.h>
#include "gui_button.h"

widget_t* create_slider(char* text, widget_click_callback_t down_cb,  widget_click_callback_t up_cb)
{
	widget_t* btn=(widget_t*)malloc(sizeof(widget_t));
	char* text_cpy=(char*)malloc(strlen(text));
	strcpy(text_cpy, text);
	btn->callback1=up_cb;
	btn->callback2=down_cb;
	btn->text=text_cpy;
	btn->type=SLIDER;
	return btn;
}
