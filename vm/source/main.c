/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 13:56:33 by prippa            #+#    #+#             */
/*   Updated: 2018/05/26 13:56:44 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		main(int argc, char **argv)
{
	cw_init();
	cw_parse_args(argc, argv + 1);
	cw_parser();
	cw_load_map();
	cw_init_processes(g_cw->pd.champs, &g_cw->processes);
	cw_game_loop();
	cw_free(); // why it leaks ?
	system("leaks -q corewar");
	return (0);
}
