/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekechedz <ekechedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:07:07 by ekechedz          #+#    #+#             */
/*   Updated: 2024/09/11 18:07:47 by ekechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	copy_coor(t_coor *c1, t_coor *c2)
{
	c1->x = c2->x;
	c1->y = c2->y;
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*p;

	if (dest == NULL && src == NULL)
		return (dest);
	i = 0;
	p = dest;
	while (i < n)
	{
		*(p + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dest);
}
