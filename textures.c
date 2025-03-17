/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgasco-g <dgasco-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 02:33:31 by dgasco-g          #+#    #+#             */
/*   Updated: 2025/02/27 21:52:04 by dgasco-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_window, img, x, y);
}

void	load_img(t_data *data, char c, int x, int y)
{
	if (c == '1')
		put_img(data, data->wall, x, y);
	else if (c == '0')
		put_img(data, data->floor, x, y);
	else if (c == 'C')
		put_img(data, data->coins, x, y);
	else if (c == 'P')
		put_img(data, data->player_w, x, y);
	else if (c == 'E')
		put_img(data, data->exit, x, y);
}

void	load_texture(t_data *data)
{
	int		w;
	int		h;

	data->player_w = mlx_xpm_file_to_image(data->mlx, PLAYER_W, &w, &h);
	if(!data->player_w)
		ft_printf("patata\n");
	data->wall = mlx_xpm_file_to_image(data->mlx, WALL, &w, &h);
	data->floor = mlx_xpm_file_to_image(data->mlx, FLOOR, &w, &h);
	data->coins = mlx_xpm_file_to_image(data->mlx, COIN, &w, &h);
	data->exit = mlx_xpm_file_to_image(data->mlx, EXIT, &w, &h);
}

void	scam_map(t_data *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (data->map[i])
	{
		x = 0;
		j = 0;
		while (data->map[i][j])
		{
			load_img(data, data->map[i][j], x, y);
			x += 64;
			j++;
		}
		y += 64;
		i++;
	}
}
