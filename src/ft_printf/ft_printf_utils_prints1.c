/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_prints1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:47:06 by ssucha            #+#    #+#             */
/*   Updated: 2026/02/11 18:45:23 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Prints number in hexadecimal.
 * @return Number of characters printed.
 */
static int	ft_puthex_unsigned(unsigned long n, char *base)
{
	int		count;

	count = 0;
	if (n >= 16)
		count += ft_puthex_unsigned(n / 16, base);
	count += ft_putchar(base[n % 16]);
	return (count);
}

/**
 * @brief Prints number in decimal.
 * @return Number of characters printed.
 */
static int	ft_putnbr_unsigned(unsigned int n)
{
	int		len;

	len = 0;
	if (n > 9)
		len += ft_putnbr_unsigned(n / 10);
	len += ft_putchar((n % 10) + '0');
	return (len);
}

/**
 * @brief Prints pointer address in hexadecimal.
 * @return Number of characters printed.
 */
static int	ft_putptr(void *ptr)
{
	int	count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	count = 0;
	count += ft_putstr("0x");
	count += ft_puthex_unsigned((unsigned long)ptr, "0123456789abcdef");
	return (count);
}

/**
 * @brief Calls print functions on number content.
 * @return Number of characters printed.
 */
static int	print_numbers(t_flags *flags, t_format_info *format_info)
{
	int	count;

	count = 0;
	if (ft_strchr("diuxX", flags->specifier) && flags->precision == 0
		&& (format_info->val_unsigned == 0 && format_info->val_signed == 0))
		return (0);
	if (flags->specifier == 'd' || flags->specifier == 'i')
	{
		if (format_info->val_signed < 0)
			count += ft_putnbr_unsigned(-format_info->val_signed);
		else
			count += ft_putnbr_unsigned(format_info->val_signed);
	}
	else if (flags->specifier == 'u')
		count += ft_putnbr_unsigned(format_info->val_unsigned);
	else if (flags->specifier == 'x')
		count += ft_puthex_unsigned(format_info->val_unsigned,
				"0123456789abcdef");
	else if (flags->specifier == 'X')
		count += ft_puthex_unsigned(format_info->val_unsigned,
				"0123456789ABCDEF");
	return (count);
}

/**
 * @brief Calls all print content functions.
 * @return Number of characters printed.
 */
int	__print_content(t_flags *flags, t_format_info *format_info)
{
	int	count;

	count = print_numbers(flags, format_info);
	if (flags->specifier == 'p')
		count += ft_putptr((void *)format_info->val_unsigned);
	else if (flags->specifier == 's')
	{
		if (!format_info->str_val)
		{
			if ((flags->precision < 6 && flags->precision != -1)
				|| (flags->width < 6 && flags->width > 0))
				return (0);
			else
				format_info->str_val = "(null)";
		}
		if (flags->precision >= 0)
			count += __ft_putnstr(format_info->str_val, flags->precision);
		else
			count += ft_putstr(format_info->str_val);
	}
	else if (flags->specifier == 'c')
		count += ft_putchar(format_info->char_val);
	else if (flags->specifier == '%')
		count += ft_putchar('%');
	return (count);
}
