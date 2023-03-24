/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:58:12 by ataouaf           #+#    #+#             */
/*   Updated: 2023/03/23 17:01:04 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_window(int argc, char **argv, t_info *info)
{
	int	fd;

	if (argc != 2)
		ft_error("Invalid args.\n Try ./so_long maps/map.ber");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("Error\nInvalid map path");
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		ft_error("Error\nthe file not .ber");
	info->si_x = (lenght_line(fd) * IMG_WIDTH);
	info->si_y = (lines_counter(fd, info->si_x, IMG_WIDTH) * IMG_HEIGHT);
}

void	init_img(t_info *info, t_map *map)
{
	t_image	*img;
	int		width;
	int		height;
	char	*path;

	info->map = map;
	img = malloc(sizeof(t_image));
	if (!img)
		ft_error("Error\nallocation failled");
	info->img = img;
	path = "/sprites/bg.xpm";
	info->img->bg = mlx_xpm_file_to_image(info->mlx_ptr, path, &width, &height);
	path = "/sprites/up.xpm";
	info->img->up = mlx_xpm_file_to_image(info->mlx_ptr, path, &width, &height);
	path = "/sprites/down.xpm";
	info->img->down = mlx_xpm_file_to_image(info->mlx_ptr, path, &width, &height);
	path = "/sprites/left.xpm";
	info->img->left = mlx_xpm_file_to_image(info->mlx_ptr, path, &width, &height);
	path = "/sprites/right.xpm";
	info->img->right = mlx_xpm_file_to_image(info->mlx_ptr, path, &width, &height);
	info->count = 0;
	info->coins = 0;
}

void	new_map(t_info *info)
{
	info->map->x = 0;
	info->map->y = 0;
	while (info->map->y < (info->si_y / IMG_HEIGHT))
	{
		if (info->map->map[info->map->y][info->map->x] == 'P')
			image_player(info);
		puts("111111");
		 if (info->map->map[info->map->y][info->map->x] == 'C')
			image_obj(info, "./sprites/collectable.xpm");
		else if (info->map->map[info->map->y][info->map->x] == 'E')
			image_obj(info, "./sprites/exit.xpm");
		else if (info->map->map[info->map->y][info->map->x] == '1')
			image_obj(info, "./sprites/wall.xpm");
		if (info->map->x < (info->si_x / IMG_WIDTH))
			info->map->x++;
		else
		{
			info->map->y++;
			info->map->x = 0;
		}
		
	}
}

int	mouse_keyboard(t_info *info)
{
	image_bg(info);
	new_map(info);
	mlx_hook(info->mlx_ptr, 17, 1L << 2, destroy_win,info);
	mlx_key_hook(info->mlx_win, key_hook, info);
	return (0);
}

int main(int argc, char **argv)
{
	t_info	info;
	t_map	map;

	check_window(argc, argv, &info);
	map.map = malloc(info.si_y + 1 * sizeof(char *));
	if (!map.map)
		ft_error("Error\nallocation failed");
	init_img(&info, &map);
	open_map(&info, argv);
	info.mlx_ptr = mlx_init();
	if (!info.mlx_ptr)
		ft_error("Error\nmlx init failed");
	info.mlx_win = mlx_new_window(info.mlx_ptr, info.si_x, info.si_y, "so_long");
	mouse_keyboard(&info);
	mlx_loop(info.mlx_ptr);
	ft_error("Error\nmlx loop fail");
}
