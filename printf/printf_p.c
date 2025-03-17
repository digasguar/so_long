/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgasco-g <dgasco-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:07:31 by dgasco-g          #+#    #+#             */
/*   Updated: 2025/02/17 18:03:38 by dgasco-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_p(char *a)
{
	int	len;

	len = 2;
	if (!a)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	len += print_hex((unsigned long)a, 0);
	return (len);
}
