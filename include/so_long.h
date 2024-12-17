/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekechedz <ekechedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:01:22 by ekechedz          #+#    #+#             */
/*   Updated: 2024/09/17 15:00:38 by ekechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "/home/ekechedz/minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "X11/Xlib.h"
# include "X11/keysym.h"
# include "../get_next_line/get_next_line.h"

# define TILE_WIDTH 64
# define TILE_HEIGHT 64
# define END_TILE_WIDTH 380
# define END_TILE_HEIGHT 160

# define EMPTY 48
# define WALL 49
# define COLLECTIBLE 67
# define MAPEXIT 69
# define PSTART 80
# define VISITED 2

typedef struct s_coor
{
	int	x;
	int	y;
}	t_coor;

typedef struct s_tilecount
{
	int	pstarts;
	int	exits;
}	t_tilecount;

typedef struct s_textures
{
	void	*background;
	void	*player;
	void	*player_dead;
	void	*wall;
	void	*target;
	void	*player_left;
	void	*points;
}	t_textures;

typedef struct s_data
{
	void		*mlx;
	void		*window;
	int			width;
	int			height;
	int			map_width;
	int			map_height;
	char		**map;
	int			collectibles;
	int			collected;
	long		end_game;
	int			dummy;
	int			moves;
	t_textures	textures;
	t_coor		ppos;
	t_coor		pdir;
}	t_data;

void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
void	free_map(char **map);
void	copy_coor(t_coor *c1, t_coor *c2);
int		handle_close(t_data *data);
int		handle_input(int keycode, t_data *data);
void	init_map(t_data *data);
int		move_player(t_data *data, int x, int y);
void	draw_tile(t_data *data, t_coor coor);
int		read_map(t_data *data, char *fname);
int		is_valid_map(t_data *data);
int		check_special_tiles(t_data *data);
void	init_textures(t_data *data);
void	clear_textures(t_data *data);
void	ft_putendl_fd(char *s, int fd);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*get_next_line(int fd);
char	*get_next_line(int fd);
int		is_surrounded_by_walls(t_data *data);
int		is_path_valid(t_data *data);
int		is_ber_file(char *filename);

#endif
