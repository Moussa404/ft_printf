/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjaafar <mjaafar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 15:47:18 by mjaafar           #+#    #+#             */
/*   Updated: 2026/11/21 15:55:09 by mjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(va_list *args, char format)
{
	unsigned int	n;

	n = va_arg(*args, unsigned int);
	return (ft_puthex_count(n, format));
}

int	ft_print_pointer(va_list *args)
{
	void	*ptr;

	ptr = va_arg(*args, void *);
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	return (2 + ft_putptr_count((unsigned long)ptr));
}
