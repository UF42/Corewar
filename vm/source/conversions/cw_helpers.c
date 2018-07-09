/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:25:00 by prippa            #+#    #+#             */
/*   Updated: 2018/06/06 12:25:01 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static char		*cw_get_string_for_conversion(int nbr)
{
	int i;
	char *str;
	char *check;
	
	i = 0;
	if (!(str = ft_itoa_base(nbr, 2, 87)))
		cw_perror_exit(ERR_MALLOC_MESSAGE, MALLOC);
	if (!(check = ft_strnew(32)))
		cw_perror_exit(ERR_MALLOC_MESSAGE, MALLOC);
	while (i < 32)
	{
		check[i] = '0';
		i++;
	}
	if (nbr < 0)
		ft_strncpy(&check[0], &str[32], ft_strlen(str) - 32);
	else
		ft_strncpy(&check[32 - ft_strlen(str)], &str[0], ft_strlen(str));
	free(str);
	return (check);
}

void			cw_write_bytes_to_buf(unsigned char *buf, int nbr)
{
	char	*check;
	int		i;
	int		k;

	i = 0;
	check = cw_get_string_for_conversion(nbr);
	k = 7;
	while (i < 4)
	{
		buf[i] = ft_bin_to_int(check, k);
		k += 8;
		i++;
	}
	free(check);
}

void			cw_write_to_map(unsigned char *map, t_processes *proc,
					unsigned char *buf, int pc)
{
	int	i;

	i = 0;
	if ((pc = MEM_X(pc)) < 0)
		pc += MEM_SIZE;
	while (i < 4)
	{
		map[pc] = buf[i];
		i++;
		pc = MEM_X((pc + 1));
	}
}

int			cw_get_dec_from_the_point(unsigned char *map, int pc)
{
	unsigned char	buf[4];
	int				res;
	int				i;

	res = 0;
	i = 0;
	if ((pc = MEM_X(pc)) < 0)
		pc += MEM_SIZE;
	while (i < 4)
	{
		if (map[pc] == 48)
			buf[i] = 0;
		else
			buf[i] = map[pc];
		i++;
		pc = MEM_X((pc + 1));
	}
	res = cw_hex_to_dec(buf, 4);
	return (res);
}

int			cw_hex_to_dec(unsigned char *buf, int i)
{
	int res;

	res = 0;
	if (!i)
		return (0);
	if (i == 4)
	{
		res += buf[0] * 16777216;
		res += buf[1] * 65536;
		res += buf[2] * 256;
		res += buf[3];
	}
	else if (i == 2)
	{
		res += buf[0] * 256;
		res += buf[1];
		res = (short)res;
	}
	else
	{
		res += buf[0];
		res = (short)res;
	}
	return (res);
}
