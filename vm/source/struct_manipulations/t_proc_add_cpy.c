#include "corewar.h"

static void	t_processes_add_to_head(t_processes **proc_start,
							t_processes **proc_end, t_processes *new_obj)
{
	new_obj->next = *proc_start;
	new_obj->prev = NULL;
	if (*proc_start)
		(*proc_start)->prev = new_obj;
	else
		*proc_end = new_obj;
	*proc_start = new_obj;
}

// TODO change init stuff
void		t_processe_add(t_processes **proc_start,
							t_processes **proc_end)
{
	t_processes	*new_obj;

	g_cw->proc_counter++;
	if (!(new_obj = (t_processes *)malloc(sizeof(t_processes))))
		cw_perror_exit(ERR_MALLOC_MESSAGE, MALLOC);
	new_obj->id = g_cw->id_counter++;
	new_obj->carry = 0;
	new_obj->color = 0;
	new_obj->process_PC = 0;
	new_obj->live_status = ALIVE;
	new_obj->has_been_activated = DEAD;
	ft_bzero(new_obj->registers, sizeof(int) * REG_NUMBER);
	new_obj->cycles_till_execution = 1;
	new_obj->status = LOOKING_FOR_THE_COMMAND;
	t_processes_add_to_head(proc_start, proc_end, new_obj);
}

void		t_processes_copy(t_processes **proc_start, t_processes **proc_end,
			/*current_proc don`t need double pointer :)*/t_processes *current_proc, int position)
{

	t_processes	*new_obj;

	// add general quantity of the processes;
	g_cw->proc_counter++;

	// created the memory area for the new node/process;
	if (!(new_obj = (t_processes *)malloc(sizeof(t_processes))))
		cw_perror_exit(ERR_MALLOC_MESSAGE, MALLOC);

	// general variable;
	new_obj->id = g_cw->id_counter++;

	new_obj->carry = current_proc->carry; // copy;
	new_obj->color = current_proc->color; // copy;
	new_obj->process_PC = position; // not a copy;
	new_obj->live_status = current_proc->live_status; // copy;
	new_obj->has_been_activated = current_proc->has_been_activated; // copy;
	new_obj->cycles_till_execution = current_proc->cycles_till_execution; // copy;
	new_obj->status = current_proc->status; // copy;

	ft_bzero(new_obj->registers, sizeof(int) * REG_NUMBER);

	ft_memcpy(new_obj->registers, current_proc->registers, sizeof(int) * 16); // ---> !!!!! sizeof(int) not just 16 !!!!! <--- // copy;

	// add to the head;
	t_processes_add_to_head(proc_start, proc_end, new_obj);


}
