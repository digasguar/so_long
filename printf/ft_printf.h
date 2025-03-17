/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgasco-g <dgasco-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:04:59 by dgasco-g          #+#    #+#             */
/*   Updated: 2025/01/13 21:04:59 by dgasco-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	print_hex(unsigned long str, int i);
int	print_char(char c);
int	print_str(char *str);
int	print_nbr(int nbr);
int	print_nbr_2(unsigned int nbr);
int	printf_p(char *a);
int	ft_printf(const char *input, ...);
#endif