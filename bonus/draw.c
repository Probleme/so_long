/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:19:22 by ataouaf           #+#    #+#             */
/*   Updated: 2023/04/12 13:50:55 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	draw_img(char *img, int x, int y, t_data *data)
{
	int	width;
	int	height;

	x *= 50;
	y *= 50;
	data->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, img, &width, &height);
	if (!data->mlx_img)
		ft_error_free("Error\nMlx image not found\n", data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->mlx_img, x, y);
	mlx_destroy_image(data->mlx_ptr, data->mlx_img);
}

void	draw_map(int x, int y, char car, t_data *data)
{
	if (car == '0')
		draw_img("assets/bg.xpm", x, y, data);
	else if (car == '1')
	{
		if (x == 0 || y == 0 || y == data->game->height - 1 || x == data->game->width -1)
			draw_img("assets/wall.xpm", x, y, data);
		else
			draw_img("assets/barrel.xpm", x, y, data);
	}
	else if (car == 'C')
		draw_img("assets/collect/key1.xpm", x, y, data);
	else if (car == 'P')
	{
		data->game->player_x = x;
		data->game->player_y = y;
		draw_img("assets/player.xpm", x, y, data);
	}
	else if (car == 'E')
		draw_img("assets/door_closed.xpm", x, y, data);
	else if (car == 'N')
		draw_img("assets/enemy.xpm", x, y, data);
}

void	draw_background(t_data *data)
{
	int	width;
	int	height;

	height = 0;
	while (height < data->game->height)
	{
		width = 0;
		while (width < data->game->width)
		{
			draw_img("assets/bg.xpm", width, height, data);
			width++;
		}
		height++;
	}
}

void	draw(t_data *data)
{
	int		x;
	int		y;
	char	car;

	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	draw_background(data);
	y = 0;
	while (y < data->game->height)
	{
		x = 0;
		while (x < data->game->width)
		{
			car = data->game->map[y][x];
			draw_map(x, y, car, data);
			x++;
		}
		y++;
	}
}
