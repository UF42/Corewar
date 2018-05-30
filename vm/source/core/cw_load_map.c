#include "corewar.h"

void	init_map(unsigned char *dst, unsigned char *src /*int start*/, unsigned int bot_size) // for the several bots;
{
	unsigned int i;

	i  = 0;
	while (i < MAP_SIZE)
		dst[i++] = '0';
	i = 0;
	while (i < bot_size)
	{
		dst[i] = src[i];
		i++;
	}
}	

void	display_map(unsigned char *map)
{
	unsigned int i;
	unsigned int lines;
	unsigned int spaces;

	i = 0;
	lines = 1;
	spaces = 1;
	while (i < MAP_SIZE)
	{
		if (map[i] != '0')
			ft_printf("%~.2x", F_GREEN, map[i]);
		else
		{
			ft_printf("%~c", F_WHITE, map[i]);
			ft_printf("%~c", F_WHITE, map[i]);
		}
		ft_printf(" ");
		if (lines == NEWLINE_QUANTITY)
		{
			ft_printf("\n");
			lines = 0;
		}
		lines++;
		spaces++;
		i++;
	}
}

void	cw_load_map()
{
	init_map(g_cw->map.stack, g_cw->pd.champs->code, g_cw->pd.champs->head.prog_size);
	display_map(g_cw->map.stack);
}
