/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekechedz <ekechedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:30:26 by ekechedz          #+#    #+#             */
/*   Updated: 2024/09/11 18:06:51 by ekechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	move_player(t_data *d, int x, int y)
{
	t_coor	pos_old;

	copy_coor(&d->pdir, &(t_coor){x, y});
	if (d->end_game || d->map[d->ppos.y + y][d->ppos.x + x] == WALL)
		return (0);
	pos_old.x = d->ppos.x;
	pos_old.y = d->ppos.y;
	d->ppos.x += x;
	d->ppos.y += y;
	if (d->map[d->ppos.y][d->ppos.x] == COLLECTIBLE)
	{
		d->map[d->ppos.y][d->ppos.x] = EMPTY;
		d->collected++;
	}
	if (d->map[d->ppos.y][d->ppos.x] == MAPEXIT
					&& d->collected == d->collectibles)
	{
		d->end_game = 1;
		mlx_loop_end(d->mlx);
	}
	draw_tile(d, pos_old);
	draw_tile(d, d->ppos);
	return (1);
}
