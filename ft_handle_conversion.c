/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjaafar <mjaafar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 14:26:50 by mjaafar           #+#    #+#             */
/*   Updated: 2026/11/21 15:59:14 by mjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_char(va_list *args)
{
	char	c;

	c = va_arg(*args, int);
	write(1, &c, 1);
	return (1);
}

static int	ft_print_string(va_list *args)
{
	char	*str;
	int		len;

	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

static int	ft_print_signed(va_list *args)
{
	return (ft_putnbr_count(va_arg(*args, int)));
}

static int	ft_print_unsigned(va_list *args)
{
	return (ft_putunsigned_count(va_arg(*args, unsigned int)));
}

int	ft_handle_conversion(char format, va_list *args)
{
	if (format == 'c')
		return (ft_handle_char(args));
	if (format == 's')
		return (ft_print_string(args));
	if (format == 'd' || format == 'i')
		return (ft_print_signed(args));
	if (format == 'u')
		return (ft_print_unsigned(args));
	if (format == 'x' || format == 'X')
		return (ft_print_hex(args, format));
	if (format == 'p')
		return (ft_print_pointer(args));
	if (format == '%')
		return (write(1, "%", 1), 1);
	return (-1);
}
