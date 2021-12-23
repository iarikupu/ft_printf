/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 09:57:39 by iarikupu          #+#    #+#             */
/*   Updated: 2021/12/23 14:16:05 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pointer(t_data *info)
{
	unsigned long long	n;
	int					i;

	n = va_arg(info->args, unsigned long long);
	i = (2 + ft_nbr_num_len(n, 16));
	if (!info->minus)
		print_space(info, i);
	write(1, "0x", 2);
	ft_putnbr(n, "0123456789abcdef", info, 16);
	if (info->minus)
		print_space(info, i);
	info->length += i;
}
