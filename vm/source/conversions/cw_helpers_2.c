#include "corewar.h"

int		cw_is_valid_reg(t_command *cmd)
{
	if ((cmd->arg1.tp == REG && IS_INVALID_REG(cmd->arg1.av))
		|| (cmd->arg2.tp == REG && IS_INVALID_REG(cmd->arg2.av))
		|| (cmd->arg3.tp == REG && IS_INVALID_REG(cmd->arg3.av)))
		return (0);
	return (1);
}
