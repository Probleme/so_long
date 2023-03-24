/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:45:48 by ataouaf           #+#    #+#             */
/*   Updated: 2023/03/21 23:07:01 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void    move_player_direc(t_info *info, int direc, char posi)
{
	if (posi == 'y' && direc == UP)
	{
		mlx_put_image_to_window(info->mlx_ptr, info->mlx_win, info->img->up,
			(info->si_x * IMG_WIDTH), (info->si_y * IMG_HEIGHT));
	}
	if (posi == 'x' && direc == LEFT)
	{
		mlx_put_image_to_window(info->mlx_ptr, info->mlx_win, info->img->left,
			(info->si_x * IMG_WIDTH), (info->si_y * IMG_HEIGHT));
	}
	if (posi == 'y' && direc == DOWN)
	{
		mlx_put_image_to_window(info->mlx_ptr, info->mlx_win, info->img->down,
			(info->si_x * IMG_WIDTH), (info->si_y * IMG_HEIGHT));
	}
	if (posi == 'x' && direc == RIGHT)
	{
		mlx_put_image_to_window(info->mlx_ptr, info->mlx_win, info->img->right,
			(info->si_x * IMG_WIDTH), (info->si_y * IMG_HEIGHT));
	}
}

void    collected(t_info *info, int direc, char posi)
{
	info->coins++;
	info->map->map[info->si_y][info->si_x] = '\0';
	mlx_put_image_to_window(info->mlx_ptr, info->mlx_win, info->img->bg,
		(info->si_x * IMG_WIDTH), (info->si_y * IMG_HEIGHT));
	move_player_direc(info, direc, posi);
}

void    move_player(t_info *info, int direc, char posi)
{
	mlx_put_image_to_window(info->mlx_ptr, info->mlx_win, info->img->bg,
		(info->si_x * IMG_WIDTH), (info->si_y * IMG_HEIGHT));
	if (posi == 'x' && info->map->map[info->si_y + 1 * direc][info->si_x] != '1'
		&& (info->map->map[info->si_y + 1 * direc][info->si_x] != 'E'
		|| info->coins == info->map->collect))
		info->si_y = info->si_y + 1 * direc;
	else if (posi == 'x' && info->map->map[info->si_y][info->si_x + 1 * direc] != '1'
		&& (info->map->map[info->si_y][info->si_x + 1 * direc] != 'E'
		|| info->coins == info->map->collect))
		info->si_x = info->si_x + 1 * direc;
	else if (posi == 'y' && info->map->map[info->si_y + 1 * direc][info->si_x] == 'E'
		&& info->coins != info->map->collect)
		ft_putendl_fd("Collect all diamonds before leaving", 1);
	else if (posi == 'x' && info->map->map[info->si_y][info->si_x + 1 * direc] == 'E'
		&& info->coins != info->map->collect)
		ft_putendl_fd("Collect all objects before leaving", 1);
	move_player_direc(info, direc, posi);
	if (info->map->map[info->si_y][info->si_x] == 'C')
		collected(info, direc, posi);
	mlx_do_sync(info->mlx_ptr);
	printf("You moved %d times\n", ++info->count);
}
