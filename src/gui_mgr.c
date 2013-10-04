#include <stdlib.h>
#include "gui_mgr.h"
#include "gui_abstraction.h"
#include <limits.h>
#include <math.h>

widget_list_item_t* top;

widget_list_item_t* active_item;

int mouse_x, mouse_y;

void gui_mouse_motion_event(int x, int y)
{
	mouse_x=x;
	mouse_y=y;
}

void gui_mouse_button_event(int button, int down, int x, int y)
{
	widget_click_callback_t cb;
	if (down)
	{
		widget_list_item_t* current=top;
		while (current)
		{
			widget_bounding_box_t bb=TRGui_get_bb(current->widget);
			if (x>bb.x && x<bb.x+bb.width &&
				y>bb.y && y<bb.y+bb.height)
			{
				active_item=current;
				break;
			}
			current=current->next;
		}
		if (!current) //end of the loop was reached
		{
			active_item=NULL;
		}

	}
	else if (active_item)
	{
		widget_bounding_box_t bb=TRGui_get_bb(active_item->widget);
		if (x>bb.x && x<bb.x+bb.width &&
			y>bb.y && y<bb.y+bb.height)
		{
			switch (active_item->widget->type)
			{
			case BUTTON:
				if (active_item->widget->callback1)
				{
					active_item->widget->callback1(button, x, y, bb);
				}
				break;
			case SLIDER:
				if (button==1) //left mouse button
				{
					cb=active_item->widget->callback1; //up callback
				}
				else if (button==3) //right mouse button
				{
					cb=active_item->widget->callback2; //down callback
				}
				if (cb)
				{
					cb(button, x, y, bb);
				}
				break;
			}
		}
		active_item=NULL;
	}
}

void gui_draw()
{
	widget_list_item_t* current=top;
	while (current)
	{
		TRGui_draw_text(current->widget->text, active_item==current, current->widget->layout_info);
		
		current=current->next;
	}
}

void gui_add_widget(widget_t* widget, coord_t* coord)
{
	//current functionality appends item to the end of the linked list
	widget_list_item_t* item;
	widget_list_item_t* current=top;

	int last_line=INT_MIN;
	int next_line;

	if (current)
	{
		widget_list_item_t* last;
		while (current)
		{
			if (!coord && //if appending
				current->widget->layout_info.y_coord_type == LINE_COORD && //and this widget's y coord is in lines
				last_line < current->widget->layout_info.y) //and it's line coord is bigger than the biggest one so far
			{
				last_line=current->widget->layout_info.y; //update last_line
				next_line=last_line+1; //and update next_line
			}
			last=current;
			current=current->next;
		}
		current=last;

		item=(widget_list_item_t*)malloc(sizeof(widget_list_item_t));
		current->next=item;
		item->prev=current;
		item->next=0;
		item->widget=widget;
	}
	else
	{
		//the list is empty
		if (!coord)
		{
			next_line=0;
		}
		top=current=(widget_list_item_t*)malloc(sizeof(widget_list_item_t));
		current->prev=0;
		current->next=0;
		current->widget=widget;
	}
	
	if (!coord)
	{
		widget->layout_info.x=0;
		widget->layout_info.x_coord_type=NORMALIZED_COORD;
		widget->layout_info.x_just=CENTER_JUST;
		widget->layout_info.y=next_line;
		widget->layout_info.y_coord_type=LINE_COORD;
		widget->layout_info.y_just=CENTER_JUST;
	}
}

void destroy_widget(widget_t* widget)
{
	free(widget->text);
	free(widget);
}

void reset_gui()
{
	widget_list_item_t* current=top;
	while (current && current->widget)
	{
		destroy_widget(current->widget);
		current=current->next;
		free(current);
	}
	top=0;
}

void setup_gui()
{
	reset_gui();
}