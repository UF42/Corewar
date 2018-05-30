/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tostruppercase.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:13:31 by prippa            #+#    #+#             */
/*   Updated: 2017/11/09 16:15:20 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_str_to_upper(char **str)
{
	int i;

	i = 0;
	while ((*str)[i])
	{
		if (ft_islower((*str)[i]))
			(*str)[i] = ft_toupper((*str)[i]);
		i++;
	}
}
