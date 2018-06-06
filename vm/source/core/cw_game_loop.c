/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_game_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 16:28:33 by prippa            #+#    #+#             */
/*   Updated: 2018/06/06 16:49:43 by otimofie         ###   ########.fr       */
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
	
	// ft_printf("before while -> %d\n",g_cw->i);
	
	// while (g_cw->i < MEM_SIZE) // add the action when the var is 4096;
	// {
	// 	// ft_printf("in while i -> %d\n",g_cw->i);
		
	// 	// ft_bzero(&cmd, sizeof(t_command));
	// 	if ((cw_get_command(&cmd, g_cw->i, g_cw->map.stack)))
	// 	{
	// 		// ft_printf("after codage i -> %d\n", g_cw->i);
	// 		g_cw->i++;
	// 		// to the next position after the cmp function;
	// 		continue;
	// 	}
		cw_get_command(&cmd, &g_cw->i, g_cw->map.stack); // TODO do not move the map with i;

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

//     cw_add(&cmd, &g_cw->map, g_cw->proc_start); // o.k.
//     cw_sub(&cmd, &g_cw->map, g_cw->proc_start); // o.k.
//     cw_binary_and(&cmd, &g_cw->map, g_cw->proc_start); // o.k
//     cw_binary_or(&cmd, &g_cw->map,  g_cw->proc_start); // o.k.
//     cw_binary_xor(&cmd, &g_cw->map, g_cw->proc_start); // o.k.
//     cw_sti(&cmd, &g_cw->map, g_cw->proc_start); // o.k.
		// cw_ld(&cmd, &g_cw->map, g_cw->proc_start);
		// cw_lld(&cmd, &g_cw->map, g_cw->proc_start);
//		cw_ldi(&cmd, &g_cw->map, g_cw->proc_start); o.k.
//		cw_live(&cmd, &g_cw->map, g_cw->proc_start);
        cw_zjmp(&cmd, &g_cw->map, g_cw->proc_start);



    tmp++;
	// }
}
