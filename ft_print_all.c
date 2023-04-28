/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:52:38 by nrossa            #+#    #+#             */
/*   Updated: 2023/03/26 03:19:17 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_unsigned(va_list args)
{
	char			*str;
	int				count;
	unsigned int	nb;

	count = 0;
	nb = va_arg(args, unsigned int);
	str = ft_utoa(nb);
	count = ft_putncount_str(str);
	free(str);
	return (count);
}

int	ft_print_dori(va_list args)
{
	char	*str;
	int		nb;
	int		count;

	count = 0;
	nb = va_arg(args, int);
	str = ft_itoa(nb);
	count = ft_putncount_str(str);
	free(str);
	return (count);
}

int	ft_print_str(va_list args)
{
	char	*str;
	int		count;

	count = 0;
	str = va_arg(args, char *);
	if (!str)
		return (count = ft_putncount_str("(null)"));
	count = ft_putncount_str(str);
	return (count);
}

int	ft_print_char(va_list args)
{
	char	c;
	int		count;

	count = 0;
	c = va_arg(args, int);
	count = ft_putncount_char(c);
	return (count);
}
