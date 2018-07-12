/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 17:49:47 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/22 17:49:49 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static inline void	dequeue_events(t_arena *arena)
{
	while (SDL_PollEvent(&(arena->e)))
	{
		if (arena->e.type == SDL_QUIT)
			exit_event(arena);
		else if (arena->e.type == SDL_KEYDOWN)
			key_event(arena, arena->e.key.keysym.sym);
		else if (arena->e.type == SDL_MOUSEWHEEL)
			wheel_event(arena, arena->e.wheel.y);
		for (int i = 0; i < BUTTON_TOTAL; i++)
			handle_button_event(&(arena->e), arena->start_btns[i], arena, i);
		for (int i = 0; i < MOVE_BUTTON_TOTAL; i++)
			handle_movebutton_event(&(arena->e), arena->move_btns[i], arena, i);
		for (int i = 0; i < TOTAL_CHECKBOXES; i++)
			handle_checkbox_event(&(arena->e), arena->checkboxes[i], arena, i);
	}
	for (int i = 0; i < MOVE_BUTTON_TOTAL; i++)
		handle_movebutton_event(NULL, arena->move_btns[i], arena, i);
}

static inline void	handle_arena_rendering(t_arena *arena, clock_t diff)
{
	static int tacts_before_update;

	if (arena->pause == false)
	{
		tacts_before_update += diff;
		if (tacts_before_update >= 100000)
		{
			for (int i = 0; i < arena->cycles_per_tact; ++i)
				cw_game_loop();
			cw_vis_update_map();
			tacts_before_update = 0;
		}
	}
}

static inline void	handle_fps(t_arena *arena, clock_t diff)
{
	static int tacts_per_second = 0;

	tacts_per_second -= diff;
	arena->fps++;
	if (tacts_per_second <= 0)
	{
		tacts_per_second = 1000000;
		arena->old_fps = arena->fps;
		arena->fps = 0;
	}
}

void				events_handler(t_arena *arena)
{
	clock_t			diff;

	Mix_PlayMusic(arena->theme, -1);
	arena->pause = true;
	cw_vis_update_map();
	while (!arena->quit)
	{
		diff = clock();
		clear_renderer(arena->renderer);
		dequeue_events(arena);
		draw_background(arena);
		draw_infopanel(arena);
		draw_button_panel(arena);
		draw_controls(arena);
		draw_statuses(arena);
		draw_framerate(arena);
		diff = clock() - diff;
		handle_fps(arena, diff);
		handle_arena_rendering(arena, diff);
		draw_arena(arena);
		SDL_RenderPresent(arena->renderer);
	}
}
