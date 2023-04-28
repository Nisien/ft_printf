/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:48:25 by nrossa            #+#    #+#             */
/*   Updated: 2023/03/08 17:10:09 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_utohex(unsigned int nb, char c)
{
	int	count;

	count = 0;
	if (16 <= nb)
	{
		count += ft_utohex(nb / 16, c);
		count += ft_utohex(nb % 16, c);
	}
	else if (nb <= 9)
		count += ft_putncount_char(nb + 48);
	else if (10 <= nb && nb <= 15)
	{
		if (c == 'X')
			count += ft_putncount_char(nb + 55);
		else if (c == 'x')
			count += ft_putncount_char(nb + 87);
	}
	return (count);
}

int	ft_print_hexa(va_list args, char c)
{
	int				count;
	unsigned int	hexa;

	hexa = va_arg(args, unsigned int);
	count = ft_utohex(hexa, c);
	return (count);
}
