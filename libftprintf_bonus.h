/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:40:07 by nrossa            #+#    #+#             */
/*   Updated: 2023/03/26 04:25:03 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_BONUS_H
# define LIBFTPRINTF_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_flags
{
	char	conversion;
	int		minus;
	int		zero;
	int		dot;
	int		width;
	int		hash;
	int		space;
	int		plus;
}	t_flags;

char	*ft_utoa(unsigned int n);
char	*ft_min_negit(void);
int		ft_printf(const char *str, ...);
int		ft_print_char(va_list args, t_flags flags);
int		ft_print_str(va_list args, t_flags flags);
int		ft_print_dori(va_list args, t_flags flags);
int		ft_print_unsigned(va_list args, t_flags flags);
int		ft_print_hexa(va_list args, t_flags flags);
int		ft_print_aptr(va_list args, t_flags flags);
int		ft_putncount_char(char c);
int		ft_putncount_str(char *s);
int		ft_isconversion(char c);
int		ft_flags_length(const char *str);
int		ft_print_space(t_flags flags, int length);
int		ft_print_zero(t_flags flags, int length, char option);
int		ft_print_flags(t_flags flags, int length);
int		ft_print_hash(t_flags flags, unsigned int hexa);
int		ft_print_mors(t_flags flags, int nb);
int		ft_dori_length(t_flags flags, char *str, int nb);
void	ft_check_flags(t_flags *flags);

#endif
