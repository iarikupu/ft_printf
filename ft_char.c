/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 08:05:06 by iarikupu          #+#    #+#             */
/*   Updated: 2021/12/21 08:15:42 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char_stuff(t_data *info)
{
	if (! info->minus)
	{
		while (info->width-- - 1 > 0)
		{
			info->length++;
			write(1, " ", 1);
		}
	}
	ft_char(info);
	if (info->minus)
	{
		while (info->width-- - 1 > 0)
		{
			info->length++;
			write(1, " ", 1);
		}
	}
}

void	ft_char(t_data *info)
{
	info->length++;
	ft_putchar(va_arg(info->args, int));
}
