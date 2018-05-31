/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_load_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 20:42:26 by otimofie          #+#    #+#             */
/*   Updated: 2018/05/30 20:42:27 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		cw_champ_quantity(t_champ *champ) // o.k.
{
	int i;

	i = 0;
	while (champ)
	{
		i++;
		champ = champ->next;
	}
	return (i);
}

void	cw_fill_map_with_bots(unsigned char *dst, int *stack_color, t_champ *champ) // remaster for processes;
{
	int				map_distance;
	unsigned int	i;
	unsigned int	j;
	int				color;

	map_distance = MEM_SIZE / cw_champ_quantity(champ);
	i = 0;
	color = 1;
	while (champ)
	{
		j = 0;
		while (j < champ->head.prog_size)
		{
			dst[i] = champ->code[j];
			stack_color[i] = color;
			i++;
			j++;
		}
		i += map_distance - j;
		color++;
		champ = champ->next;
	}
}

void	cw_init_map(unsigned char *stack, int *stack_color) // o.k.
{
	unsigned int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		stack[i] = '0';
		stack_color[i] = 0;
		i++;
	}
}

void	cw_print_color(unsigned char data, int color_type) // o.k.
{
	if (color_type == 1)
		ft_printf("%~.2x", F_GREEN, data);
	else if (color_type == 2)
		ft_printf("%~.2x", F_RED, data);
	else if (color_type == 3)
		ft_printf("%~.2x", F_BLUE, data);
	else if (color_type == 4)
		ft_printf("%~.2x", F_CYAN, data);
}

void	cw_display_map(unsigned char *map, int *color) // o.k.
{
	unsigned int i;
	unsigned int spaces;
	unsigned int lines;

	i = 0;
	spaces = 1;
	lines = 0;
	while (i < MEM_SIZE)
	{
		if (map[i] != '0')
			cw_print_color(map[i], color[i]);
		else
			ft_printf("%~.2d", F_WHITE, 0);
		ft_printf(" ");
		if (lines == NEWLINE_QUANTITY)
		{
			ft_printf("\n");
			lines = -1;
		}
		lines++;
		spaces++;
		i++;
	}
}

void	cw_load_map(void)
{
	cw_init_map(g_cw->map.stack, g_cw->map.stack_color);
	cw_fill_map_with_bots(g_cw->map.stack, g_cw->map.stack_color, g_cw->pd.champs);
	cw_display_map(g_cw->map.stack, g_cw->map.stack_color);
}
