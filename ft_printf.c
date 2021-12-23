/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:08:23 by iarikupu          #+#    #+#             */
/*   Updated: 2021/12/23 14:09:05 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstuff(t_data *info)
{
	if (*info->format == 'c')
		ft_char_stuff(info);
	else if (*info->format == 's')
		ft_string(info);
	else if (*info->format == 'p')
		ft_pointer(info);
	else if (*info->format == 'd' || *info->format == 'i')
		ft_int(info);
	else if (*info->format == 'u')
		ft_unsigned(info);
	else if (*info->format == 'x')
		ft_hexl(info);
	else if (*info->format == 'X')
		ft_hexu(info);
	else if (*info->format == '%')
	{
		write(1, "%", 1);
		info->length++;
	}
	info->format++;
}

int	ft_printf(const char *format, ...)
{
	t_data		*info;
	int			length;

	info = (t_data *)malloc(sizeof(t_data));
	va_start(info->args, format);
	info->format = format;
	info->length = 0;
	while (*info->format)
	{
		set_flags(info);
		while (*info->format && *info->format != '%')
		{
			ft_putchar(*info->format++);
			info->length++;
		}
		if (*info->format && *info->format == '%')
			eval_stuff(info);
	}
	va_end(info->args);
	length = info->length;
	free(info);
	return (length);
}
