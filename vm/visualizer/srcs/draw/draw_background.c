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
	SDL_SetRenderDrawColor(arena->renderer, 0, 0, 0, 0);
	SDL_RenderFillRect(arena->renderer, &clip);
}