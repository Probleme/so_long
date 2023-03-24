/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:45:45 by ataouaf           #+#    #+#             */
/*   Updated: 2023/03/23 16:56:05 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void    image_bg(t_info *info)
{
    int i;
    int j;

    i = 0;
    while (i < info->si_y)
    {
        j = 0;
        while (j < info->si_x)
        {
            mlx_put_image_to_window(info->mlx_ptr, info->mlx_win, info->img->bg, j, i);
            j += IMG_WIDTH;
        }
        i += IMG_HEIGHT;
    }
}

void    image_player(t_info *info)
{
    info->pl_x = info->map->x;
    info->pl_y = info->map->y;
    mlx_put_image_to_window(info->mlx_ptr, info->mlx_win, info->img->up,
                           (info->pl_x * IMG_WIDTH), (info->pl_y * IMG_HEIGHT));
}

void    image_obj(t_info *info, char *path)
{
    int width;
    int height;
    
    info->map->obj = mlx_xpm_file_to_image(info->mlx_ptr, path, &width, &height);
    mlx_put_image_to_window(info->mlx_ptr, info->mlx_win, info->map->obj, (info->map->x * IMG_WIDTH), (info->map->y * IMG_HEIGHT));
}

int destroy_win(t_info * info)
{
    mlx_destroy_window(info->mlx_ptr, info->mlx_win);
    ft_putendl_fd("You gave up", STDOUT_FILENO);
    exit(0);
}

int key_hook(int key, t_info *info)
{
    if (info->map->map[info->si_y][info->si_x] == 'E')
        game_win(info);
    if (key == ESC)
    {
        ft_putendl_fd("You gave up", STDOUT_FILENO);
        exit(0);
    }
    else if (key == W)
		move_player(info, 'y', UP);
	else if (key == A)
		move_player(info, 'x', LEFT);
	else if (key == S)
		move_player(info, 'y', DOWN);
	else if (key == D)
		move_player(info, 'x', RIGHT);
    return (0);
}
