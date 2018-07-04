/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_processes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:25:50 by prippa            #+#    #+#             */
/*   Updated: 2018/06/05 19:30:23 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_processes	*t_processe_get_by_id(t_processes *proc_start,
								t_processes *proc_end, unsigned int id)
{
	unsigned int i;

	i = 0;
	while (proc_start && proc_end && i <= (g_cw.proc_counter / 2))
	{
		if (proc_start->id == id)
			return (proc_start);
		else if (proc_end->id == id)
			return (proc_end);
		proc_start = proc_start->next;
		proc_end = proc_end->prev;
		i++;
	}
	return (NULL);
}

int			t_processe_free_by_obj(t_processes **proc_start,
								t_processes **proc_end, t_processes *obj)
{
	if (!(*proc_start) || !(*proc_end) || !obj)
		return (0);
	if (obj == *proc_start)
	{
		*proc_start = (*proc_start)->next;
		if (*proc_start)
			(*proc_start)->prev = NULL;
		else
			*proc_end = NULL;
	}
	else if (!obj->next)
	{
		obj->prev->next = NULL;
		*proc_end = obj->prev;
	}
	else
	{
		obj->prev->next = obj->next;
		obj->next->prev = obj->prev;
	}
	free(obj);
	g_cw.proc_counter--;
	return (1);
}

int			t_processe_free_by_id(t_processes **proc_start,
								t_processes **proc_end, unsigned int id)
{
	t_processes *tmp;

	if (!(tmp = t_processe_get_by_id(*proc_start, *proc_end, id)))
		return (0);
	if (!t_processe_free_by_obj(proc_start, proc_end, tmp))
		return (0);
	return (1);
}
