/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 08:21:24 by iarikupu          #+#    #+#             */
/*   Updated: 2021/12/23 14:13:36 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_string(t_data *info)
{
	char	*s;
	int		len;

	s = va_arg(info->args, char *);
	if (s == NULL)
		return (string_null(info));
	if ((int)ft_strlen(s) > info->pre && info->pre >= 0)
		len = info->pre;
	else
		len = (int)ft_strlen(s);
	if (! info->minus)
		print_space(info, len);
	info->length += len;
	write(1, s, len);
	if (info->minus)
		print_space(info, len);
}

void	string_null(t_data *info)
{
	if (! info->minus)
		print_space(info, 6);
	if (info->pre > 6 || info->pre == -1)
	{
		write(1, "(null)", 6);
		info->length += 6;
	}
	else
	{	
		write(1, "(null)", info->pre);
		info->length += info->pre;
	}
}
