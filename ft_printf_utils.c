/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:10:25 by iarikupu          #+#    #+#             */
/*   Updated: 2021/12/23 14:13:34 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_flags(t_data *info)
{
	info->minus = 0;
	info->zero = 0;
	info->hash = 0;
	info->space = 0;
	info->plus = 0;
	info->width = 0;
	info->pre = -1;
	info->dot = 0;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_flag(t_data *info)
{
	if (*info->format == '0')
		info->zero = 1;
	else if (*info->format == '-')
		info->minus = 1;
	else if (*info->format == ' ')
		info->space = 1;
	else if (*info->format == '+')
		info->plus = 1;
	else if (*info->format == '#')
		info->hash = 1;
	else
		return (0);
	return (1);
}

void	eval_stuff(t_data *info)
{
	info->format++;
	while (is_flag(info))
		info->format++;
	if (*info->format >= '0' && *info->format <= '9')
		info->width = ft_atoi(info->format);
	while (*info->format >= '0' && *info->format <= '9')
		info->format++;
	if (*info->format == '.')
	{
		info->pre = ft_atoi(++info->format);
		info->dot = 1;
	}
	while (*info->format >= '0' && *info->format <= '9')
		info->format++;
	ft_putstuff(info);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (! s)
		return (6);
	len = 0;
	while (*s++)
		len++;
	return (len);
}
