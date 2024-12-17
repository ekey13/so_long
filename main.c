/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekechedz <ekechedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:23:58 by ekechedz          #+#    #+#             */
/*   Updated: 2024/09/17 15:03:03 by ekechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

static int	handle_error(char *msg, t_data *data)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	if (data->mlx != NULL)
	{
		if (data->window != NULL)
			mlx_destroy_window(data->mlx, data->window);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->map)
		free_map(data->map);
	return (1);
}

static int	initialize_game(t_data *data)
{
	data->mlx = mlx_init();
	data->width = TILE_WIDTH * data->map_width;
	data->height = TILE_HEIGHT * data->map_height;
	data->collected = 0;
	data->end_game = 0;
	if (data->mlx == NULL)
		return (-1);
	data->window = mlx_new_window(data->mlx, data->width, data->height,
			"Custom Game Window Title");
	if (data->window == NULL)
		return (handle_error("Failed to create window", data));
	return (0);
}

static void	setup_event_handlers(t_data *data)
{
	mlx_key_hook(data->window, &handle_input, data);
	mlx_hook(data->window, DestroyNotify, StructureNotifyMask,
		&handle_close, data);
}

static int	validate_input(t_data *data, int argc, char *argv[])
{
	data->mlx = NULL;
	data->window = NULL;
	data->map = NULL;
	data->collectibles = 0;
	data->moves = 0;
	if (argc != 2)
		return (handle_error("Usage: so_long <map_file_name>", data));
	if (read_map(data, argv[1]) < 0)
		return (handle_error("Error reading map file", data));
	if (check_special_tiles(data) < 0)
		return (handle_error("Error with special tiles in map", data));
	if (!is_valid_map(data))
		return (handle_error("Invalid map structure", data));
	if (!is_surrounded_by_walls(data))
		return (handle_error("Map is not surrounded by walls", data));
	if (!is_ber_file(argv[1]))
		return (handle_error("It's need to be .ber file.", data));
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (validate_input(&data, argc, argv))
		return (1);
	if (initialize_game(&data) < 0)
		return (1);
	init_map(&data);
	setup_event_handlers(&data);
	mlx_loop(data.mlx);
	mlx_destroy_window(data.mlx, data.window);
	clear_textures(&data);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
	free_map(data.map);
	return (0);
}
