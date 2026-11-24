/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjaafar <mjaafar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 15:19:42 by mjaafar           #+#    #+#             */
/*   Updated: 2026/11/23 15:23:35 by mjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putnbr_count(int n);
int	ft_putunsigned_count(unsigned int n);
int	ft_puthex_count(unsigned int n, char format);
int	ft_putptr_count(unsigned long n);
int	ft_handle_conversion(char format, va_list *args);
int	ft_print_hex(va_list *args, char format);
int	ft_print_pointer(va_list *args);
int	ft_process_format(const char *format, va_list *args);

#endif