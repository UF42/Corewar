/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:44:52 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/22 15:44:55 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H
# include "button.h"
# include "events.h"
# include "draw.h"
# include "loader.h"
# include "ltexture.h"
# include "fonts.h"
# include "init.h"
# define ARENA_TILE_WIDTH ((SCREEN_WIDTH - BUTTON_WIDTH - 100) >> 6)
# define ARENA_TILE_HEIGHT (SCREEN_HEIGHT >> 6)
# define ARENA_WIDTH 64
# define ARENA_HEIGHT 64

extern t_ltexture	*g_tile_block;
extern t_ltexture	*g_text_block;

int			visualizer_main(void);
SDL_Rect	get_rectangle(int x, int y, int w, int h);
void		set_viewport(SDL_Renderer *renderer, SDL_Rect *viewport);
bool		init(t_arena *arena);
void		clear_renderer(SDL_Renderer *renderer);
int			exit_dialog(t_arena *arena);
bool		init_start_menu(SDL_Renderer *renderer);
void		create_figures(t_arena *arena);
void		set_random(t_arena *arena);
void		force_error(const char *error);
void		draw_arena_split(t_arena *arena);
#endif