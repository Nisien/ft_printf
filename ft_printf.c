/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:39:36 by nrossa            #+#    #+#             */
/*   Updated: 2023/03/19 08:30:38 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_catch_and_dispatch(va_list args, char c)
{
	int	count;

	count = 0;
	if (c == '%')
		count = ft_putncount_char(c);
	else if (c == 'd' || c == 'i')
		count = ft_print_dori(args);
	else if (c == 'c')
		count = ft_print_char(args);
	else if (c == 's')
		count = ft_print_str(args);
	else if (c == 'u')
		count = ft_print_unsigned(args);
	else if (c == 'x')
		count = ft_print_hexa(args, c);
	else if (c == 'X')
		count = ft_print_hexa(args, c);
	else if (c == 'p')
		count = ft_print_aptr(args);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
			count += ft_putncount_char(str[i]);
		else
		{
			i++;
			count += ft_catch_and_dispatch(args, str[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}
