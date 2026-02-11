/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_prints2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:47:06 by ssucha            #+#    #+#             */
/*   Updated: 2026/02/11 18:48:00 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Writes a string to a standard output.
 * @param n The maximum number of characters to be printed.
 * @return Number of successfully writen characters (len/-1)
 */
int	__ft_putnstr(char *s, int n)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s && s[i] && i < n)
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

/**
 * @brief Stores value of input to the format_info struct according to its type.
 * @return 0 on success, -1 on value error.
 */
static int	extract_value(va_list *args, t_flags *flags,
	t_format_info *format_info)
{
	if (__value_errors(flags) < 0)
		return (-1);
	if ((flags->specifier == 'd' || flags->specifier == 'i'))
		format_info->val_signed = va_arg(*args, int);
	else if (flags->specifier == 'u' || flags->specifier == 'x'
		|| flags->specifier == 'X')
		format_info->val_unsigned = va_arg(*args, unsigned int);
	else if (flags->specifier == 'p')
		format_info->val_unsigned = (unsigned long)va_arg(*args, void *);
	else if (flags->specifier == 's')
		format_info->str_val = va_arg(*args, char *);
	else if (flags->specifier == 'c')
		format_info->char_val = (char)va_arg(*args, int);
	return (0);
}

/**
 * @brief Prints all the paddings preceeding the content itself.
 * @return Number of characters printed.
 */
static int	print_padding_prefix(t_flags *flags, t_format_info *format_info)
{
	int	count;

	count = 0;
	if (!flags->minus)
		while (format_info->spaces-- > 0)
			count += ft_putchar(' ');
	if ((flags->specifier == 'd' || flags->specifier == 'i'))
	{
		if (format_info->val_signed < 0)
			count += ft_putchar('-');
		else if (flags->plus)
			count += ft_putchar('+');
		else if (flags->space)
			count += ft_putchar(' ');
	}
	if ((flags->specifier == 'x' || flags->specifier == 'X')
		&& flags->hash && format_info->val_unsigned != 0)
	{
		count += ft_putchar('0');
		count += ft_putchar(flags->specifier);
	}
	while (format_info->len_zero-- > 0)
		count += ft_putchar('0');
	return (count);
}

/**
 * @brief Prints all the post spaces succeeding the content itself.
 * @return Number of characters printed.
 */
static int	print_post_spaces(t_flags *flags, t_format_info *format_info)
{
	int	count;

	count = 0;
	if (flags->minus || (ft_strchr("diuxX", flags->specifier)
			&& flags->precision == 0 && (format_info->val_unsigned == 0
				&& format_info->val_signed == 0)))
		while (format_info->spaces-- > 0)
			count += ft_putchar(' ');
	return (count);
}

/**
 * @brief Applies formatting and prints the final result
 * according to the t_flags struct.
 * @return Number of characters printed.
 */
int	__print_formatted(va_list *args, t_flags *flags)
{
	t_format_info	*format_info;
	int				count;

	format_info = malloc(sizeof(t_format_info));
	if (!format_info)
	{
		ft_putstr("Malloc error\n");
		return (-1);
	}
	ft_bzero(format_info, sizeof(t_format_info));
	if (extract_value(args, flags, format_info) < 0)
	{
		free(format_info);
		return (-1);
	}
	__count_len_content_nbr(flags, format_info);
	if (!ft_strchr("diuxX", flags->specifier))
		__count_len_content_other(flags, format_info);
	__compute_flag_lengths(flags, format_info);
	count = 0;
	count += print_padding_prefix(flags, format_info);
	count += __print_content(flags, format_info);
	count += print_post_spaces(flags, format_info);
	free(format_info);
	return (count);
}
