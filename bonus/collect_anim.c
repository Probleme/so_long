/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_anim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:07:45 by ataouaf           #+#    #+#             */
/*   Updated: 2023/04/12 13:50:10 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static void	ft_g_key_rotation(int i, int w, int h, t_data *data)
{
	if (i == 0)
		draw_img("assets/collect/key1.xpm", w, h, data);
	else if (i == 2500)
		draw_img("assets/collect/key2.xpm", w, h, data);
	else if (i == 4500)
		draw_img("assets/collect/key3.xpm", w, h, data);
	else if (i == 6500)
		draw_img("assets/collect/key4.xpm", w, h, data);
	else if (i == 8500)
		draw_img("assets/collect/key5.xpm", w, h, data);
	else if (i == 10500)
		draw_img("assets/collect/key6.xpm", w, h, data);
	else if (i == 12500)
		draw_img("assets/collect/key1.xpm", w, h, data);
}

static void	ft_anim_g_key(t_data *data)
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
				ft_g_key_rotation(i, w, h, data);
			w += 1;
		}
		h += 1;
	}
	i += 1;
	if (i > 12500)
		i = 0;
}

void	ft_collect_animation(t_data *data)
{
	ft_anim_g_key(data);
}
