/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:06:25 by vgladush          #+#    #+#             */
/*   Updated: 2018/05/26 23:32:13 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	crt_nm_cmt(t_asm *am, char *s, int i)
{
	int		j;

	j = 0;
	am->x++;
	if (i == 1)
	{
		if (am->nmcm == 1 || am->nmcm == 3)
			errors_man(am, s, 1);
		while (s[am->x] != '\"')
			am->hd.prog_name[j++] = s[am->x++];
		am->nmcm += 1;
	}
	else
	{
		if (am->nmcm == 2 || am->nmcm == 3)
			errors_man(am, s, 2);
		while (s[am->x] != '\"')
			am->hd.comment[j++] = s[am->x++];
		am->nmcm += 2;
	}
}

static int	ch_comment(char *s, t_asm *am, char *cmt, int i)
{
	while (*cmt)
		if (*cmt++ != s[i++])
			return (0);
	am->x = i;
	while (s[am->x] == ' ' || s[am->x] == '\t')
		am->x++;
	if (!s[am->x] || s[am->x] == COMMENT_CHAR || s[am->x] == ';')
		errors_man(am, s, 3);
	if (s[am->x] != '\"')
		errors_man(am, s, 4);
	i = am->x + 1;
	while (s[i] && s[i] != '\"')
		i++;
	if (!s[i++])
		errors_man(am, s, 5);
	if (i - am->x - 2 > COMMENT_LENGTH)
		errors_man(am, s, 7);
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i] != COMMENT_CHAR && s[i] != ';' && s[i] && (am->x = i))
		errors_man(am, s, 3);
	crt_nm_cmt(am, s, 2);
	return (1);
}

static int	ch_name(char *s, t_asm *am, char *nm, int i)
{
	while (*nm)
		if (*nm++ != s[i++])
			return (0);
	am->x = i;
	while (s[am->x] == ' ' || s[am->x] == '\t')
		am->x++;
	if (!s[am->x] || s[am->x] == COMMENT_CHAR || s[am->x] == ';')
		errors_man(am, s, 3);
	if (s[am->x] != '\"')
		errors_man(am, s, 4);
	i = am->x + 1;
	while (s[i] && s[i] != '\"')
		i++;
	if (!s[i++])
		errors_man(am, s, 5);
	if (i - am->x - 2 > PROG_NAME_LENGTH)
		errors_man(am, s, 6);
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i] && s[i] != COMMENT_CHAR && s[i] != ';' && (am->x = i + 1))
		errors_man(am, s, 3);
	crt_nm_cmt(am, s, 1);
	return (1);
}

static void	valid_bit(int fd, t_asm *am, char *s)
{
	while (get_next_line(fd, &s))
	{
		++am->y;
		am->x = 0;
		while (s[am->x] && (s[am->x] == ' ' || s[am->x] == '\t'))
			am->x++;
		if (!s[am->x] || s[am->x] == COMMENT_CHAR || s[am->x] == ';')
			am->x = ft_strlen(s) + 1;
		else if (s[am->x] == '.')
		{
			if (!ch_name(s, am, NAME_CMD_STRING, am->x) &&
				!ch_comment(s, am, COMMENT_CMD_STRING, am->x))
				errors_man(am, s, 0);
		}
		else
			check_form(s, am, am->x, 0);
		free(s);
	}
	if (!am->lb)
		errors_man(am, 0, 5);
	ch_to_coord(am);
}

int		ft_pow(int nb, int pow)
{
	if (pow == 0)
		return (1);
	else
		return (nb * ft_pow(nb, pow - 1));
}

char	*ft_itoa_base(int value, int base)
{
	int		i;
	char	*nbr;
	int		neg;

	i = 1;
	neg = 0;
	if (value < 0)
	{
		if (base == 10)
			neg = 1;
		value *= -1;
	}
	while (ft_pow(base, i) - 1 < value)
		i++;
	nbr = (char*)malloc(sizeof(nbr) * i);
	nbr[i + neg] = '\0';
	while (i-- > 0)
	{
		nbr[i + neg] = (value % base) + (value % base > 9 ? 'A' - 10 : '0');
		value = value / base;
	}
	if (neg)
		nbr[0] = '-';
	return (nbr);
}

int			binary_add(int var_x, int var_y)
{
	char *x;
	char *y;
	char x_stack[33];
	char y_stack[33];


	x = ft_itoa_base(var_x, 2);
	ft_printf("x -> %s\n", x);
	y = ft_itoa_base(var_y, 2);
	ft_printf("y -> %s\n", y);

	ft_bzero(x_stack, 32);
	ft_bzero(y_stack, 32);

	x_stack[32] = '\0';
	y_stack[32] = '\0';

	ft_strcpy(x_stack, x);
	ft_strcpy(y_stack, y);


	ft_printf("x_stack -> %s\n", x_stack);
	ft_printf("y_stack -> %s\n", y_stack);


	return (0);
}

int			main(int ac, char **av)
{
	int		op;
	char	*line;
	t_asm	am;

	if (ac < 2)
		exit(ft_printf("need flags\n"));
	line = 0;
	op = open(av[ac - 1], O_RDONLY);
	if (read(op, 0, 0) < 0)
		exit(ft_printf("Can't read source %s\n", av[ac - 1]));
	am.hd.magic = COREWAR_EXEC_MAGIC;
	ft_bzero(am.hd.prog_name, PROG_NAME_LENGTH + 1);
	am.hd.prog_size = 0;
	ft_bzero(am.hd.comment, COMMENT_LENGTH + 1);
	am.lb = 0;
	am.nmcm = 0;
	am.x = 0;
	am.y = 0;
	valid_bit(op, &am, line);
	initial(av[ac - 1], &am);
	all_clear(&am, 0);
	binary_add(10, 7);
	return (0);
}
