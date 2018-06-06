#include "corewar.h"

void			cw_ldi(t_command *cmd, t_stack *map, t_processes *proc)
{
	int arg;

	arg = 0;
	if (cmd->arg1.tp == 2)
		arg = BOBA(cmd->arg1.av) + proc->process_PC;
	else
		arg = BOBA(cmd->arg1.av + cmd->arg2.av) + proc->process_PC;
	proc->registers[cmd->arg3.av - 1] = cw_get_dec_from_the_point(
		map->stack,
		4,
		arg
	);
	proc->process_PC = BIBA(
		proc->process_PC + cmd->arg1.tp + cmd->arg2.tp + cmd->arg3.tp + 2);
}
