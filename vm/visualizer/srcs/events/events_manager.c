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
		for (int i = 0; i < TOTAL_START_BUTTONS; i++)
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
	static int		tacts_before_update;
	int				i;
	t_champ			*champion;
	
	if (arena->pause == false)
	{
		tacts_before_update += diff;
		if (tacts_before_update >= arena->tact_duration && g_cw.game_over)
		{
			i = -1;
			while (++i < arena->cycles_per_tact)
			{
				if (!cw_visu_game_loop())
				{
					g_cw.game_over = false;
					champion = t_champ_find(g_cw.last_reported_to_be_alive, g_cw.pd.champs);
					char buf[2];
					buf[0] = champion->champ_number * (-1) + '0';
					buf[1] = 0; 
					char *hail = ft_strjoin("Contestant ", buf);
					hail = ft_strjoin(hail, " won!");
					SDL_Color c;
					if (champion->color == 1)
						c = LIGHT_GREEN;
					else if (champion->color == 2)
						c = LIGHT_BLUE;
					else if (champion->color == 3)
						c = LIGHT_RED;
					else
						c = CYAN_COLOR;
					arena->hail = load_from_rendered_text(get_text_info(WESTERN_SWING, 1200, hail, c), arena->renderer);
					free(hail);
					t_processes_free(&g_cw.proc_start, &g_cw.proc_end);
					cw_vis_update_map();
					break ;
				}
				cw_vis_update_map();
			}
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

static inline void	update_renderer(t_arena *arena)
{
	SDL_RenderPresent(arena->renderer);
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
		clear_renderer(arena);
		dequeue_events(arena);
		draw_arena(arena);
		if (g_cw.game_over == false)
			render(get_render_position(0, (SDL_Point){.x = BUTTON_WIDTH}, (SDL_Point){0}, (SDL_Point){arena->viewport.w - (BUTTON_WIDTH << 1), SCREEN_WIDTH >> 2}), arena->hail, arena->renderer, SDL_FLIP_NONE);
		draw_infopanel(arena);
		draw_button_panel(arena);
		draw_controls(arena);
		draw_statuses(arena);
		draw_framerate(arena);
		handle_arena_rendering(arena, clock() - diff);
		handle_fps(arena, clock() - diff);
		update_renderer(arena);
	}
}
