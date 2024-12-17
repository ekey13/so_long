/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekechedz <ekechedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:44:54 by ekechedz          #+#    #+#             */
/*   Updated: 2024/09/11 17:46:16 by ekechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	handel_error(int fd, void *str, char **map)
{
	if (fd != 1)
		close(fd);
	if (str != NULL)
		free(str);
	if (map)
		free_map(map);
	return (-1);
}

int	is_valid(char *line, int width)
{
	int	len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
	{
		line[len - 1] = '\0';
		len--;
	}
	if (len != width)
		return (0);
	while (*line)
	{
		if (*line != EMPTY
			&& *line != WALL
			&& *line != COLLECTIBLE
			&& *line != MAPEXIT
			&& *line != PSTART)
			return (0);
		line++;
	}
	return (1);
}

int	get_map_dimensions(int fd, t_data *data)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (-1);
	data->map_width = ft_strlen(line);
	if (line[data->map_width - 1] == '\n')
		data->map_width--;
	data->map_height = 0;
	while (line)
	{
		if (!is_valid(line, data->map_width))
			return (handel_error(-1, line, NULL));
		data->map_height++;
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

int	read_map(t_data *data, char *fname)
{
	int		fd;
	int		i;

	fd = open(fname, O_RDONLY);
	if (fd == -1)
		return (-1);
	if (get_map_dimensions(fd, data) < 0)
		return (handel_error(fd, NULL, NULL));
	data->map = ft_calloc(data->map_height + 1, sizeof(char *));
	close(fd);
	fd = open(fname, O_RDONLY);
	if (fd == -1)
		return (-1);
	i = -1;
	while (++i < data->map_height)
	{
		data->map[i] = get_next_line(fd);
		data->map[i][data->map_width] = '\0';
		if (!data->map[i])
			return (handel_error(fd, NULL, data->map));
	}
	get_next_line(fd);
	close(fd);
	return (0);
}
