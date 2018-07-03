/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:44:40 by otimofie          #+#    #+#             */
/*   Updated: 2018/06/01 16:44:41 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
// TODO delete all comments
// static t_processes	*cw_process_find(int process_id, t_processes *list)
// {
// 	while (list)
// 	{
// 		if (list->id == process_id)
// 			return (list);
// 		list = list->next;
// 	}
// 	return (NULL);
// }

void			cw_add(t_command *cmd, t_stack *map, t_processes *proc/*, unsigned int process_id*/)
{
	ft_printf("add\n");
	if (proc->process_PC > 4095 || proc->process_PC < 0)
	{
		ft_printf("add\n");
		getchar();
	}

//	t_processes *proc;
	// int	arguments[3];
	//process;
//	proc = t_processe_get_by_id(g_cw->proc_start, g_cw->proc_end, process_id);
//	ft_printf("process_id-> %d\n\n", proc->id);

//	ft_printf("proc->registers[cmd->arg1.av - 1]-> %d\n", proc->registers[cmd->arg1.av - 1]);
//	ft_printf("proc->registers[cmd->arg2.av - 1]-> %d\n", proc->registers[cmd->arg2.av - 1]);
	map->stack_color[proc->process_PC] = proc->color;

	
	proc->registers[cmd->arg3.av - 1] = proc->registers[cmd->arg1.av - 1] + proc->registers[cmd->arg2.av - 1];

//	ft_printf("proc->registers[cmd->arg3.av - 1]-> %d\n", proc->registers[cmd->arg3.av - 1]);

	proc->carry = (proc->registers[cmd->arg3.av - 1] == 0) ? 1 : 0;

	proc->process_PC = MEM_CORRECTION(
		(proc->process_PC + cmd->arg1.tp + cmd->arg2.tp + cmd->arg3.tp + 2));

	ft_printf("process_PC -> %d\n", proc->process_PC);


	if (proc->process_PC > 4095 || proc->process_PC < 0)
	{
		ft_printf("add\n");
			getchar();
	}

	map->stack_color[proc->process_PC] = proc->proc_process_PC_color; // !!!!!!!!!!!!!!!!!!!!
   


	// for testing;
//	 map->stack[proc->process_PC] = 7;
//	 map->stack_color[proc->process_PC] = 5;

//	 ft_printf("process_carry -> %d\n\n", proc->carry);

//	 cw_display_map(g_cw->map.stack, g_cw->map.stack_color);
}
