/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validating.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekechedz <ekechedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:08:37 by ekechedz          #+#    #+#             */
/*   Updated: 2024/09/11 18:27:41 by ekechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	chk_tile(t_data *data, int x, int y, char **is_checked)
{
	int	result;

	if (is_checked[y][x] == 1)
		return (0);
	if (data->map[y][x] == WALL)
		return (0);
	if (x == 0 || x == data->map_width - 1
		|| y == 0 || y == data->map_height - 1)
		return (-1);
	result = 0;
	if (data->map[y][x] == COLLECTIBLE)
		result++;
	is_checked[y][x] = 1;
	return (
		result
		+ chk_tile(data, x + 1, y, is_checked)
		+ chk_tile(data, x - 1, y, is_checked)
		+ chk_tile(data, x, y + 1, is_checked)
		+ chk_tile(data, x, y - 1, is_checked)
	);
}

int	is_valid_map(t_data *data)
{
	char	**is_checked;
	int		i;

	is_checked = ft_calloc(data->map_height + 1, sizeof(char *));
	i = 0;
	while (i < data->map_height)
		is_checked[i++] = ft_calloc(data->map_width, sizeof(char));
	i = chk_tile(data, data->ppos.x, data->ppos.y, is_checked);
	free_map(is_checked);
	if (i != data->collectibles)
		return (0);
	if (!is_path_valid(data))
		return (0);
	return (1);
}

void	check_special_tile(t_data *data, t_coor *coor, t_tilecount *tc)
{
	if (data->map[coor->y][coor->x] == PSTART)
	{
		(tc->pstarts)++;
		data->ppos.x = coor->x;
		data->ppos.y = coor->y;
	}
	else if (data->map[coor->y][coor->x] == MAPEXIT)
		(tc->exits)++;
	else if (data->map[coor->y][coor->x] == COLLECTIBLE)
		data->collectibles++;
}

int	check_special_tiles(t_data *data)
{
	t_coor		coor;
	t_tilecount	tc;

	coor.y = -1;
	tc.exits = 0;
	tc.pstarts = 0;
	while (++(coor.y) < data->map_height)
	{
		coor.x = -1;
		while (++(coor.x) < data->map_width)
			check_special_tile(data, &coor, &tc);
	}
	if (tc.pstarts != 1 || tc.exits != 1)
		return (-1);
	return (0);
}
