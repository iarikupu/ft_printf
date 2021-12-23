/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:18:59 by iarikupu          #+#    #+#             */
/*   Updated: 2021/12/23 14:19:47 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsigned(t_data *info)
{
	long long	n;
	int			i;

	n = (unsigned int)va_arg(info->args, int);
	if (info->pre == -1 || !info->pre)
	{
		if ((info->pre == 0 || info->pre == -1) && n == 0 && info->dot)
			return (sp_pre(info, n, 0));
		i = ft_nbr_num_len(n, 10);
		if (!info->minus)
			print_space(info, i);
		info->length += i;
		ft_putnbr(n, "0123456789", info, 10);
		if (info->minus)
			print_space(info, i);
	}
	else
		pre_handle(n, info, 10, "0123456789");
}
