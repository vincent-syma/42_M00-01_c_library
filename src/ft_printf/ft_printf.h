/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 19:52:23 by ssucha            #+#    #+#             */
/*   Updated: 2026/02/11 17:54:59 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef struct s_flags
{
	int		minus;		// Flag '-' (left-align)
	int		zero;		// Flag '0' (zero-padding)
	int		hash;		// Flag '#' (alternate form for x, X)
	int		plus;		// Flag '+' (explicit plus for positive numbers)
	int		space;		// Flag ' ' (space for positive numbers)
	int		width;		// Minimum field width
	int		precision;	// Flag '.' -1 if not set, >=0 = value
	char	specifier;	// Format specifier (c, s, d, i, u, x, X, p, %)
}	t_flags;

typedef struct s_format_info
{
	long			val_signed;
	unsigned long	val_unsigned;
	char			char_val;
	char			*str_val;		// string value
	int				len_content;
	int				len_prefix;
	int				len_zero;
	int				spaces;			// number of spaces
}	t_format_info;

int		__parse_flags(const char *format, t_flags *flags);
int		__error_check(va_list *args, t_flags *flags, int *count);
int		__value_errors(t_flags *flags);
void	__count_len_content_nbr(t_flags *flags, t_format_info *format_info);
void	__count_len_content_other(t_flags *flags, t_format_info *format_info);
void	__compute_flag_lengths(t_flags *flags, t_format_info *format_info);
int		__ft_putnstr(char *s, int n);
int		__print_content(t_flags *flags, t_format_info *format_info);
int		__print_formatted(va_list *args, t_flags *flags);

#endif