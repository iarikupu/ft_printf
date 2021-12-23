/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:14:04 by iarikupu          #+#    #+#             */
/*   Updated: 2021/12/23 14:14:14 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_space(t_data *info, int i)
{
	char	c;

	if (!info->zero)
		c = ' ';
	else
		c = '0';
	while (info->width > i)
	{
		info->length++;
		write(1, &c, 1);
		info->width--;
	}
}
