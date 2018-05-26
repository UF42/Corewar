/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:48:54 by prippa            #+#    #+#             */
/*   Updated: 2018/04/26 18:48:58 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

/*
** Parsing champions part (data)
*/

typedef struct		s_champ
{
	t_header		head;
	char			file_name[FILE_NAME_MAX + 1];
	int				fd;
	char			*code;
	struct s_champ	*next;
}					t_champ;

typedef struct		s_parse_data
{
	t_champ			*champs;
	long long int	tmp;
}					t_parse_data;

/*
** End
*/

typedef struct		s_corewar
{
	t_parse_data	pd;
}					t_corewar;

#endif
