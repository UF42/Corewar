#include "corewar.h"

int			cw_is_valid_reg(t_command *cmd)
{
	if ((cmd->arg1.tp == REG && IS_INVALID_REG(cmd->arg1.av))
		|| (cmd->arg2.tp == REG && IS_INVALID_REG(cmd->arg2.av))
		|| (cmd->arg3.tp == REG && IS_INVALID_REG(cmd->arg3.av)))
		return (0);
	return (1);
}

int			cw_get_right_arg(t_processes *proc, char tp, int av)
{
	if (tp == REG)
		return (proc->registers[av - 1]);
	return (av);
}

void		cw_move_pc_with_codage(t_command *cmd, t_processes *proc)
{
	proc->pc = MEM_X(
		(proc->pc + cmd->arg1.tp + cmd->arg2.tp + cmd->arg3.tp + 2));
}

void		cw_move_pc_without_codage(t_processes *proc)
{
	proc->pc = MEM_X(
		(proc->pc + g_cw.op[proc->cmd - 1].label + 1));
}

void		cw_move_pc(t_processes *proc, int value)
{
	if ((proc->pc = MEM_X((proc->pc + value))) < 0)
		proc->pc += MEM_SIZE;
}
