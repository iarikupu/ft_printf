/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_share.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:15:35 by iarikupu          #+#    #+#             */
/*   Updated: 2021/12/23 14:19:54 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbr_num_len(unsigned long long n, int b)
{
	int	l;

	l = 0;
	if (! n)
		return (1);
	while (n)
	{
		l++;
		n /= b;
	}
	return (l);
}

void	ft_putnbr(unsigned long long n, char *s, t_data *info, int base)
{
	if (n >= (unsigned long long)base)
		ft_putnbr(n / base, s, info, base);
	ft_putchar(s[n % base]);
}

void	pre_handle(unsigned long long n, t_data *info, int b, char *s)
{
	int	i;
	int	j;

	j = info->width;
	i = ft_nbr_num_len(n, b);
	if (i > info->pre)
		info->pre = i;
	while (j > info->pre && (info->zero || (info->dot == 3 && !info->minus)))
	{
		write(1, " ", 1);
		info->length++;
		j--;
	}
	while (info->pre > i++)
	{
		write(1, "0", 1);
		info->length++;
	}
	if (info->dot != 2)
		i--;
	ft_putnbr(n, s, info, b);
	info->length += ft_nbr_num_len(n, b);
	if (!info->zero && j != info->pre)
		print_space(info, i);
}

void	sp_pre(t_data *info, int n, int i)
{
	if (n == 0)
		info->zero = 0;
	print_space(info, i);
	return ;
}
