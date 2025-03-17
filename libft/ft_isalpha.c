/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgasco-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:01:16 by dgasco-g          #+#    #+#             */
/*   Updated: 2024/11/25 18:25:07 by dgasco-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int n)
{
	if ((n < 'A' || n > 'Z')
		&& (n < 'a' || n > 'z'))
	{
		return (0);
	}
	return (1);
}
