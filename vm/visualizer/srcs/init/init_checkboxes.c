/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_checkboxes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 15:48:11 by vkovsh            #+#    #+#             */
/*   Updated: 2018/07/09 15:48:13 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

bool			init_checkboxes(t_arena *arena)
{
	int			wd;
	
	wd = SCREEN_WIDTH - BUTTON_WIDTH - (SCREEN_WIDTH >> 6);
	bzero(arena->full_sprites, sizeof(arena->full_sprites));
	if (!(arena->full_sprites[CHECK_MOUSE_OUT] =
			load_from_file(CHECK_IMG, arena->renderer, WHITE_COLOR)) ||
		!(arena->full_sprites[CHECK_MOUSE_IN] =
			load_from_file(CHECK_IMG, arena->renderer, WHITE_COLOR)) ||
		!(arena->full_sprites[CROSS_MOUSE_OUT] =
			load_from_file(CROSS_IMG, arena->renderer, WHITE_COLOR)) ||
		!(arena->full_sprites[CROSS_MOUSE_IN] =
			load_from_file(CROSS_IMG, arena->renderer, WHITE_COLOR)))
		return (false);
	if (!(arena->full_btn = create_checkbox((SDL_Point){.x = 10 * BUTTON_WIDTH, .y = SCREEN_HEIGHT - CHECKBOX_HEIGHT},
									"FULLSCREEN",
									arena)))
		return (false);
	set_color(GREEN_COLOR, arena->full_sprites[CHECK_MOUSE_IN]);
	set_color(GREEN_COLOR, arena->full_sprites[CROSS_MOUSE_IN]);
	return (true);
}