/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 13:12:48 by vkovsh            #+#    #+#             */
/*   Updated: 2018/07/03 13:12:49 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"


void	draw_background(t_arena *arena)
{
	SDL_Rect clip = get_rectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	t_rposition pos = get_render_position(0, NULL, NULL, &clip);
	//render_part((SDL_Rect){.w = 100, .h = 100}, (SDL_Rect){.w = 100, .h = 100}, (SDL_Point){}, arena->background->texture, arena->renderer);
	render(&pos, arena->background, arena->renderer, SDL_FLIP_NONE);
}
