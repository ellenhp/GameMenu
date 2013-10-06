#include "gui_input.h"
#include "gui_mgr.h"
#include "gui_abstraction.h"
#include <math.h>

#include "SDL.h"

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
