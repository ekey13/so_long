/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekechedz <ekechedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:24:23 by ekechedz          #+#    #+#             */
/*   Updated: 2024/09/17 12:41:53 by ekechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	put_tile(t_data *data, void *img, t_coor coor)
{
	mlx_put_image_to_window(data->mlx, data->window, img,
		coor.x * TILE_WIDTH, coor.y * TILE_HEIGHT);
}

static void	draw_player(t_data *data, t_coor coor)
{
	if (data->pdir.x == -1)
		put_tile(data, data->textures.player_left, coor);
	else
		put_tile(data, data->textures.player, coor);
}

void	draw_tile(t_data *data, t_coor coor)
{
	if (coor.x == data->ppos.x && coor.y == data->ppos.y)
		draw_player(data, coor);
	else if (data->map[coor.y][coor.x] == WALL)
		put_tile(data, data->textures.wall, coor);
	else if (data->map[coor.y][coor.x] == COLLECTIBLE)
		put_tile(data, data->textures.points, coor);
	else if (data->map[coor.y][coor.x] == MAPEXIT)
		put_tile(data, data->textures.target, coor);
	else
		put_tile(data, data->textures.background, coor);
}

void	init_map(t_data *data)
{
	t_coor	coor;

	data->pdir.x = 0;
	data->pdir.y = 0;
	init_textures(data);
	coor.y = 0;
	while (coor.y < data->map_height)
	{
		coor.x = 0;
		while (coor.x < data->map_width)
		{
			draw_tile(data, coor);
			coor.x++;
		}
		coor.y++;
	}
}
