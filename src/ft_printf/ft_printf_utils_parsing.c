/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_parsing.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:47:06 by ssucha            #+#    #+#             */
/*   Updated: 2026/02/11 17:55:28 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse_flags_chars(const char *format, t_flags *flags)
{
	int	i;

	i = 0;
	while (ft_strchr("-0#+ ", format[i]))
	{
		if (format[i] == '-')
			flags->minus += 1;
		else if (format[i] == '0')
			flags->zero += 1;
		else if (format[i] == '#')
			flags->hash += 1;
		else if (format[i] == '+')
			flags->plus += 1;
		else if (format[i] == ' ')
			flags->space += 1;
		i++;
	}
	return (i);
}

static int	parse_flags_width(const char *format, t_flags *flags)
{
	int	i;

	i = 0;
	while (ft_isdigit(format[i]))
	{
		flags->width = flags->width * 10 + (format[i] - '0');
		i++;
	}
	return (i);
}

static int	parse_flags_precision(const char *format, t_flags *flags)
{
	int	i;

	i = 0;
	if (format[i] == '.')
	{
		i++;
		flags->precision = 0;
		while (ft_isdigit(format[i]))
		{
			flags->precision = flags->precision * 10 + (format[i] - '0');
			i++;
		}
	}
	return (i);
}

static int	parse_flags_specifier(const char *format, t_flags *flags)
{
	int	i;

	i = 0;
	if (ft_strchr("cspdiuxX%", format[i]))
	{
		flags->specifier = format[i];
		i++;
	}
	return (i);
}

/**
 * @brief Fills t_flags struct with format string info.
 * @return Len of format signs - number of signs for string index to skip.
 */
int	__parse_flags(const char *format, t_flags *flags)
{
	int	i;

	i = 0;
	ft_bzero(flags, sizeof(t_flags));
	flags->precision = -1;
	i += parse_flags_chars(&format[i], flags);
	i += parse_flags_width(&format[i], flags);
	i += parse_flags_precision(&format[i], flags);
	i += parse_flags_specifier(&format[i], flags);
	return (i);
}
