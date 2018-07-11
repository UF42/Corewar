/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_game_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 16:28:33 by prippa            #+#    #+#             */
/*   Updated: 2018/06/07 15:17:13 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		cw_cycles_new_period(void)
{
	g_cw.max_checks_check--;
	if (t_champ_is_nbr_live(g_cw.pd.champs) || !g_cw.max_checks_check)
	{
		g_cw.cycle_to_die -= CYCLE_DELTA;
		g_cw.max_checks_check = MAX_CHECKS;
	}
	g_cw.cycle_to_die_check = g_cw.cycle_to_die;
	t_champ_zero_lives_number(g_cw.pd.champs);
	t_processe_killer(g_cw.pd.champs);
}

static void		cw_proc_executer(t_processes *proc)
{
	while (proc)
	{
		g_cw.color_map_pc[proc->pc] = 0;
		if (proc->exec_cycles != -1)
		{
			if (!proc->exec_cycles)
			{
				g_cw.op[proc->cmd - 1].func(proc);
				proc->exec_cycles = -1;
			}
			else
				proc->exec_cycles--;
		}
		else
			proc->pc = MEM_X((proc->pc + 1));
		g_cw.color_map_pc[proc->pc] = 1;
		proc = proc->next;
	}
}

void			cw_game_loop(void)
{
	t_champ *champs;

	while (1)
	{//6095
		if (g_cw.cycle >= 5683 && !g_cw.pd.flags[DUMP]) //(3 Gagnants) 8802 is not same with original
		{
			cw_vis_print_map(1); // TRASH
			ft_printf("\n************\nCycle: %u\n************\n", g_cw.cycle);
			ft_printf("cycle to die: %d\n", g_cw.cycle_to_die);
		}
		else
			cw_vis_print_map(0);
		if (g_cw.cycle_to_die <= 0)
			break ;
		t_processes_initer(g_cw.pd.champs);
		champs = g_cw.pd.champs;
		while (champs)
		{
			cw_proc_executer(champs->proc_start);
			champs = champs->next;
		}
		if (g_cw.pd.flags[DUMP] && g_cw.cycle == g_cw.pd.dump_stop)
			cw_print_dump_exit();
		if (!g_cw.cycle_to_die_check)
			cw_cycles_new_period();
		ft_printf("proc count: %u\n", g_cw.proc_counter);
		if (g_cw.proc_counter == 0)
			break ;
		g_cw.cycle++;
		g_cw.cycle_to_die_check--;
	}
}
