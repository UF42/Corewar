#include "corewar.h"

void	t_champ_free(t_champ **champs)
{
	while (*champs)
	{
		free(*champs);
		*champs = (*champs)->next;
	}
}

void	t_champ_add(t_champ **champs)
{
	t_champ *new_obj;

	if(!(new_obj = (t_champ *)malloc(sizeof(t_champ))))
		cw_perror_exit("ERROR", MALLOC);
	new_obj->fd = -1;
	ft_bzero(new_obj->file_name, FILE_NAME_MAX + 1);
	new_obj->header.magic = 0;
	ft_bzero(new_obj->header.prog_name, PROG_NAME_LENGTH + 1);
	new_obj->header.prog_size = 0;
	ft_bzero(new_obj->header.comment, COMMENT_LENGTH + 1);
	new_obj->next = *champs;
	*champs = new_obj;
}
