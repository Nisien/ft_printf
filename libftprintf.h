/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:40:07 by nrossa            #+#    #+#             */
/*   Updated: 2023/03/19 09:11:20 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

char	*ft_utoa(unsigned int n);
int		ft_printf(const char *str, ...);
int		ft_print_char(va_list args);
int		ft_print_str(va_list args);
int		ft_print_dori(va_list args);
int		ft_print_unsigned(va_list args);
int		ft_print_hexa(va_list args, char c);
int		ft_print_aptr(va_list args);
int		ft_putncount_char(char c);
int		ft_putncount_str(char *s);

#endif
