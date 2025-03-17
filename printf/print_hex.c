/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgasco-g <dgasco-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:01:32 by dgasco-g          #+#    #+#             */
/*   Updated: 2025/01/13 21:11:40 by dgasco-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned long str, int i)
{
	int	len;

	len = 0;
	if (str >= 16)
		len += print_hex(str / 16, i);
	str = str % 16;
	if (str < 10)
		len += print_char(str + 48);
	else if (i == 0)
		len += print_char(str + 87);
	else if (i == 1)
		len += print_char(str + 55);
	return (len);
}
