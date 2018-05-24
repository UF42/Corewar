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

// t_asm *ld;

// ld->hd
// while
//  ?? ld->lb->cmd->cmd
//  ?? ld->lb->cmd->codage
//  ??arg1/...2...3
//  tp == 1 === char ... 2 short 3 int
//  ?? tp (1 2 or 3)ard->av

typedef struct		s_toto
{
	unsigned int	magic;
	char			prog_name[128 + 1];
	unsigned int	prog_size;
	// size of the commands of program itself (not the whole file);
	char			comment[2048 + 1];
}					t_toto;

int		ft_string_size(char *str)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str) - 1;
	while (str[len] && str[len] != '/')
	{
		i++;
		len--;
	}
	// ft_printf("i -> %d", i);
	return (i);
}

// void	ft_write_hex(char *to, char *what)
// {
// 	int i;
// 	int j;

// 	if (ft_strlen(what) == 8)
// 		i = 0;
// 	else
// 		i = 8 - ft_strlen(what);
// 	j = ft_strlen(what) - 1;
// 	while (to[i] != '\0')
// 		to[i++] = what[j--];
// }

void	init(char *str)
{
	int a;

	a = 0;
	while (a < 8)
		str[a++] = '0';
}

// void	ft_reverse(char *str)
// {
// 	char buf[3];

// 	ft_bzero(buf, 3);
// 	ft_strncpy(buf, &str[0], 2);
// 	ft_strncpy(&str[0], &str[6], 2);
// 	ft_strncpy(&str[6], buf, 2);
// 	ft_strncpy(buf, &str[2], 2);
// 	ft_strncpy(&str[2], &str[4], 2);
// 	ft_strncpy(&str[4], buf, 2);
// }

// char	*dec_to_hexa(unsigned int n)
// {
// 	int		i;
// 	int		temp;
// 	char	hexadecimal[100];
// 	char	*buf;
// 	size_t	a;

// 	ft_bzero(hexadecimal, 100);
// 	i = 0;
// 	a = 0;
// 	while (n)
// 	{
// 		temp = n % 16;
// 		if (temp < 10)
// 			hexadecimal[i++] = temp + 48;
// 		else
// 			hexadecimal[i++] = temp + 55;
// 		n = n / 16;
// 	}
// 	buf = ft_strnew(8);
// 	init(buf);
// 	ft_write_hex(buf, hexadecimal);
// 	// ft_printf("buf before reverse -> %s\n", buf);
// 	ft_reverse(buf);
// 	// ft_printf("buf after  reverse -> %s\n", buf);
// 	return (buf);
// }

// unsigned int		hexadecimal_to_decimal(char *hexval)
// {
// 	unsigned int	base;
// 	unsigned int	dec_val;
// 	int				i;
// 	char			*str;

// 	base = 1;
// 	dec_val = 0;
// 	i = 7;
// 	str = hexval;
// 	while (i >= 0)
// 	{
// 		if (str[i] >= '0' && str[i] <= '9')
// 		{
// 			dec_val += (str[i--] - 48) * base;
// 			base = base * 16;
// 		}
// 		else if (str[i] >= 'A' && str[i] <= 'F')
// 		{
// 			dec_val += (str[i--] - 55) * base;
// 			base = base * 16;
// 		}
// 	}
// 	free(str);
// 	return (dec_val);
// }
void	reverse_binary_string(char *str)
{
	ft_printf("initial string -> %s\n", str);

	char buf[9];
	ft_bzero(buf, 9);
	buf[8] = '\0';

	ft_strncpy(buf, &str[0], 8);
	ft_printf("buf1 -> %s\n", buf);

	ft_strncpy(&str[0], &str[24], 8);
	ft_strcpy(&str[24], buf);

	ft_printf("1. swap -> %s\n", str);

	ft_strncpy(buf, &str[8], 8);
	ft_printf("buf2 -> %s\n", buf);

	ft_strncpy(&str[8], &str[16], 8);
	ft_strncpy(&str[16], buf, 8);

	ft_printf("2. swap -> %s\n", str);
}

