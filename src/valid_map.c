/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekechedz <ekechedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:24:57 by ekechedz          #+#    #+#             */
/*   Updated: 2024/09/17 14:48:07 by ekechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	is_valid_move(t_data *data, int x, int y, char **visited)
{
	return (x >= 0 && x < data->map_width
		&& y >= 0 && y < data->map_height
		&& data->map[y][x] != WALL
		&& visited[y][x] != VISITED);
}

static int	dfs_path_exists(t_data *data, int x, int y, char **visited)
{
	if (data->map[y][x] == MAPEXIT)
		return (1);
	if (!is_valid_move(data, x, y, visited))
		return (0);
	visited[y][x] = VISITED;
	return (dfs_path_exists(data, x + 1, y, visited)
		|| dfs_path_exists(data, x - 1, y, visited)
		|| dfs_path_exists(data, x, y + 1, visited)
		|| dfs_path_exists(data, x, y - 1, visited));
}

static char	**allocate_visited_array(int map_height, int map_width)
{
	char	**visited;
	int		y;
	int		free_index;

	visited = (char **)malloc(map_height * sizeof(char *));
	if (!visited)
		return (NULL);
	y = 0;
	while (y < map_height)
	{
		visited[y] = (char *)calloc(map_width, sizeof(char));
		if (!visited[y])
		{
			free_index = 0;
			while (free_index < y)
				free(visited[free_index++]);
			free(visited);
			return (NULL);
		}
		y++;
	}
	return (visited);
}

static void	free_visited_array(char **visited, int map_height)
{
	int	y;

	y = 0;
	while (y < map_height)
	{
		free(visited[y]);
		y++;
	}
	free(visited);
}

int	is_path_valid(t_data *data)
{
	char	**visited;
	int		path_exists;

	visited = allocate_visited_array(data->map_height, data->map_width);
	if (!visited)
		return (0);
	path_exists = dfs_path_exists(data, data->ppos.x, data->ppos.y, visited);
	free_visited_array(visited, data->map_height);
	return (path_exists);
}
