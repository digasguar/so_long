/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgasco-g <dgasco-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:35:27 by dgasco-g          #+#    #+#             */
/*   Updated: 2025/02/24 13:05:41 by dgasco-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i++]);
	}
	free(map);
}

int	chek_characters(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'C'
			&& str[i] != 'E' && str[i] != 'P' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	get_rows_and_coluns(t_data *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[i])
	{
		if ((int) ft_strlen(map->map[i]) > j)
			j = ft_strlen(map->map[i]);
		i++;
	}
	if (i > 29 || j > 60)
	{
		ft_printf("Error\nMapa demasiado grande\n");
		return (0);
	}
	map->columns = j;
	map->rows = i;
	return (1);
}

int	check_valid_map(char *map)
{
	if (!ft_strchr(map, 'P'))
		return (0);
	if (ft_strchr(map, 'P') != ft_strrchr(map, 'P'))
		return (0);
	if (!ft_strchr(map, 'E'))
		return (0);
	if (ft_strchr(map, 'E') != ft_strrchr(map, 'E'))
		return (0);
	if (!ft_strchr(map, 'C'))
		return (0);
	return (1);
}

void	get_positions(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->rows_player = i;
				data->col_player = j;
			}
			if (data->map[i][j] == 'E')
			{
				data->rows_exit = i;
				data->col_exit = j;
			}
			j++;
		}
		i++;
	}
}
