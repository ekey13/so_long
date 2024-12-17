/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handalers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekechedz <ekechedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:41:12 by ekechedz          #+#    #+#             */
/*   Updated: 2024/09/17 14:48:28 by ekechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	num_len(int num)
{
	int	len;

	len = 0;
	if (num <= 0)
		len++;
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	num;

	len = num_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	num = n;
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (num)
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

int	handle_close(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}

void	print_moves(int moves)
{
	char	*move_str;

	move_str = ft_itoa(moves);
	if (move_str)
	{
		write(STDOUT_FILENO, "Number of moves: ", 17);
		write(STDOUT_FILENO, move_str, ft_strlen(move_str));
		write(STDOUT_FILENO, "\n", 1);
		free(move_str);
	}
}

int	handle_input(int keycode, t_data *data)
{
	int		moved;

	moved = 0;
	if (keycode == XK_Escape)
		mlx_loop_end(data->mlx);
	if (keycode == XK_w || keycode == XK_W || keycode == XK_Up)
		moved = move_player(data, 0, -1);
	else if (keycode == XK_s || keycode == XK_S || keycode == XK_Down)
		moved = move_player(data, 0, 1);
	else if (keycode == XK_a || keycode == XK_A || keycode == XK_Left)
		moved = move_player(data, -1, 0);
	else if (keycode == XK_d || keycode == XK_D || keycode == XK_Right)
		moved = move_player(data, 1, 0);
	if (moved)
	{
		data->moves++;
		print_moves(data->moves);
	}
	return (0);
}
