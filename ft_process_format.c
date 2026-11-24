/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjaafar <mjaafar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 15:57:44 by mjaafar           #+#    #+#             */
/*   Updated: 2026/11/23 15:23:26 by mjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_process_format(const char *format, va_list *args)
{
	int	i;
	int	count;
	int	result;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			result = ft_handle_conversion(format[i + 1], args);
			if (result >= 0)
			{
				count += result;
				i++;
			}
			else
				count += ft_print_char(format[i]);
		}
		else
			count += ft_print_char(format[i]);
		i++;
	}
	return (count);
}