int		len_to_copy(char *str)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str) - 1;
	while (str[len] && str[len] != '.' && str[len] != '/')
	{
		i++;
		len--;
	}
	// ft_printf("i -> %d\n", i);
	// ft_printf("len -> %d\n", ft_string_size(str));
	if (ft_string_size(str) == i)
		return (0);
	return (i + 1);
}
int bstr_to_dec(char * str)
{
    int val = 0;
     
    while (*str != '\0')
        val = 2 * val + (*str++ - '0');
    return val;
}

char	*ft_to_binary(unsigned int n)
{
	int i = 0;
	int c = 31;
	int k;
	char str[33];
	char *reverse = ft_strnew(32);
	ft_bzero(reverse, 32);

	str[32] = '\0'; 
	while (c >= 0)
	{
		k = n >> c;
		if (k & 1)
			str[i++] = '1';
		else
			str[i++] = '0';
		c--;
	}
	reverse_binary_string(str);
	ft_strcpy(reverse,str);
	ft_printf("reverse->%s\n", reverse);
	return (reverse);
}

void	write_to_struct(char *file_name, t_toto *sample)
{
	int		len;
	int		fd;
	int		copy_start;
	char	*tmp;
	char	*res;
	void	*ar;
	unsigned int 	asd;

	asd = 1792; // inverted value = 1792;

	// asd = hexadecimal_to_decimal(dec_to_hexa(asd));
	// ft_printf("%u\n", asd);
	// short buf = asd;
	ar = &asd;
	// short x = *(short *)ar;
	// ft_printf("%u\n",x);
	// int -> short | char'
	len = ft_string_size(file_name);
	copy_start = ft_strlen(file_name) - len;
	// ft_printf("copy_start -> %d\n", copy_start);
	tmp = ft_strnew(len - len_to_copy(file_name));
	// ft_printf("%s\n", "Check");
	ft_strncpy(tmp, &file_name[copy_start], len - len_to_copy(file_name));
	res = ft_strjoin(tmp, ".cor");
	free(tmp);
	fd = open(res, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	// sample->prog_size = hexadecimal_to_decimal(dec_to_hexa(sample->prog_size));
	// ft_putnbr(sample->prog_size);
	sample->prog_size = bstr_to_dec(ft_to_binary(23));
	sample->magic = bstr_to_dec(ft_to_binary(15369203));;
	// sample->magic = 385875968;

	// ft_printf("unsigned int ->%u\n", sample->magic);
	// ft_printf("str size -> %d\n", sizeof(sample->prog_name));
	// ft_printf("unsigned int size -> %d\n", sizeof(sample->magic));
	write(fd, sample, sizeof(sample->magic) + sizeof(sample->prog_name)
			+ sizeof(sample->prog_size) + sizeof(sample->comment));

	// write(fd, (short*)ar, 2);

	close(fd);
	free(res);
}


// C++ program to convert binary to decimal
// #include<iostream>
// using namespace std;
 
// Function to convert binary to decimal
// unsigned int binaryToDecimal(char *str)
// {
//     int num = n;
//     int dec_value = 0;
     
//     // Initializing base value to 1, i.e 2^0
//     int base = 1;
     
//     int temp = num;
//     while (temp)
//     {
//         int last_digit = temp % 10;
//         temp = temp/10;
         
//         dec_value += last_digit*base;
         
//         base = base*2;
//     }
     
//     return dec_value;
// }


int		main(int argc, char **argv)
{
	t_toto	sample;

	(void)argc;
	ft_bzero(sample.prog_name, sizeof(sample.prog_name));
	ft_strcpy(sample.prog_name, "zork");
	ft_bzero(sample.comment, sizeof(sample.comment));
	ft_strcpy(sample.comment, "just a basic living prog");

	// unsigned int test;
	// unsigned int x = 23;
	// test = x;

	// ft_printf("-----------%u ->", bstr_to_dec(ft_to_binary(23)));

	
	write_to_struct(argv[1], &sample);

	ft_printf("\n");
	// ft_to_binary(test);
	// system("leaks -q asm");
}


