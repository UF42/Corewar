/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 13:58:44 by vgladush          #+#    #+#             */
/*   Updated: 2018/04/23 16:31:54 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	all_clear(t_asm *am, char *s)
{
	if (am->name)
		free(am->name);
	if (am->comment)
		free(am->comment);
	if (am->bn)
		free(am->bn);
	free(s);
	return (0);
}

static void	errors_sec(t_asm *am, char *s, int o, int i)
{
	if (o == 4)
	{
		ft_printf("Syntax error at token [TOKEN][%.3d:001] LABEL \"", am->y);
		while (s[i] && s[i] != ' ' && s[i] != '\t')
			write(1, s + i++, 1);
		write(1, "\"\n", 2);
	}
	else if (o == 9)
	{
		ft_printf("Syntax error at token [TOKEN][%.3d:%.3d] INSTRUCTION \"",
			am->y, am->x);
		am->x--;
		while (s[am->x] && s[am->x] != ' ' && s[am->x] != '\t' && s[am->x]
			!= ';' && s[am->x] != '\"')
			write(1, s + am->x++, 1);
		write(1, "\"\n", 2);
	}
}

void		errors_man(t_asm *am, char *s, int o)
{
	if (o == 1)
		ft_printf("Syntax error at token [TOKEN]\
[%.3d:001] COMMAND_NAME \".name\"\n", am->y);
	else if (o == 2)
		ft_printf("Syntax error at token [TOKEN]\
[%.3d:001] COMMAND_COMMENT \".comment\"\n", am->y);
	else if (o == 3)
		ft_printf("Lexical error at [%d:%d]\n", am->y, am->x);
	else if (o == 5)
		ft_printf("Syntax error at token [TOKEN]\
[%.3d:%.3d] ENDLINE\n", am->y, am->x + 1);
	else if (o == 6)
		ft_printf("Syntax error at token [TOKEN]\
[%.3d:%.3d] END \"(null)\"\n", am->y, am->x);
	else if (o == 7)
		ft_printf("Champion name too long (Max length 128)\n");
	else if (o == 8)
		ft_printf("Champion comment too long (Max length 2048)\n");
	else
		errors_sec(am, s, o, 0);
	exit(all_clear(am, s));
}
