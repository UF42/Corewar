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

typedef struct s_toto
{
	unsigned int x;
	char str[5];
}				t_toto;

int reversebits(int num)
{
    int NO_OF_BITS = sizeof(num) * 8;
    int reverse_num = 0, i, temp;
 
    for (i = 0; i < NO_OF_BITS; i++)
    {
        temp = (num & (1 << i));
        if(temp)
            reverse_num |= (1 << ((NO_OF_BITS - 1) - i));
    }
  
    return reverse_num;
}

int		ft_string_size(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '.') // / / / / /.s
		i++;
	return (i);
}

void	create_name_string(char *file_name_to_open, char *data_to_be_written)
{
	int len; 	// len till '.';
	int fd; 	// file descriptor;
	char *tmp; 	// buf;
	char *res; 	// string after join;

	len = ft_string_size(file_name_to_open);
	tmp = ft_strnew(len);
	ft_strncpy(tmp, file_name_to_open, len);
	res = ft_strjoin(tmp, ".cor");
	free(tmp);

	fd = open(res, O_WRONLY | O_CREAT, 0777);

	write(fd, data_to_be_written, ft_strlen(data_to_be_written)); // can be int value;

	close(fd);
	free(res);
}

unsigned int reverseBits(unsigned int num)
{
    unsigned int count = sizeof(num) * 8 - 1;
    unsigned int reverse_num = num;
     
    num >>= 1; 
    while(num)
    {
       reverse_num <<= 1;       
       reverse_num |= num & 1;
       num >>= 1;
       count--;
    }
    reverse_num <<= count;
    return reverse_num;
}

void	create_name_struct(char *file_name_to_open, t_toto *sample)
{
	int len; 	// len till '.';
	int fd; 	// file descriptor;
	char *tmp; 	// buf;
	char *res; 	// string after join;

	len = ft_string_size(file_name_to_open);
	tmp = ft_strnew(len);
	ft_strncpy(tmp, file_name_to_open, len);
	res = ft_strjoin(tmp, ".cor");
	free(tmp);

	fd = open(res, O_WRONLY | O_CREAT | O_TRUNC, 0777); //current position of the |;



	// hex = reverseBits(sample->x);
	

	write(fd, sample, sizeof(sample->str) + sizeof(sample->x));

	// ft_printf("sizeof struct in func -> %d\n", sizeof(sample->str) + sizeof(sample->x));

	close(fd);





	free(res);
}

void decToHexa(int n)
{   
    // char array to store hexadecimal number
    char hexaDeciNum[100];
     
    // counter for hexadecimal number array
    int i = 0;
    while(n!=0)
    {   
        // temporary variable to store remainder
        int temp  = 0;
         
        // storing remainder in temp variable.
        temp = n % 16;
         
        // check if temp < 10
        if(temp < 10)
        {
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else
        {
            hexaDeciNum[i] = temp + 55;
            i++;
        }
         
        n = n/16;
    }
     
    // printing hexadecimal number array in reverse order
    for(int j=i-1; j>=0; j--)
       ft_printf("%c", hexaDeciNum[j]);
}

int		main(int argc, char **argv)
{
	(void)argc;	

	t_toto sample;

	// sample.str = ft_strdup("12345");

	ft_bzero(sample.str, sizeof(sample.str)); //
	ft_strcpy(sample.str, "abcde");

	sample.x = 2147483647; //reverse bits;

	decToHexa(sample.x);

	// unsigned int magic;
	// unsigned int prog_size;


	// ft_printf("%d\n", reversebits(sample.x));

	// ft_printf("sizeof struct in main-> %d\n", sizeof(sample));

	create_name_struct(argv[1], &sample);

	system("leaks -q asm");
}
