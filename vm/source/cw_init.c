/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 13:56:25 by prippa            #+#    #+#             */
/*   Updated: 2018/06/07 15:46:18 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

struct s_corewar g_cw;

static void cw_get_op(void)
{
	const t_op op_tab[] =
	{
		{&cw_live, 10, 4},
		{&cw_ld, 5, 4},
		{&cw_st, 5, 4},
		{&cw_add, 10, 4},
		{&cw_sub, 10, 4},
		{&cw_binary_and, 6, 4},
		{&cw_binary_or, 6, 4},
		{&cw_binary_xor, 6, 4},
		{&cw_zjmp, 20, 2},
		{&cw_ldi, 25, 2},
		{&cw_sti, 25, 2},
		{&cw_fork, 800, 2},
		{&cw_lld, 10, 4},
		{&cw_lldi, 50, 2},
		{&cw_lfork, 1000, 2},
		{&cw_aff, 2, 4}
	};
	g_cw.op = op_tab;
}

static void	cw_parse_data_init(t_parse_data *pd)
{
	pd->champs = NULL;
	pd->tmp = 0;
	pd->champs_count = 0;
	pd->dump_stop = 0;
	ft_bzero(pd->flags, CW_F_SIZE);
	ft_bzero(pd->flag_champ_number, MAX_PLAYERS);
}

void		cw_init(void)
{
	cw_parse_data_init(&g_cw.pd);
	ft_bzero(g_cw.map, MEM_SIZE);
	ft_bzero(g_cw.color_map, MEM_SIZE);
	ft_bzero(g_cw.color_map_pc, MEM_SIZE);
	ft_bzero(g_cw.color_map_bold, MEM_SIZE);
	ft_bzero(g_cw.color_map_live, MEM_SIZE);
	ft_bzero(g_cw.color_live_cycle_buf, MEM_SIZE);
	cw_get_op();
	g_cw.proc_start = NULL;
	g_cw.proc_end = NULL;
	g_cw.cycle = 0;
	g_cw.cycle_to_die = CYCLE_TO_DIE;
	g_cw.cycle_to_die_check = CYCLE_TO_DIE;
	g_cw.max_checks_check = MAX_CHECKS;
	g_cw.proc_counter = 0;
	g_cw.id_counter = 1;
	g_cw.last_reported_to_be_alive = -1;
}
