/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:50:31 by otimofie          #+#    #+#             */
/*   Updated: 2018/05/21 14:50:33 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ft_printf.h"
#include <fcntl.h>

typedef struct		s_toto
{
	unsigned int	x;
	char			str[5];
}					t_toto;

int		ft_string_size(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	return (i);
}

void	ft_write_hex(char *to, char *what)
{
	int i;
	int j;

	if (ft_strlen(what) == 8)
		i = 0;
	else
		i = 8 - ft_strlen(what);
	j = ft_strlen(what) - 1;
	while (to[i] != '\0')
		to[i++] = what[j--];
}

void	init(char *str)
{
	int a;

	a = 0;
	while (a < 8)
		str[a++] = '0';
}

void	ft_reverse(char *str)
{
	char buf[3];

	ft_bzero(buf, 3);
	ft_strncpy(buf, &str[0], 2);
	ft_strncpy(&str[0], &str[6], 2);
	ft_strncpy(&str[6], buf, 2);
	ft_strncpy(buf, &str[2], 2);
	ft_strncpy(&str[2], &str[4], 2);
	ft_strncpy(&str[4], buf, 2);
}

char	*dec_to_hexa(unsigned int n)
{
	int		i;
	int		temp;
	char	hexadecimal[100];
	char	*buf;
	size_t	a;

	ft_bzero(hexadecimal, 100);
	i = 0;
	a = 0;
	while (n)
	{
		temp = n % 16;
		if (temp < 10)
			hexadecimal[i++] = temp + 48;
		else
			hexadecimal[i++] = temp + 55;
		n = n / 16;
	}
	buf = ft_strnew(8);
	init(buf);
	ft_write_hex(buf, hexadecimal);
	ft_reverse(buf);
	return (buf);
}

int		hexadecimal_to_decimal(char *hexval)
{
	int len;
	int base;
	int dec_val;
	int i;
	char *str;

	len = 8;
	base = 1;
	dec_val = 0;
	i = len - 1;
	str = hexval;
	while (i >= 0)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			dec_val += (str[i--] - 48) * base;
			base = base * 16;
		}
		else if (str[i] >= 'A' && str[i] <= 'F')
		{
			dec_val += (str[i--] - 55) * base;
			base = base * 16;
		}
	}
	free(str);
	return (dec_val);
}

void	write_to_struct(char *file_name_to_open, t_toto *sample)
{
	int		len;
	int		fd;
	char	*tmp;
	char	*res;

	len = ft_string_size(file_name_to_open);
	tmp = ft_strnew(len);
	ft_strncpy(tmp, file_name_to_open, len);
	res = ft_strjoin(tmp, ".cor");
	free(tmp);
	fd = open(res, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	sample->x = hexadecimal_to_decimal(dec_to_hexa(sample->x));
	write(fd, sample, sizeof(sample->str) + sizeof(sample->x));
	close(fd);
	free(res);
}

int		main(int argc, char **argv)
{
	t_toto	sample;

	(void)argc;
	ft_bzero(sample.str, sizeof(sample.str));
	ft_strcpy(sample.str, "abcde");
	sample.x = 429496729503;
	write_to_struct(argv[1], &sample);
	system("leaks -q asm");
}
