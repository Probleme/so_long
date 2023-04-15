/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:13:41 by ataouaf           #+#    #+#             */
/*   Updated: 2023/04/15 16:15:11 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static void	assign_key(int key, t_data *data)
{
	if (key == W || key == UP)
		data->game->current_key = UP;
	else if (key == A || key == LEFT)
		data->game->current_key = LEFT;
	else if (key == S || key == DOWN)
		data->game->current_key = DOWN;
	else if (key == D || key == RIGHT)
		data->game->current_key = RIGHT;
}

static int	key(int key, t_data *data)
{
	int	x;
	int	y;

	assign_key(key, data);
	x = data->game->player_x;
	y = data->game->player_y;
	data->game->map[y][x] = '0';
	if (key == ESC || key == Q)
	{
		msg_out(data, 'q');
		ft_exit(data);
	}
	else if (key == W || key == UP)
		move(data, x, y - 1);
	else if (key == S || key == DOWN)
		move(data, x, y + 1);
	else if (key == A || key == LEFT)
		move(data, x - 1, y);
	else if (key == D || key == RIGHT)
		move(data, x + 1, y);
	return (0);
}

void	mlx(t_data *data)
{
	int	height_win;
	int	width_win;

	height_win = data->game->height;
	width_win = data->game->width;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		error_free("Error\nMlx Init\n", data);
	data->mlx_win = mlx_new_window(data->mlx_ptr,
			width_win * 50, height_win * 50, "./so_long");
	if (!data->mlx_win)
		error_free("Error\nMlx Window", data);
	if (data->game->enm_num > 0)
		data->enm = init_enemies(data);
	draw(data);
	mlx_hook(data->mlx_win, 02, (1L << 0), key, data);
	mlx_loop_hook(data->mlx_ptr, animation, data);
	mlx_hook(data->mlx_win, 17, 0, ft_exit, data);
	mlx_loop(data->mlx_ptr);
}
