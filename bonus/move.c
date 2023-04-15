/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:45:58 by ataouaf           #+#    #+#             */
/*   Updated: 2023/04/15 16:42:48 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static void	move_player(int x, int y, t_data *data)
{
	print_moves(data);
	if (data->game->current_key == UP)
		draw_img("textures/pl/up.xpm", x, y, data);
	else if (data->game->current_key == LEFT)
		draw_img("textures/pl/left.xpm", x, y, data);
	else if (data->game->current_key == DOWN)
		draw_img("textures/pl/down.xpm", x, y, data);
	else
		draw_img("textures/pl/right.xpm", x, y, data);
}

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
			data->game->i = 0;
			move_player(x, y, data);
		}
		else
		{
			draw_img("textures/bg.xpm", data->game->player_x,
				data->game->player_y, data);
			move_player(x, y, data);
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
		move_player(x, y, data);
		data->game->map[y][x] = '0';
		data->game->collect -= 1;
	}
	else
	{
		draw_img("textures/bg.xpm", data->game->player_x,
			data->game->player_y, data);
		draw_img("textures/bg.xpm", x, y, data);
		move_player(x, y, data);
		data->game->map[y][x] = '0';
		data->game->collect -= 1;
	}
}

static void	move_enemy(t_data *data)
{
	msg_out(data, 'N');
	ft_exit(data);
}

void	move(t_data *data, int x, int y)
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
	else if (data->game->map[y][x] == 'N')
		move_enemy(data);
	data->game->player_x = x;
	data->game->player_y = y;
}
