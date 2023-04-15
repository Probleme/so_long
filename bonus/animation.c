/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:36:44 by ataouaf           #+#    #+#             */
/*   Updated: 2023/04/15 16:42:48 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static void	key_rotation(int i, int w, int h, t_data *data)
{
	if (i == 0)
		draw_img("textures/collect/key1.xpm", w, h, data);
	else if (i == 2500)
		draw_img("textures/collect/key2.xpm", w, h, data);
	else if (i == 4500)
		draw_img("textures/collect/key3.xpm", w, h, data);
	else if (i == 6500)
		draw_img("textures/collect/key4.xpm", w, h, data);
	else if (i == 8500)
		draw_img("textures/collect/key5.xpm", w, h, data);
	else if (i == 10500)
		draw_img("textures/collect/key6.xpm", w, h, data);
	else if (i == 12500)
		draw_img("textures/collect/key1.xpm", w, h, data);
}

static void	collect_animation(t_data *data)
{
	static int	i;
	int			h;
	int			w;

	h = 0;
	while (h < data->game->height)
	{
		w = 0;
		while (w < data->game->width)
		{
			if (data->game->map[h][w] == 'C')
				key_rotation(i, w, h, data);
			w += 1;
		}
		h += 1;
	}
	i += 1;
	if (i > 12500)
		i = 0;
}

static void	open_door(t_data *data)
{
	int	h;
	int	w;

	h = 0;
	while (h < data->game->height)
	{
		w = 0;
		while (w < data->game->width)
		{
			if (data->game->map[h][w] == 'E')
				draw_img("textures/door_open.xpm", w, h, data);
			w++;
		}
		h++;
	}
}

int	animation(t_data *data)
{
	collect_animation(data);
	enemy_anim(data);
	if (data->game->collect == 0)
		open_door(data);
	return (0);
}
