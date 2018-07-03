/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:48:54 by prippa            #+#    #+#             */
/*   Updated: 2018/06/05 16:36:57 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

/*
************************ Parsing champions part (data) *************************
*/

typedef struct			s_champ
{
	t_header			head; 							// nope;
	char				file_name[FILE_NAME_MAX + 1];	// nope;
	int					fd;								// nope;
	unsigned char		code[CHAMP_MAX_SIZE];			// yeap;
	int					champ_number;
	int					real_champ_number;
	unsigned int        lives_number;
	unsigned int        last_live;                      // todo implement in the cycle;
	struct s_champ		*next;							// yeap;
}						t_champ;

typedef struct			s_parse_data
{
	t_champ				*champs; 						// to add champ name/counter;
	long long int		tmp;
	int					champs_count;
	int					dump_stop;					// -dump flag
	char				flags[CW_F_SIZE];
}						t_parse_data;

/*
********************************** Core Part ***********************************
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
}						t_command;

typedef	struct			s_processes					// fork will create a process and will change the map;
{
	unsigned int		id;
	int					color;						// R: {1 - 4};
	int					process_PC;					// current position of the stack command line (iteratively according to the quantity of champs);
	int					carry;						// initially has zero value because this var will be modified after execution of the command;
	int					registers[REG_NUMBER];		// r1 -> player_name register;
	int 				live_status;				// flag to detect the life of the process;
	int 				has_been_activated;			// if the process has been used;
	int					champ_number;				// Number of champ
	short				cycles_till_execution;		// will be decremented;
	short				proc_process_PC_color;		// initial color;
	short				proc_color_write_to_map;	// color for writing on the map;
	int					current_command;			// keep the current command;
	int 				detect_deviation;			// cmd vs cur cmd;
	struct s_processes	*next;						// pointer to the next element;
	struct s_processes	*prev;						// pointer to the prev element;
}						t_processes;

typedef struct			s_stack
{
	unsigned char		stack[MEM_SIZE];			// whole stack;
	int					stack_color[MEM_SIZE];		// colors manipulation;
	unsigned int		write_to_the_map_stack[MEM_SIZE];	// maintain color buf for sti;
	unsigned int		cycle_stack[MEM_SIZE];		// to keep the 50 cycles;
}						t_stack;

/*
*********************** Implementing a function pointer ************************
*/

typedef struct			s_op
{
	void				((*func))(t_command *, t_stack *, t_processes *);
	short				cycles_price;
	short				arguments_quantity;
}						t_op;

/*
*************************** Global Elite Structure *****************************
*/

typedef struct			s_corewar
{
	t_parse_data		pd;
	t_stack				map;
	t_processes			*proc_start;
	t_processes			*proc_end;
	const t_op			*op;
	unsigned int		cycle;
	int					cycle_to_die;
	int					cycle_to_die_check;
	unsigned int		max_checks_check;
	unsigned int		proc_counter;				// size of active processes
	unsigned int		id_counter;					// counter of id in processes
}						t_corewar;

#endif

#define AAA "  ________                           ________                          \n /  _____/ _____     _____    ____   \\_____  \\  ___  __  ____  _______ \n"
