/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_display_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 12:09:06 by otimofie          #+#    #+#             */
/*   Updated: 2018/06/01 12:09:07 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	print_color(unsigned char data, int color_type)
{
	if (color_type == 1)
		ft_printf("%~.2x", F_GREEN, data);
	else if (color_type == 2)
		ft_printf("%~.2x", F_RED, data);
	else if (color_type == 3)
		ft_printf("%~.2x", F_BLUE, data);
	else if (color_type == 4)
		ft_printf("%~.2x", F_CYAN, data);
	else if (color_type == 5)
		ft_printf("%~.2x", F_BACK_GREEN_WHITE, data);
	else if (color_type == 6)
		ft_printf("%~.2x", F_BACK_RED_WHITE, data);
	else if (color_type == 7)
		ft_printf("%~.2x", F_BACK_BLUE_WHITE, data);
	else if (color_type == 8)
		ft_printf("%~.2x", F_BACK_CYAN_WHITE, data);
}

// 1+4
// 2+4
// 3+4
// 4+4

void		cw_display_map(unsigned char *map, int *color)
{
	unsigned int i;
	unsigned int spaces;
	unsigned int lines;

	read(1, 0, 1); // this stuff may help with visualization;
	system("clear"); // this stuff may help with visualization;

	i = 0;
	spaces = 1;
	lines = 0;
	while (i < MEM_SIZE)
	{
		if (map[i] != '0')
			print_color(map[i], color[i]);
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
