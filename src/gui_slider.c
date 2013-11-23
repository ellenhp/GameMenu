#include <stdlib.h>
#include <string.h>
#include "gui_button.h"
#include "gui_slider.h"

void slider_value_changed(int button, int mouse_x, int mouse_y, widget_bounding_box_t bb, input_type_t input_type, widget_t* widget)
{
	/*if (mouse_x<bb.x+bb.width/3)
	{
		widget->option--;
		widget->option=(widget->option+widget->total_options) % widget->total_options;
	}
	else if (mouse_y>bb.x+2*bb.width/3)
	{
		widget->option++;
		widget->option %= widget->total_options;
	}*/
	widget->option++;
	widget->option %= widget->total_options;

	slider_set_value(widget, widget->option);
	if (widget->callback2)
	{
		widget->callback2(button, mouse_x, mouse_y, bb, input_type, widget);
	}
}

widget_t* create_slider(char* text, int num_options, char* options, widget_click_callback_t changed)
{
	widget_t* slider=(widget_t*)malloc(sizeof(widget_t));

	slider->text=0;
	slider->callback2=changed;
	slider->callback1=slider_value_changed;
	slider->option=0;
	slider->total_options=num_options;
	slider->type=SLIDER;

	slider->data1=(char*)malloc(strlen(text)+1);
	strcpy(slider->data1, text);

	if (options)
	{
		slider->data2=(char*)malloc(strlen(options)+1);
		strcpy(slider->data2, options);
	}
	else
	{
		slider->data2=0;
	}
	
	return slider;
}

