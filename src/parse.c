/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:33:50 by ataouaf           #+#    #+#             */
/*   Updated: 2023/03/23 13:01:14 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	counter_obj(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!str)
		return (1);
	while (str && str[i])
	{
		if (str[i++] == c)
			j++;
	}
	return (j);
}

void	check_info(t_info *info)
{
	int	player;
	int	end;
	int	i;

	i = 0;
	player = 0;
	end = 0;
	info->map->collect = 0;
	while (info->map->map && info->map->map[i])
	{
		end += counter_obj(info->map->map[i], 'E');
		player += counter_obj(info->map->map[i], 'P');
		info->map->collect += counter_obj(info->map->map[i], 'C');
		i++;
	}
	if (player != 1)
		ft_error("Error\nInvalid map. There are more than one Player");
	if (end == 0)
		ft_error("Error\nInvalid map. There is no exit");
	if (info->map->collect == 0)
		ft_error("Error\nInvalid map. The map must contains at least one collectable");
}

void	check_map(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < (info->si_y / IMG_HEIGHT))
	{
		if ((int)ft_strlen(info->map->map[i]) != info->si_x / IMG_WIDTH)
			ft_error("Error\nMap not rectangular");
		j = 0;
		while (j < (info->si_x / IMG_WIDTH))
		{
			if (info->map->map[i][j] != '1' && info->map->map[i][i] != '0' &&
				info->map->map[i][j] != 'C' && info->map->map[i][j] != 'P' &&
				info->map->map[i][j] != 'E')
				ft_error("Error\nInvalid map file at '1' '0' 'C' 'E' 'P' ");
			else if (((info->si_y / IMG_HEIGHT - 1) == i 
					|| (info->si_x / IMG_WIDTH - 1) == j)
					&& info->map->map[i][j] != '1')
				ft_error("Error\nInvalid map has to be surrounded by walls1");
			else if (info->map->map[i][j] != '1' && (i == 0 || j == 0))
				ft_error("Error\nInvalid map has to be surrounded by walls");
			j++;
		}
		i++;
	}
}

void	open_map(t_info *info, char **argv)
{
	int		fd;
	int		readed;
	int		i;
	char	buff[2];

	i = 0;
	readed = 1;
	buff[1] = '\0';
	fd = open(argv[1], O_RDONLY);
	while (readed == 1)
	{
		readed = read(fd, buff, 1);
		if (readed != 1)
			break ;
		if (buff[0] != '\n' && buff[0] != '\0')
			info->map->map[i] = ft_strjoin(info->map->map[i], buff);
		else
			i++;
	}
	check_info(info);
	check_map(info);
}
