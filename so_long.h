/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgasco-g <dgasco-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:02:17 by dgasco-g          #+#    #+#             */
/*   Updated: 2025/03/14 16:49:57 by dgasco-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"

# define WALL "./textures/pared.xpm"
# define COIN "./textures/coin.xpm"
# define EXIT "./textures/puerta.xpm"
# define FLOOR "./textures/suelo.xpm"
# define PLAYER_W "./textures/jake.xpm"

typedef struct s_data
{
	char	**map;
	int		rows;
	int		columns;
	void	*mlx;
	void	*mlx_window;
	int		rows_player;
	int		col_player;
	int		rows_exit;
	int		col_exit;
	char	*player_direc;
	int		coins_num;

	void	*wall;
	void	*floor;
	void	*coins;
	void	*exit;
	void	*player_w;

}	t_data;

void	free_map(char **map);
char	*get_map(int fd);
int		check_floodfill(t_data *map);
void	floodfill(t_data *map, char **map2, int x, int y);
int		check_walls(t_data *map);
int		rectangle(t_data map, int i, int j);
int	get_rows_and_coluns(t_data *map);
int		chek_characters(char *str);
int		check_valid_map(char *map);
void	clean_data(t_data *data);
int		input(int keycode, t_data *data);
void	scam_map(t_data *data);
void	put_img(t_data *data, void *img, int x, int y);
void	get_positions(t_data *data);
void	load_texture(t_data *data);
int		close_game(t_data *data);
void	get_num_of_coins(t_data *data, char *map);
int		checkline(char *map);

#endif
