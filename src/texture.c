/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekechedz <ekechedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:01:19 by ekechedz          #+#    #+#             */
/*   Updated: 2024/09/17 14:44:42 by ekechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:12:34 by wpepping          #+#    #+#             */
/*   Updated: 2024/08/18 17:01:02 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_textures(t_data *data)
{
	data->textures.wall = mlx_xpm_file_to_image(data->mlx,
			"./textures/wall.xpm", &data->dummy, &data->dummy);
	data->textures.background = mlx_xpm_file_to_image(data->mlx,
			"./textures/background.xpm", &data->dummy, &data->dummy);
	data->textures.target = mlx_xpm_file_to_image(data->mlx,
			"./textures/exit.xpm", &data->dummy, &data->dummy);
	data->textures.player = mlx_xpm_file_to_image(data->mlx,
			"./textures/player_small.xpm", &data->dummy, &data->dummy);
	data->textures.player_left = mlx_xpm_file_to_image(data->mlx,
			"./textures/player_left.xpm", &data->dummy, &data->dummy);
	data->textures.points = mlx_xpm_file_to_image(data->mlx,
			"./textures/collect.xpm", &data->dummy, &data->dummy);
}

void	clear_textures(t_data *data)
{
	mlx_destroy_image(data->mlx, data->textures.background);
	mlx_destroy_image(data->mlx, data->textures.player);
	mlx_destroy_image(data->mlx, data->textures.player_left);
	mlx_destroy_image(data->mlx, data->textures.wall);
	mlx_destroy_image(data->mlx, data->textures.points);
	mlx_destroy_image(data->mlx, data->textures.target);
}
