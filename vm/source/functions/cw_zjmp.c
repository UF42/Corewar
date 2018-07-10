/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 16:17:53 by otimofie          #+#    #+#             */
/*   Updated: 2018/06/06 17:23:47 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			cw_zjmp(t_processes *proc)
{
	int av;

	av = cw_get_dec_from_the_point(proc->pc + 1, g_cw.op[proc->cmd - 1].label);
	if (proc->carry)
		cw_move_pc(proc, IDX_X(av));
	else
		cw_move_pc_without_codage(proc);
}