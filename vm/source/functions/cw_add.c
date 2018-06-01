/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:44:40 by otimofie          #+#    #+#             */
/*   Updated: 2018/06/01 16:44:41 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			cw_add(int var_x, int var_y, int *var_res, int *carry)
{
	*var_res = var_x + var_y;
	*carry = (var_res != 0) ? 1 : 0;
}
