/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjaafar <mjaafar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 14:04:54 by mjaafar           #+#    #+#             */
/*   Updated: 2026/11/21 14:05:00 by mjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_count(unsigned long n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_putptr_count(n / 16);
	write(1, &"0123456789abcdef"[n % 16], 1);
	count++;
	return (count);
}
