/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_anim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:41:21 by ataouaf           #+#    #+#             */
/*   Updated: 2023/04/15 16:42:48 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static void	enemy_y(int y, t_enemy *temp, t_data *data)
{
	if (data->game->map[y][temp->enm_x] == 'C')
	{
		data->game->map[temp->enm_y][temp->enm_x] = '0';
		data->game->map[y][temp->enm_x] = 'N';
		draw_img("textures/key1.xpm", temp->enm_x, temp->enm_y, data);
		draw_img("textures/enemy.xpm", temp->enm_x, y, data);
	}
	else
	{
		data->game->map[temp->enm_y][temp->enm_x] = '0';
		data->game->map[y][temp->enm_x] = 'N';
		draw_img("textures/bg.xpm", temp->enm_x, temp->enm_y, data);
		draw_img("textures/enemy.xpm", temp->enm_x, y, data);
	}
	temp->enm_y = y;
	if (data->game->map[temp->enm_y][temp->enm_x] \
		== data->game->map[data->game->player_y][data->game->player_x])
	{
		msg_out(data, 'N');
		ft_exit(data);
	}
}

static void	enemy_x(int x, t_enemy *temp, t_data *data)
{
	if (data->game->map[temp->enm_y][x] == 'C')
	{
		data->game->map[temp->enm_y][temp->enm_x] = 'C';
		data->game->map[temp->enm_y][x] = 'N';
		draw_img("textures/collect/key1.xpm", temp->enm_x, temp->enm_y, data);
		draw_img("textures/enemy.xpm", x, temp->enm_y, data);
	}
	else if (data->game->map[temp->enm_y][x] == '0')
	{
		data->game->map[temp->enm_y][temp->enm_x] = '0';
		data->game->map[temp->enm_y][x] = 'N';
		draw_img("textures/bg.xpm", temp->enm_x, temp->enm_y, data);
		draw_img("textures/enemy.xpm", x, temp->enm_y, data);
	}
	temp->enm_x = x;
	if (data->game->map[temp->enm_y][temp->enm_x] \
		== data->game->map[data->game->player_y][data->game->player_x])
	{
		msg_out(data, 'N');
		ft_exit(data);
	}
}

static void	set_limit(int *limit, t_data *data)
{
	if (data->game->collect == 0)
		*limit = 30;
	else
		*limit = 4000;
}

void	enemy_anim(t_data *data)
{
	static int	i;
	int			flag;
	int			limit;
	t_enemy		*temp;

	temp = data->enm;
	set_limit(&limit, data);
	i += 1;
	while (temp)
	{
		enemy_dir(temp, data, &flag);
		if (flag == DOWN && i == limit)
			enemy_y(temp->enm_y + 1, temp, data);
		if (flag == UP && i == limit)
			enemy_y(temp->enm_y - 1, temp, data);
		if (flag == RIGHT && i == limit)
			enemy_x(temp->enm_x + 1, temp, data);
		if (flag == LEFT && i == limit)
			enemy_x(temp->enm_x - 1, temp, data);
		temp = temp->next;
	}
	if (i > limit)
		i = 0;
}
