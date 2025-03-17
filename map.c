/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgasco-g <dgasco-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:58:04 by dgasco-g          #+#    #+#             */
/*   Updated: 2025/02/27 21:43:29 by dgasco-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "so_long.h"

int	rectangle(t_data map, int i, int j)
{
	while (j < map.columns)
	{
		i = 0;
		while (i < map.rows)
		{
			if (map.map[i] == NULL || map.map[i++][j] == '\0')
				return (0);
		}
		j++;
	}
	i = 0;
	while (i < map.rows)
	{
		j = 0;
		while (j < map.columns)
		{
			if (map.map[i] == NULL || map.map[i][j++] == '\0')
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_walls(t_data *map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map->map[i][j] != '\0')
	{
		if (map->map[i][j++] != '1')
			return (0);
	}
	j = 0;
	while (map->map[map->rows - 1][j])
	{
		if (map->map[map->rows - 1][j] != '1')
			return (0);
		j++;
	}
	while (i < map->rows - 1)
	{
		if (map->map[i][0] != '1' || map->map[i][map->columns - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	floodfill(t_data *map, char **map2, int x, int y)
{
	if (map2[x][y] == '1' || map2[x][y] == 'x')
		return ;
	map2[x][y] = 'x';
	floodfill(map, map2, x + 1, y);
	floodfill(map, map2, x - 1, y);
	floodfill(map, map2, x, y + 1);
	floodfill(map, map2, x, y - 1);
}

int	check_floodfill(t_data *data)
{
	char	**map2;
	int		i;
	int		j;

	get_positions(data);
	i = -1;
	if (!check_walls(data))
		return (0);
	map2 = malloc(sizeof(char *) * (data->rows + 1));
	while (data->map[++i])
		map2[i] = ft_strdup(data->map[i]);
	map2[i] = NULL;
	i = 0;
	floodfill(data, map2, data->rows_player, data->col_player);
	while (map2[i])
	{
		j = 0;
		while (map2[i][j++])
		{
			if (map2[i][j] == 'E' || map2[i][j] == 'C')
				return (free_map(map2), 0);
		}
		i++;
	}
	return (free_map(map2), 1);
}

char	*get_map(int fd)
{
	int		bytes_read;
	char	buffer[2];
	char	*map;

	map = malloc(1);
	map[0] = '\0';
	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buffer, 1);
		buffer[bytes_read] = '\0';
		if (bytes_read == -1)
			return (NULL);
		map = ft_strjoin(map, buffer);
		if (!map)
			return (NULL);
	}
	return (map);
}
