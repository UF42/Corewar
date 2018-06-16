#include "corewar.h"

unsigned int	t_champ_get_lives_number(t_champ *champs)
{
	unsigned int count;

	count = 0;
	while (champs)
	{
		count += champs->lives_number;
		champs = champs->next;
	}
	return (count);
}

t_champ			*t_champ_find(int champ_number, t_champ *list)
{
	while (list)
	{
		if (list->champ_number == champ_number)
			return (list);
		list = list->next;
	}
	return (NULL);
}

void		cw_print_players(t_champ *champs)
{
	ft_putstr("Introducing contestants...\n");
	while (champs)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			champs->real_champ_number, champs->head.prog_size,
			champs->head.prog_name, champs->head.comment);
		champs = champs->next;
	}
}

void		cw_print_winer(t_champ *champs)
{
	t_champ	*winer;

	winer = champs;
	while (champs)
	{
		if (winer->last_live < champs->last_live)
			winer = champs;
		champs = champs->next;
	}
	ft_printf("Contestant %d, \"%s\", has won !\n",
		winer->real_champ_number, winer->head.prog_name);
}

void		t_champ_zero_lives_number(t_champ *champs)
{
	while (champs)
	{
		champs->lives_number = 0;
		champs = champs->next;
	}
}