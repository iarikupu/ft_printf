/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:20:34 by iarikupu          #+#    #+#             */
/*   Updated: 2021/12/23 14:21:15 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexl(t_data *info)
{
	long long	n;
	int			i;

	i = 0;
	n = va_arg(info->args, unsigned);
	if (info->hash == 1 && n)
	{
		write(1, "0x", 2);
		i += 2;
	}
	if (info->pre == -1 || !info->pre)
		hex_help(n, info, i, "0123456789abcdef");
	else
	{
		if (info->width > info->pre)
			info->dot = 3;
		pre_handle(n, info, 16, "0123456789abcdef");
	}
}

void	ft_hexu(t_data *info)
{
	long long	n;
	int			i;

	i = 0;
	n = va_arg(info->args, unsigned);
	if (info->hash == 1 && n)
	{
		write(1, "0X", 2);
		i += 2;
	}
	if (info->pre == -1 || !info->pre)
		hex_help(n, info, i, "0123456789ABCDEF");
	else
	{
		if (info->width > info->pre)
			info->dot = 3;
		pre_handle(n, info, 16, "0123456789ABCDEF");
	}
}

void	hex_help(unsigned long long n, t_data *info, int i, char *s)
{
	if ((info->pre == 0 || info->pre == -1) && n == 0 && info->dot)
		return (sp_pre(info, n, i));
	i += ft_nbr_num_len(n, 16);
	if (!info->minus && i - ft_nbr_num_len(n, 16) == 0)
		print_space(info, i);
	info->length += i;
	ft_putnbr(n, s, info, 16);
	if (info->minus)
		print_space(info, i);
}
