/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 23:43:47 by nrossa            #+#    #+#             */
/*   Updated: 2023/04/11 22:10:23 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	ft_isconversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

char	*ft_min_negit(void)
{
	char	*dst;

	dst = ft_itoa(2147483647);
	dst[9] += 1;
	return (dst);
}

int	ft_dori_length(t_flags flags, char *str, int nb)
{
	int	length;

	length = ft_strlen(str);
	if (flags.dot >= 0 && flags.dot >= length && nb >= 0)
		length += flags.dot - length;
	if (flags.dot == 0 && nb == 0)
		length = 0;
	if ((flags.plus || flags.space) && nb >= 0)
		length++;
	return (length);
}

int	ft_flags_length(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && !ft_isconversion(str[i]))
		i++;
	return (i);
}

void	ft_check_flags(t_flags *flags)
{
	char	c;

	c = flags->conversion;
	if (flags->width < 0)
	{
		flags->width *= -1;
		flags->minus = 1;
	}
	if (flags->zero && flags->minus)
		flags->zero = 0;
	if (flags->zero && flags->dot >= 0 && (c == 'd' || c == 'i'
			|| c == 'u' || c == 'x' || c == 'X'))
		flags->zero = 0;
	if (flags->space && flags->plus)
		flags->space = 0;
	if (c == 's' && flags->zero)
		flags->zero = 0;
}
