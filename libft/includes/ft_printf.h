/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:10:42 by prippa            #+#    #+#             */
/*   Updated: 2018/03/12 21:52:51 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include <inttypes.h>

# define SF_H			1
# define SF_HH			2
# define SF_L			3
# define SF_LL			4
# define SF_J			5
# define SF_Z			6

# define F_MINUS		0
# define F_PLUS			1
# define F_SPACE		2
# define F_SHARP		3
# define F_ZERO			4
# define F_DOT			5
# define F_COLOR		6

# define FPF_FLAG_SIZE	7

# define PC fpf->format[fpf->i]
# define PC_1 fpf->format[fpf->i + 1]
# define FC fpf->type
# define SIZE_FLAGS(c) (c == 'l' || c == 'h' || c == 'j' || c == 'z')
# define FLAGS(c) (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
# define BONUS_FLAGS(c) (c == '*' || c == '.' || c == '~')
# define MAX(a, b) (a > b ? a : b)

# define COLOR_RESET 	"\x1B[0m"
# define RED   			"\x1B[31m"
# define YELLOW   		"\x1B[33m"
# define GREEN   		"\x1B[32m"
# define CYAN   		"\x1B[36m"
# define BLUE   		"\x1B[34m"
# define MAGENTA   		"\x1B[35m"
# define WHITE 			"\x1B[37m"

# define BOLD_GRAY 		"\033[1;30m"
# define BOLD_RED 		"\033[1;31m"
# define BOLD_GREEN 	"\033[1;32m"
# define BOLD_YELLOW 	"\033[1;33m"
# define BOLD_BLUE 		"\033[1;34m"
# define BOLD_MAGENTA 	"\033[1;35m"
# define BOLD_CYAN 		"\033[1;36m"
# define BOLD_WHITE 	"\033[1;39m"

# define BACK_RED_BLACK		"\e[30;41m"
# define BACK_GREEN_BLACK	"\e[30;42m"
# define BACK_BLUE_BLACK	"\e[30;44m"
# define BACK_CYAN_BLACK	"\e[30;46m"
# define BACK_GRAY_BLACK	"\e[30;100m"

# define BACK_RED_WHITE		"\e[1;97;41m"
# define BACK_GREEN_WHITE	"\e[1;97;42m"
# define BACK_BLUE_WHITE	"\e[1;97;44m"
# define BACK_CYAN_WHITE	"\e[1;97;46m"


typedef enum	e_colors
{
	F_GREEN = 0,
	F_BLUE,
	F_RED,
	F_CYAN,
	F_YELLOW,
	F_MAGENTA,
	F_WHITE,
	F_BOLD_GRAY,
	F_BOLD_RED,
	F_BOLD_GREEN,
	F_BOLD_YELLOW,
	F_BOLD_BLUE,
	F_BOLD_MAGENTA,
	F_BOLD_CYAN,
	F_BOLD_WHITE,
	F_BACK_GREEN_BLACK,
	F_BACK_BLUE_BLACK,
	F_BACK_RED_BLACK,
	F_BACK_CYAN_BLACK,
	F_BACK_GRAY_BLACK,
	F_BACK_GREEN_WHITE,
	F_BACK_BLUE_WHITE,
	F_BACK_RED_WHITE,
	F_BACK_CYAN_WHITE
}				t_colors;

typedef	struct			s_printf
{
	int					fd;
	char				*format;
	int					i;
	int					size;
	va_list				args;
	char				flag[FPF_FLAG_SIZE];
	int					width;
	int					precision;
	int					size_flag;
	char				type;
	char				*str;
	char				*out_str;
	int					color;
}						t_printf;

int						ft_printf(const char *format, ...);
int						ft_dprintf(int fd, const char *format, ...);
void					ft_lobi(t_printf *fpf);
void					ft_base_output(t_printf *fpf);
void					ft_initialization(t_printf *fpf);
void					ft_dispatcher(t_printf *fpf);
void					ft_fpf_color(t_printf *fpf);

void					ft_get_flags(t_printf *fpf);
int						ft_get_flag_type(t_printf *fpf);
void					ft_get_type(t_printf *fpf);
char					*ft_wstr_to_str(wchar_t *ws);
long long int			ft_conv_sig_int(t_printf *fpf);
unsigned long long int	ft_conv_unsig_int(t_printf *fpf);

char					*ft_get_c(t_printf *fpf);
char					*ft_get_s(t_printf *fpf);
char					*ft_get_oux(t_printf *fpf);
char					*ft_get_di(t_printf *fpf);

void					ft_output_c_modul(t_printf *fpf);
void					ft_output_s_modul(t_printf *fpf);
void					ft_output_d_modul(t_printf *fpf);
void					ft_output_u_modul(t_printf *fpf);
void					ft_output_ox_modul(t_printf *fpf);
void					ft_output_p_modul(t_printf *fpf);

int						ft_atoi(const char *str);
char					*ft_itoa_max(long long int num);
char					*ft_itoa_base(unsigned long long int num,
						int base, int letter);
int						ft_isdigit(int c);
int						ft_isspace(int c);
int						ft_isascii(int c);
size_t					ft_strlen(const char *s);
void					ft_bzero(void *s, size_t n);
char					*ft_strdup(const char *s1);
void					ft_pf_strjoin(t_printf *fpf, char *str, int size);
void					ft_charjoin(t_printf *fpf, int n, char c);

#endif
