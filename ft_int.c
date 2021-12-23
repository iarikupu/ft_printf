/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:16:47 by iarikupu          #+#    #+#             */
/*   Updated: 2021/12/23 14:26:22 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_int(t_data *info)
{
	long long	n;
	int			i;

	i = 0;
	n = va_arg(info->args, int);
	if (n >= 0 && (info->space == 1 || info->plus == 1))
		space_plus(info);
	if (n < 0)
	{
		i++;
		n *= -1;
		if (info->zero && info->dot && info->pre < info->width)
			return (get_over(info, n));
		done(info, n, i);
		if (!(info->pre == -1 || !info->pre))
			info->length++;
		info->dot = 2;
	}
	if (info->pre == -1 || !info->pre)
		int_help(n, info, i);
	else
		pre_handle(n, info, 10, "0123456789");
}

void	get_over(t_data *info, unsigned long long n)
{
	if (info->pre < ft_nbr_num_len(n, 10))
		info->pre = ft_nbr_num_len(n, 10);
	info->zero = 0;
	print_space(info, info->pre + 1);
	write(1, "-", 1);
	info->length++;
	info->width = info->pre;
	info->zero = 1;
	print_space(info, ft_nbr_num_len(n, 10));
	ft_putnbr(n, "0123456789", info, 10);
	info->length += ft_nbr_num_len(n, 10);
}

void	done(t_data *info, unsigned long long n, int i)
{
	if (!info->minus && !info->zero)
		print_space(info, i + ft_nbr_num_len(n, 10));
	write(1, "-", 1);
	if (info->zero && info->width > info->pre)
		print_space(info, i + ft_nbr_num_len(n, 10));
}

void	int_help(unsigned long long n, t_data *info, int i)
{
	if ((info->pre == 0 || info->pre == -1) && n == 0 && info->dot)
		return (sp_pre(info, n, i));
	i += ft_nbr_num_len(n, 10);
	if (!info->minus && i - ft_nbr_num_len(n, 10) == 0)
		print_space(info, i);
	info->length += i;
	ft_putnbr(n, "0123456789", info, 10);
	if (info->minus)
		print_space(info, i);
}

void	space_plus(t_data *info)
{
	if (info->space == 1)
		write(1, " ", 1);
	else
		write(1, "+'", 1);
	info->length++;
}
