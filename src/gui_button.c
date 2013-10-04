#include <stdlib.h>
#include <string.h>
#include "gui_button.h"

widget_t* create_button(char* text, widget_click_callback_t click_cb)
{
	widget_t* btn=(widget_t*)malloc(sizeof(widget_t));
	char* text_cpy=(char*)malloc(strlen(text));
	strcpy(text_cpy, text);
	btn->callback1=click_cb;
	btn->text=text_cpy;
	btn->type=BUTTON;
	return btn;
}
