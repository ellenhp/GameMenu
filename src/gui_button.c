#include <stdlib.h>
#include <string.h>
#include "gui_button.h"

widget_t* create_button(char* text, widget_click_callback_t click_cb)
{
	widget_t* btn=(widget_t*)malloc(sizeof(widget_t));
	btn->text=0;
	widget_set_text(btn, text);
	btn->callback1=click_cb;
	btn->type=BUTTON;
	return btn;
}
