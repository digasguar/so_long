/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgasco-g <dgasco-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 23:17:18 by dgasco-g          #+#    #+#             */
/*   Updated: 2025/02/23 18:23:07 by dgasco-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_move(t_data *data, char c)
{
	if (c == '1')
		return (0);
	if (c == 'E' && data->coins_num == 0)
		close_game(data);
	if (c == 'C')
		data->coins_num--;
	return (1);
}

int	valid_movement(t_data *data, char direction)
{
	int	x;
	int	y;

	x = data->rows_player;
	y = data->col_player;
	if (direction == 'W')
	{
		return (check_move(data, data->map[x - 1][y]));
	}
	else if (direction == 'A')
	{
		return (check_move(data, data->map[x][y - 1]));
	}
	else if (direction == 'S')
	{
		return (check_move(data, data->map[x + 1][y]));
	}
	else if (direction == 'D')
	{
		return (check_move(data, data->map[x][y + 1]));
	}
	return (0);
}

void	check_exit_pos(t_data *data)
{
	if (data->rows_player == data->rows_exit
		&& data->col_exit == data->col_player)
		data->map[data->rows_player][data->col_player] = 'E';
	else
		data->map[data->rows_player][data->col_player] = '0';
}

int	move(t_data *data, char c)
{
	static int	movements;

	if (!valid_movement(data, c))
		return (0);
	if (!movements)
		movements = 0;
	check_exit_pos(data);
	if (c == 'W')
		data->rows_player--;
	else if (c == 'S')
		data->rows_player++;
	else if (c == 'A')
		data->col_player--;
	else if (c == 'D')
		data->col_player++;
	data->map[data->rows_player][data->col_player] = 'P';
	scam_map(data);
	movements++;
	ft_printf("Movimientos: %i\n", movements);
	return (0);
}

int	input(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		close_game(data);
	else if (keycode == XK_w)
		move(data, 'W');
	else if (keycode == XK_s)
		move(data, 'S');
	else if (keycode == XK_a)
		move(data, 'A');
	else if (keycode == XK_d)
		move(data, 'D');
	return (0);
}
