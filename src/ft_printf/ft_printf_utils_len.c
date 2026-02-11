/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_len.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:47:06 by ssucha            #+#    #+#             */
/*   Updated: 2026/02/11 17:55:19 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @param n Number to be printed
 * @param base	10 / 16 etc.
 * @param is_signed 1 if signed (can be negative), 0 if unsigned
 * @return Length of a printable signed or unsigned number.
 */
static int	nbr_len(long long n, int base, int is_signed)
{
	int					len;
	unsigned long long	val;
	unsigned long long	uns_base;

	len = 1;
	is_signed += 0;
	val = (unsigned long long)n;
	uns_base = (unsigned long long)base;
	while (val >= uns_base)
	{
		val = val / uns_base;
		len++;
	}
	return (len);
}

/**
 * @return Length of a printable pointer address or length of "(nil)".
 */
static int	ptr_len(void *ptr)
{
	if (!ptr)
		return (5);
	return (nbr_len((long long)ptr, 16, 0));
}

/**
 * @brief Counts length of the content to be printed
 * and stores it into the format_info->len_content (numbers).
 */
void	__count_len_content_nbr(t_flags *flags, t_format_info *format_info)
{
	if (ft_strchr("diuxX", flags->specifier) && flags->precision == 0
		&& format_info->val_unsigned == 0 && format_info->val_signed == 0)
	{
		format_info->len_content = 0;
		return ;
	}
	if (flags->specifier == 'd' || flags->specifier == 'i')
	{
		if (format_info->val_signed < 0)
			format_info->len_content = nbr_len(-format_info->val_signed, 10, 0);
		else
			format_info->len_content = nbr_len(format_info->val_signed, 10, 0);
	}
	else if (flags->specifier == 'u')
		format_info->len_content = nbr_len(format_info->val_unsigned, 10, 0);
	else if (flags->specifier == 'x' || flags->specifier == 'X')
		format_info->len_content = nbr_len(format_info->val_unsigned, 16, 0);
}

/**
 * @brief Counts length of the content to be printed
 * and stores it into the format_info->len_content (other than numbers).
 */
void	__count_len_content_other(t_flags *flags, t_format_info *format_info)
{
	if (flags->specifier == 'p')
		format_info->len_content = ptr_len((void *)format_info->val_unsigned);
	else if (flags->specifier == 's')
	{
		if (!format_info->str_val)
		{
			if ((flags->precision < 6 && flags->precision != -1)
				|| (flags->width < 6 && flags->width > 0))
				format_info->len_content = 0;
			else
				format_info->len_content = 6;
		}
		else if (flags->precision >= 0
			&& flags->precision < (int)ft_strlen(format_info->str_val))
			format_info->len_content = flags->precision;
		else
			format_info->len_content = ft_strlen(format_info->str_val);
	}
	else
		format_info->len_content = ft_strlen("1");
}

/**
 * @brief Counts additional length related values
 * (prefixes, zeros, spaces, width) and stores them into the format_info struct.
 */
void	__compute_flag_lengths(t_flags *flags, t_format_info *format_info)
{
	int	total_len;

	if ((flags->specifier == 'd' || flags->specifier == 'i'))
	{
		if (format_info->val_signed < 0)
			format_info->len_prefix = 1;
		else if (flags->plus || flags->space)
			format_info->len_prefix = 1;
	}
	else if (((flags->specifier == 'x' || flags->specifier == 'X')
			&& flags->hash && format_info->val_unsigned != 0)
		|| (flags->specifier == 'p' && format_info->val_unsigned != 0))
		format_info->len_prefix = 2;
	if (flags->specifier != 's' && flags->precision > format_info->len_content)
		format_info->len_zero = flags->precision - format_info->len_content;
	else if (flags->zero && !flags->minus && flags->precision < 0)
		format_info->len_zero = flags->width - (format_info->len_content
				+ format_info->len_prefix);
	if (format_info->len_zero < 0)
		format_info->len_zero = 0;
	total_len = format_info->len_content + format_info->len_prefix
		+ format_info->len_zero;
	if (flags->width > total_len)
		(format_info->spaces = flags->width - total_len);
}
