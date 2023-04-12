/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:36:44 by ataouaf           #+#    #+#             */
/*   Updated: 2023/04/11 16:47:23 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static void	ft_open_door(t_data *data)
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
			{
				draw_img("assets/door_open.xpm", w, h, data);
			}
			w++;
		}
		h++;
	}
}

int	ft_animation(t_data *data)
{
	ft_collect_animation(data);
	ft_villain_anim(data);
	if (data->game->collect == 0)
		ft_open_door(data);
	return (0);
}
