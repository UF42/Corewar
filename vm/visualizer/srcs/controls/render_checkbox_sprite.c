/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_checkbox_sprite.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 14:17:38 by vkovsh            #+#    #+#             */
/*   Updated: 2018/06/05 14:17:41 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void				render_checkbox_sprite(t_checkbox *cbx, t_arena *arena)
{
	t_rposition		cbx_pos;
	t_rposition		txt_pos;
	SDL_Rect		clip;

	clip = get_rectangle(cbx->position.x,
							cbx->position.y,
							CHECKBOX_WIDTH,
							CHECKBOX_HEIGHT);
	cbx_pos = get_render_position(0, cbx->position, cbx->position,
								(SDL_Point){.x = clip.w, .y = clip.h});
	render(cbx_pos, arena->full_sprites[cbx->current_sprite],
			arena->renderer, SDL_FLIP_NONE);
	if (cbx->checkbox_txt)
	{
		clip.w *= 2;
		txt_pos = get_render_position(0,
						cbx->txt_position,
						cbx->txt_position,
						(SDL_Point){.x = clip.w >> 1, .y = clip.h >> 1});
		render(txt_pos, cbx->checkbox_txt, arena->renderer, SDL_FLIP_NONE);
	}
}
