/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekechedz <ekechedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:13:39 by ekechedz          #+#    #+#             */
/*   Updated: 2024/09/17 14:59:35 by ekechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	check_horizontal_walls(t_data *data, int x, int y)
{
	if (x >= data->map_width)
		return (1);
	if (data->map[y][x] != WALL)
		return (0);
	return (check_horizontal_walls(data, x + 1, y));
}

static int	check_vertical_walls(t_data *data, int x, int y)
{
	if (y >= data->map_height)
		return (1);
	if (data->map[y][x] != WALL)
		return (0);
	return (check_vertical_walls(data, x, y + 1));
}

int	is_surrounded_by_walls(t_data *data)
{
	if (!check_horizontal_walls(data, 0, 0)
		|| !check_horizontal_walls(data, 0, data->map_height - 1))
		return (0);
	if (!check_vertical_walls(data, 0, 0)
		|| !check_vertical_walls(data, data->map_width - 1, 0))
		return (0);
	return (1);
}

int	is_ber_file(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len > 4 && ft_strcmp(filename + len - 4, ".ber") == 0)
		return (1);
	return (0);
}
