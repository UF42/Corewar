#include "corewar.h"

void		t_processe_killer(t_champ *champs)
{
	t_processes	*head;
	t_processes	*tmp;

	while (champs)
	{
		head = champs->proc_start;
		while (head)
		{
			if (head->has_been_activated == LIVE)
				head->has_been_activated = DEAD;
			else
			{
				tmp = head->next;
				t_processe_free_by_obj(&champs->proc_start, &champs->proc_end, head);
				if (!tmp)
					break ;
				head = tmp;
				continue;
			}
			head = head->next;
		}
		champs = champs->next;
	}
}
