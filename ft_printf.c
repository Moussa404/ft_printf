/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjaafar <mjaafar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 15:19:57 by mjaafar           #+#    #+#             */
/*   Updated: 2026/11/21 16:03:32 by mjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, format);
	count = ft_process_format(format, &args);
	va_end(args);
	return (count);
}

// #include "ft_printf.h"

// int	ft_printf(const char *format, ...)
// {
// 	int				i;
// 	int				count;
// 	char			c;
// 	char			*str;
// 	int				number;
// 	unsigned int	u_number;
// 	unsigned int	hex_number;
// 	void			*ptr;
// 	va_list			args;

// 	i = 0;
// 	count = 0;
// 	va_start(args, format);
// 	while (format[i])
// 	{
// 		if (format[i] == '%' && format[i + 1] == 'c')
// 		{
// 			c = va_arg(args, int);
// 			write(1, &c, 1);
// 			count++;
// 			i++;
// 		}
// 		else if (format[i] == '%' && format[i + 1] == '%')
// 		{
// 			write(1, "%", 1);
// 			count++;
// 			i++;
// 		}
// 		else if (format[i] == '%' && format[i + 1] == 's')
// 		{
// 			str = va_arg(args, char *);
// 			count += ft_strlen(str);
// 			write(1, str, ft_strlen(str));
// 			i++;
// 		}
// 		else if (format[i] == '%' && (format[i + 1] == 'd'
// 				|| format[i + 1] == 'i'))
// 		{
// 			number = va_arg(args, int);
// 			count += ft_putnbr_count(number);
// 			i++;
// 		}
// 		else if (format[i] == '%' && format[i + 1] == 'u')
// 		{
// 			u_number = va_arg(args, unsigned int);
// 			count += ft_putunsigned_count(u_number);
// 			i++;
// 		}
// 		else if (format[i] == '%' && (format[i + 1] == 'x'
// 				|| format[i + 1] == 'X'))
// 		{
// 			hex_number = va_arg(args, unsigned int);
// 			count += ft_puthex_count(hex_number, format[i + 1]);
// 			i++;
// 		}
// 		else if (format[i] == '%' && format[i + 1] == 'p')
// 		{
// 			ptr = va_arg(args, void *);
// 			if (!ptr)
// 			{
// 				write(1, "(nil)", 5);
// 				count += 5;
// 			}
// 			else
// 			{
// 				write(1, "0x", 2);
// 				count += 2;
// 				count += ft_putptr_count((unsigned long)ptr);
// 			}
// 			i++;
// 		}
// 		else
// 		{
// 			write(1, &format[i], 1);
// 			count++;
// 		}
// 		i++;
// 	}
// 	va_end(args);
// 	return (count);
// }

// Macro/type	Purpose
// va_list		Stores the argument-list information
// va_start		Initializes access to the extra arguments
// va_arg		Retrieves the next argument
// va_end		Ends access to the arguments
// va_copy		Copies an argument list