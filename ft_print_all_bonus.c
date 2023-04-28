/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_all_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:52:38 by nrossa            #+#    #+#             */
/*   Updated: 2023/04/11 22:30:11 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	ft_print_negid(int nb, t_flags flags)
{
	char	*str;
	int		count;
	int		length;

	count = 0;
	if (nb == -2147483648)
		str = ft_min_negit();
	else
		str = ft_itoa(nb * -1);
	length = ft_dori_length(flags, str, nb * -1) + 1;
	if (flags.plus || flags.space)
		length--;
	if (flags.width && !flags.minus && !flags.zero)
		count += ft_print_space(flags, length);
	count += ft_putncount_char('-');
	if (flags.width && flags.zero)
		count += ft_print_zero(flags, length, 'z');
	if (flags.dot >= 0)
		if (nb != 0 || flags.dot != 0)
			count += ft_print_zero(flags, ft_strlen(str), 'd');
	count += ft_putncount_str(str);
	if (flags.width && flags.minus)
		count += ft_print_space(flags, length);
	free(str);
	return (count);
}

int	ft_print_dori(va_list args, t_flags flags)
{
	char	*str;
	int		nb;
	int		count;
	int		length;

	count = 0;
	nb = va_arg(args, int);
	if (nb < 0)
		return (ft_print_negid(nb, flags));
	str = ft_itoa(nb);
	length = ft_dori_length(flags, str, nb);
	if (flags.width && !flags.minus && !flags.zero)
		count += ft_print_space(flags, length);
	count += ft_print_mors(flags, nb);
	if (flags.width && flags.zero)
		count += ft_print_zero(flags, length, 'z');
	if (flags.dot >= 0)
		if (nb != 0 || flags.dot != 0)
			count += ft_print_zero(flags, ft_strlen(str), 'd');
	if (nb != 0 || flags.dot != 0)
		count += ft_putncount_str(str);
	if (flags.width && flags.minus)
		count += ft_print_space(flags, length);
	free(str);
	return (count);
}

int	ft_print_unsigned(va_list args, t_flags flags)
{
	char			*str;
	int				count;
	int				length;
	unsigned int	nb;

	count = 0;
	nb = va_arg(args, unsigned int);
	str = ft_utoa(nb);
	length = ft_strlen(str);
	if (flags.dot >= 0 && flags.dot >= length)
		length += flags.dot - length;
	if (flags.dot == 0 && nb == 0)
		length = 0;
	count += ft_print_flags(flags, length);
	if (flags.dot >= 0)
		if (nb != 0 || flags.dot != 0)
			count += ft_print_zero(flags, ft_strlen(str), 'd');
	if (nb != 0 || flags.dot != 0)
		count += ft_putncount_str(str);
	if (flags.width && flags.minus)
		count += ft_print_space(flags, length);
	free(str);
	return (count);
}

int	ft_print_str(va_list args, t_flags flags)
{
	char	*str;
	int		i;
	int		count;
	int		length;

	i = -1;
	count = 0;
	length = 0;
	str = va_arg(args, char *);
	if (!str)
		return (count = ft_putncount_str("(null)"));
	if (flags.dot >= 0)
		while (length < flags.dot && str[length])
			length++;
	else
		length = ft_strlen(str);
	count += ft_print_flags(flags, length);
	if (flags.dot >= 0)
		while (++i < length)
			count += ft_putncount_char(str[i]);
	else
		count += ft_putncount_str(str);
	if (flags.width && flags.minus)
		count += ft_print_space(flags, length);
	return (count);
}

int	ft_print_char(va_list args, t_flags flags)
{
	char	c;
	int		count;

	count = 0;
	c = va_arg(args, int);
	if (flags.width && !flags.minus)
		count += ft_print_space(flags, 1);
	count += ft_putncount_char(c);
	if (flags.width && flags.minus)
		count += ft_print_space(flags, 1);
	return (count);
}
