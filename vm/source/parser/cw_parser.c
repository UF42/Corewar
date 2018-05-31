/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 13:55:45 by prippa            #+#    #+#             */
/*   Updated: 2018/05/26 13:55:50 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	cw_parse_file(t_champ *champ)
{
	cw_check_magic(champ);
	cw_get_prog_name(champ);
	cw_get_prog_size(champ);
	cw_get_comment(champ);
	cw_get_prog_code(champ);
}

void		cw_parser(void)
{
	t_champ *champs;

	champs = g_cw->pd.champs;
	while (champs)
	{
		cw_parse_file(champs);
		champs = champs->next;
	}
}