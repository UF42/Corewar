#include "corewar.h"

int		cw_pow(int base, int level)
{
	int	res;

	res = 1;
	if (level == 0)
		return (1);
	while (level)
	{
		res = res * base;
		level--;;
	}
	return (res);
}

int		cw_bin_to_in(char *str, int index)
{
	int decimal;
	int	len;
	int i;

	decimal = 0;
	len = 7;
	i = 0;
	while (len >= 0)
	{
		if (str[index] == '1')
			decimal += cw_pow(2, i);
		i++;
		index--;
		len--;
	}
	return (decimal);
}

char	*cw_get_string_for_conversion(int nbr)
{
	int i;
	char *str;
	char *check;
	
	i = 0;
	str = ft_itoa_base(nbr, 2, 87);
	check = ft_strnew(32);
	while (i < 32)
	{
		check[i] = '0';
		i++;
	}
	if (nbr < 0)
		ft_strncpy(&check[0], &str[32], ft_strlen(str) - 32);
	else
		ft_strncpy(&check[32 - ft_strlen(str)], &str[0], ft_strlen(str));
	free(str);
	return (check);
}

void	cw_write_bytes_to_buf(unsigned char *buf, int nbr)
{
	char *check;
	int i;
	int k;

	i = 0;
	check = cw_get_string_for_conversion(nbr);
	while (i < 4)
	{
		if (i == 0)
		{
			k = 7 ;
			buf[i] = cw_bin_to_in(check, k);
		}
		else if (i >= 0)
		{
			k = k + 8;
			buf[i] = cw_bin_to_in(check, k);
		}
		i++;
	}
	free (check);
}

int		cw_get_dec_from_the_point(unsigned char *str, int quantity, int position)
{
	int res;
	int i;
	int j;

	res = 0;
	i = 0;
	j = position;

	// ft_printf("position -> %d\n", position);
	// ft_printf("mod -> %d\n", 0 %IDX_MOD);

	// int k = 0;
	// while (k < 4096)
	// {
	// 	ft_printf("d->%d\n", str[k]);
	// 	k++;
	// }
	

	while (i < quantity)
	{
		// ft_printf("d->%d\n", str[j] - '0');
		// ft_printf("c->%c\n", str[j]);
		
		res += (str[j] - '0');
		i++;
		j++;
	}
	// ft_printf("res --> %d\n", res);
	return (res);

}

int		cw_arguments_value(t_command *cmd, t_stack *map, t_processes *process) // -1 for registers;
{
	if (cmd->codage == 100) // o.k
		return (((process->process_PC + cmd->arg2.av + process->registers[cmd->arg3.av - 1]) % IDX_MOD));
	else if (cmd->codage == 116) // o.k
	{
		// ft_printf("IND -> %d\n", cmd->arg2.av % IDX_MOD);
		return (process->process_PC + (cw_get_dec_from_the_point(map->stack, 4, cmd->arg2.av % IDX_MOD) + process->registers[cmd->arg3.av - 1]));
	}
	else if (cmd->codage == 84) // o.k.
	{
		// ft_printf("r1 -> %d\n", process->registers[cmd->arg2.av - 1]);
		// ft_printf("r1 -> %d\n", process->registers[cmd->arg3.av - 1]);
		// ft_printf("res -> %d\n", ((process->registers[cmd->arg2.av - 1] + (process->process_PC + 1) + process->registers[cmd->arg3.av - 1]) % IDX_MOD));
		return ((process->process_PC + process->registers[cmd->arg2.av - 1]  /*+ 1*/ + process->registers[cmd->arg3.av - 1]) % IDX_MOD);
	}
	else if (cmd->codage == 104) // o.k
		return ((process->process_PC + cmd->arg2.av + cmd->arg3.av) % IDX_MOD);
	else if (cmd->codage == 120) // o.k.
		return (process->process_PC + (cw_get_dec_from_the_point(map->stack, 4, cmd->arg2.av % IDX_MOD) + cmd->arg3.av));
	else if (cmd->codage == 88) // o.k
		return ((process->process_PC + process->registers[cmd->arg2.av - 1]  /*+ 1*/ + cmd->arg3.av) % IDX_MOD);
	return (0);
}

void	cw_sti(t_command *cmd, t_stack *map, t_processes *process) // do not forget about the search of the right process;
{
	unsigned char buf[4];
	int i;
	int	position;
	// int	arguments[3];
	//process;

	position = 0;
	cw_write_bytes_to_buf(buf, process->registers[0]);

	// ft_printf("2 -> %d\n", cmd->arg2.av);
	// ft_printf("3 -> %d\n", process->registers[cmd->arg3.av]);
	// 
	position += cw_arguments_value(cmd, map, process); // to func;

	// ft_printf("position -> %d\n", position);
	

	// position = 15;

	process->process_PC += (cmd->arg1.tp + cmd->arg2.tp + cmd->arg1.tp); // o.k.

	(cmd->arg2.tp == 2) ? process->process_PC += 2 : 0;
	(cmd->arg2.tp == 1) ? process->process_PC += 2 : 0;
	(cmd->arg2.tp == 2 && cmd->arg3.tp == 2) ? process->process_PC += 1 : 0;
	(cmd->arg2.tp == 4 && cmd->arg3.tp == 2) ? process->process_PC += 1 : 0;

	// ft_printf("process_PC -> %d\n", process->process_PC);

	// move the process_PC by the quantity of bytes; 

	// process id // process parent;
	// get clear with it;
	// it will be found by the color ?;

	// process id in order to find the correct process;

	// ft_printf("%d", ((cmd->arg2.av + process->registers[cmd->arg3.av]) % IDX_MOD));
	// position = 15;

	// i = 0; // argument type variation;
	i = 0;
	if (position < 0)
		position = MEM_SIZE + position;
		// ft_printf("position -> %d\n", position);
	while (i < 4) // 2 || 4; // always take 4 bytes to the map;
	{
		if (position == 4096)
		// ft_printf("position -> %d", position);
		position = 0;
		
		map->stack[position] = buf[i++];
		map->stack_color[position++] = process->color;
	}
	map->stack[process->process_PC] = 7;
	map->stack_color[process->process_PC] = 5;

	// cw_display_map(g_cw->map.stack, g_cw->map.stack_color);

	// ft_printf("%d\n", 15 & IDX_MOD);
}
