/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:13:41 by ataouaf           #+#    #+#             */
/*   Updated: 2023/04/15 16:42:48 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	move_next(t_data *data, int x, int y)
{
	if (data->game->map[y][x] == '0')
	{
		if (data->game->i == 1)
		{
			draw_img("textures/bg.xpm", data->game->player_x,
				data->game->player_y, data);
			draw_img("textures/door_closed.xpm", data->game->player_x,
				data->game->player_y, data);
			data->game->map[data->game->player_y][data->game->player_x] = 'E';
			draw_img("textures/player.xpm", x, y, data);
			data->game->i = 0;
		}
		else
		{
			draw_img("textures/bg.xpm", data->game->player_x,
				data->game->player_y, data);
			draw_img("textures/player.xpm", x, y, data);
		}
	}
	return ;
}

static void	move_collect(int x, int y, t_data *data)
{
	if (data->game->i == 1)
	{
		draw_img("textures/bg.xpm", data->game->player_x,
			data->game->player_y, data);
		draw_img("textures/door_closed.xpm", data->game->player_x,
			data->game->player_y, data);
		data->game->map[data->game->player_y][data->game->player_x] = 'E';
		draw_img("textures/player.xpm", x, y, data);
		data->game->map[y][x] = '0';
		data->game->collect -= 1;
	}
	else
	{
		draw_img("textures/bg.xpm", data->game->player_x,
			data->game->player_y, data);
		draw_img("textures/player.xpm", x, y, data);
		data->game->map[y][x] = '0';
		data->game->collect -= 1;
	}
}

static void	move(t_data *data, int x, int y)
{
	move_next(data, x, y);
	if (data->game->map[y][x] == '1')
		return ;
	else if (data->game->map[y][x] == 'E' && data->game->collect == 0)
	{
		msg_out(data, 'e');
		ft_exit(data);
	}
	else if (data->game->map[y][x] == 'E' && data->game->collect != 0)
	{
		draw_img("textures/bg.xpm", data->game->player_x,
			data->game->player_y, data);
		draw_img("textures/pl/player.xpm", x, y, data);
		data->game->i = 1;
	}
	else if (data->game->map[y][x] == 'C')
		move_collect(x, y, data);
	data->game->player_x = x;
	data->game->player_y = y;
	data->game->moves += 1;
	print_moves(data);
}

static int	key(int key, t_data *data)
{
	int	x;
	int	y;

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
	else if (key == A || key == LEFT)
		move(data, x - 1, y);
	else if (key == S || key == DOWN)
		move(data, x, y + 1);
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
	draw(data);
	mlx_hook(data->mlx_win, 02, (1L << 0), key, data);
	mlx_hook(data->mlx_win, 17, 0, ft_exit, data);
	mlx_loop(data->mlx_ptr);
}
