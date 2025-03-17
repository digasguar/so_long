/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgasco-g <dgasco-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:45:48 by dgasco-g          #+#    #+#             */
/*   Updated: 2025/02/23 18:43:39 by dgasco-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_num_of_coins(t_data *data, char *map)
{
	int	i;

	i = 0;
	data->coins_num = 0;
	while (map[i] != '\0')
	{
		if (map[i] == 'C')
			data->coins_num++;
		i++;
	}
}

void	free_img(t_data *data)
{
	mlx_destroy_image(data->mlx, data->floor);
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->coins);
	mlx_destroy_image(data->mlx, data->exit);
	mlx_destroy_image(data->mlx, data->player_w);
}

void	clean_data(t_data *data)
{
	free_img(data);
	if (data->map)
		free_map(data->map);
	if (data->mlx && data->mlx_window)
		mlx_destroy_window(data->mlx, data->mlx_window);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
}

int	checkline(char *map)
{
	int	i;

	i = 0;
	while (map[i + 1] != '\0')
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			return (ft_printf("Error\nSaltos de linea seguidos"), 0);
		}
		i++;
	}
	return (1);
}

int	close_game(t_data *data)
{
	clean_data(data);
	exit(0);
	return (0);
}
