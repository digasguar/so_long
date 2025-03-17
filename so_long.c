/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgasco-g <dgasco-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:54:14 by dgasco-g          #+#    #+#             */
/*   Updated: 2025/03/03 18:17:50 by dgasco-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "so_long.h"

int	check_extension(char *arg)
{
	char	*extension;

	extension = ft_strrchr(arg, '.');
	if (!extension)
	{
		ft_printf("Error\nArchivo no termina en .ber");
		return (0);
	}
	if (ft_strncmp(extension, ".ber", 5))
	{
		ft_printf("Error\nArchivo no termina en .ber");
		return (0);
	}
	return (1);
}

int	cheks(t_data *data, char *map)
{
	if (!chek_characters(map) || !check_valid_map(map))
	{
		ft_printf("Error\nCaracteres invalidos en el mapa");
		return (0);
	}
	data->map = ft_split(map, '\n');
	if(!get_rows_and_coluns(data))
		return(free_map(data->map), 0);
	if (!check_walls(data))
	{
		ft_printf("Error\nEl mapa no esta cerrado");
		return (free_map(data->map), 0);
	}
	if (!rectangle(*data, 0, 0))
	{
		ft_printf("Error\nEl mapa no es rectangular");
		return (free_map(data->map), 0);
	}
	if (!check_floodfill(data))
		return (ft_printf("Error\nEl mapa no es jugable"),
			free_map(data->map), 0);
	get_num_of_coins(data, map);
	return (1);
}

void	start_game(t_data *data)
{
	data->mlx = mlx_init();
	load_texture(data);
	data->mlx_window = mlx_new_window(data->mlx,
			data->columns * 64, data->rows * 64, "juego");
	scam_map(data);
	mlx_key_hook(data->mlx_window, input, data);
	mlx_hook(data->mlx_window, 17, 0, close_game, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char *argv[])
{
	int		fd;
	t_data	data;
	char	*map;

	if (argc != 2)
		return (1);
	if (!check_extension(argv[1]))
		return (1);
	fd = open(argv[1], 00);
	if (fd == -1)
	{
		ft_printf("Error, archivo no enontrado");
		return (0);
	}
	map = get_map(fd);
	if (!checkline(map))
		return (free(map), 1);
	close(fd);
	if (!cheks(&data, map))
		return (free(map), 0);
	free(map);
	start_game(&data);
	return (0);
}
