/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_errors.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:47:06 by ssucha            #+#    #+#             */
/*   Updated: 2026/02/11 18:45:33 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	__error_check(va_list *args, t_flags *flags, int *count)
{
	int		error_check_count;

	error_check_count = __print_formatted(args, flags);
	if (error_check_count < 0)
		return (-1);
	*count += error_check_count;
	return (0);
}

int	__value_errors(t_flags *flags)
{
	if (!ft_strchr("cspdiuxX%", flags->specifier))
	{
		ft_putstr("Error: wrong input: unknown format specifier\n");
		return (-1);
	}
	if ((flags->space && flags->plus) && (flags->specifier == 'd'
			|| flags->specifier == 'i'))
	{
		ft_putstr("Error: Space ignored because of '+'\n");
		return (-1);
	}
	if ((flags->zero && flags->minus) && (flags->specifier == 'd'
			|| flags->specifier == 'i'))
	{
		ft_putstr("Error: Zero ignored because of '-'\n");
		return (-1);
	}
	return (0);
}
