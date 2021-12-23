/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:08:43 by iarikupu          #+#    #+#             */
/*   Updated: 2021/12/23 14:09:03 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdlib.h>
# include<unistd.h>
# include<stdarg.h>
# include <stdio.h>

typedef struct s_data
{
	const char	*format;
	va_list		args;
	int			length;
	int			minus;
	int			zero;
	int			hash;
	int			space;
	int			plus;
	int			width;
	int			pre;
	int			dot;
}	t_data;

void	set_flags(t_data *info);
int		is_flag(t_data *info);
void	eval_stuff(t_data *info);
int		ft_printf(const char *format, ...);
int		ft_isspace(char c);
int		ft_atoi(const char *nptr);
void	ft_putstuff(t_data *info);
void	ft_char(t_data *info);
void	ft_putchar(char c);
int		ft_isdigit(int n);
size_t	ft_strlen(const char *s);
void	ft_string(t_data *info);
void	ft_int(t_data *info);
void	ft_unsigned(t_data *info);
void	ft_percent(t_data *info);
void	ft_pointer(t_data *info);
void	ft_hexl(t_data *info);
void	ft_hexu(t_data *info);
void	ft_putnbr(unsigned long long n, char *s, t_data *info, int base);
void	minint(void);
void	space_plus(t_data *info);
void	ft_char_stuff(t_data *info);
void	print_space(t_data *info, int i);
int		ft_nbr_num_len(unsigned long long n, int b);
void	pre_handle(unsigned long long n, t_data *info, int b, char *s);
void	int_help(unsigned long long n, t_data *info, int i);
void	string_null(t_data *info);
void	sp_pre(t_data *info, int n, int i);
void	hex_help(unsigned long long n, t_data *info, int i, char *s);
void	get_over(t_data *info, unsigned long long n);
void	done(t_data *info, unsigned long long n, int i);

#endif
