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

typedef struct			s_arg
{
	t_arg_type			tp;
	int					av;
}						t_arg;

typedef struct			s_command
{
	char				cmd;
	int					codage;
	t_arg				arg1;
	t_arg				arg2;
	t_arg				arg3;
	struct s_command	*next;
}						t_command;

typedef struct			s_champ
{
	t_header			head;
	char				file_name[FILE_NAME_MAX + 1];
	int					fd;
	unsigned char		code[CHAMP_MAX_SIZE + 1];
	t_command			*cmd;
	struct s_champ		*next;
}						t_champ;

typedef struct			s_parse_data
{
	t_champ				*champs;
	long long int		tmp;
	int					i;
}						t_parse_data;

/*
** End
*/

typedef struct			s_corewar
{
	t_parse_data		pd;
}						t_corewar;

#endif
