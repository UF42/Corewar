/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_game_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 16:28:33 by prippa            #+#    #+#             */
/*   Updated: 2018/05/31 16:28:35 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		cw_game_loop(void)
{
	// while (g_cw->loop)
	// {
		
	// }
	t_command cmd;
	int tmp = 1;

	g_cw->i = 0;
	while (g_cw->i < MEM_SIZE)
	{
		ft_bzero(&cmd, sizeof(t_command));
		if ((cw_get_command(&cmd, &g_cw->i, g_cw->map.stack)))
		{
			g_cw->i++;
			continue;
		}
		ft_printf("command ------------------------ %d\n", tmp);
		ft_printf("cmd - %u\n", cmd.cmd);
		ft_printf("codage - %d\n", cmd.codage);
		ft_printf("arg1.tp - %u\n", cmd.arg1.tp);
		ft_printf("arg1.av - %d\n", cmd.arg1.av);
		ft_printf("arg2.tp - %u\n", cmd.arg2.tp);
		ft_printf("arg2.av - %d\n", cmd.arg2.av);
		ft_printf("arg3.tp - %u\n", cmd.arg3.tp);
		ft_printf("arg3.av - %d\n", cmd.arg3.av);
		ft_printf("-----------------------------------\n");
		tmp++;
	}
}
