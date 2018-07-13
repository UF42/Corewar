#include "visualizer.h"

static inline bool	is_mouse_event_happened(int type)
{
	return (type == SDL_MOUSEMOTION ||
			type == SDL_MOUSEBUTTONDOWN ||
			type == SDL_MOUSEBUTTONUP);
}

static inline bool	is_mouse_outside_button(int x, int y,
											SDL_Point position, t_arena *arena)
{
	return (x < position.x ||
			x > position.x + BUTTON_WIDTH ||
			y < position.y ||
			y > position.y + BUTTON_HEIGHT);
}

void				handle_button_event(SDL_Event *e,
										t_button *btn,
										t_arena *arena,
										t_startmenu id)
{
	int				x;
	int				y;

	if (is_mouse_event_happened(e->type))
	{
		SDL_GetMouseState(&x, &y);
		if (is_mouse_outside_button(x, y, btn->position, arena))
			btn->current_sprite = BUTTON_MOUSE_OUT;
		else if (e->type == SDL_MOUSEMOTION)
		{
			if (btn->current_sprite != BUTTON_MOUSE_OVER_MOTION)
				Mix_PlayChannel(-1, arena->btn_move, 0);
			btn->current_sprite = BUTTON_MOUSE_OVER_MOTION;
		}
		else if (e->type == SDL_MOUSEBUTTONDOWN)
		{
			Mix_PlayChannel(-1, arena->btn_press, 0);
			btn->current_sprite = BUTTON_MOUSE_DOWN;
			btn->action(arena);
		}
		else if (e->type == SDL_MOUSEBUTTONUP)
			btn->current_sprite = BUTTON_MOUSE_UP;
	}
}
