#include "gui_input.h"
#include "gui_mgr.h"
#include "gui_abstraction.h"
#include <math.h>

#include "SDL.h"

#define JOYSTICK_TRIGGER 0.5
#define JOYSTICK_RELAX 0.35

int joystick_x_status=0, joystick_y_status=0;

void gui_process_keypress(int key)
{
	input_t input=NONE_INPUT;
	switch (key)
	{
	case SDLK_DOWN:
		input=DOWN_INPUT;
		break;
	case SDLK_UP:
		input=UP_INPUT;
		break;
	case SDLK_RIGHT:
		input=RIGHT_INPUT;
		break;
	case SDLK_LEFT:
		input=LEFT_INPUT;
		break;
	case SDLK_RETURN:
	case SDLK_SPACE:
		input=SELECT_INPUT;
		break;
	}
	gui_process_input(input);
}

void gui_process_button_press(int button)
{
	if (button==0)
	{
		gui_process_input(SELECT_INPUT);
	}
}

void gui_process_axis(double x, double y)
{
	if (joystick_x_status!=0)
	{
		if (fabs(x)<JOYSTICK_RELAX)
		{
			joystick_x_status=0;
		}
	}
	else
	{
		if (x<-JOYSTICK_TRIGGER)
		{
			joystick_x_status=-1;
			gui_process_input(LEFT_INPUT);
		}
		if (x>JOYSTICK_TRIGGER)
		{
			joystick_x_status=1;
			gui_process_input(RIGHT_INPUT);
		}
	}

	if (joystick_y_status!=0)
	{
		if (fabs(y)<JOYSTICK_RELAX)
		{
			joystick_y_status=0;
		}
	}
	else
	{
		if (y<-JOYSTICK_TRIGGER)
		{
			joystick_y_status=-1;
			gui_process_input(UP_INPUT);
		}
		if (y>JOYSTICK_TRIGGER)
		{
			joystick_y_status=1;
			gui_process_input(DOWN_INPUT);
		}
	}
}
