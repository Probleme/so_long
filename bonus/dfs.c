/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:31:28 by ataouaf           #+#    #+#             */
/*   Updated: 2023/04/10 16:47:25 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

char	**duplicate_map(char **map)
{
	int		y;
	char	**dmap;

	y = 0;
	while (map[y])
		y++;
	dmap = malloc(sizeof(char *) * (y + 1));
	if (!dmap)
		return (NULL);
	y = 0;
	while (map[y++])
		dmap[y] = ft_strdup(map[y]);
	dmap[y] = 0;
	return (dmap);
}

static	int	map_path(int y, int x, char **dmap, char **map)
{
	if (map[y][x] == 'P')
		return (1);
	else if (map[y][x] != '1' && dmap[y][x] != '1')
	{
		dmap[y][x] = '1';
		if (map_path(y, x - 1, dmap, map))
			return (1);
		if (map_path(y + 1, x, dmap, map))
			return (1);
		if (map_path(y, x + 1, dmap, map))
			return (1);
		if (map_path(y - 1, x, dmap, map))
			return (1);
	}
	return (0);
}

int	check_collectibles(char **map)
{
	int		x;
	int		y;
	char	**dmap;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][++x])
		{
			if (map[y][x] == 'C')
			{
				dmap = duplicate_map(map);
				if (map_path(y, x, dmap, map))
				{
					return (1);
				}
			}
		}
		y += 1;
	}
	return (0);
}

static	int	check_exit(int y, int x, char **dmap, char **map)
{
	if (map[y][x] == 'E')
		return (1);
	else if (map[y][x] != '1' && dmap[y][x] != '1')
	{
		dmap[y][x] = '1';
		if (check_exit(y, x - 1, dmap, map))
			return (1);
		if (check_exit(y + 1, x, dmap, map))
			return (1);
		if (check_exit(y, x + 1, dmap, map))
			return (1);
		if (check_exit(y - 1, x, dmap, map))
			return (1);
	}
	return (0);
}

void	player_path(t_data *data)
{
	int		x;
	int		y;
	char	**map;
	char	**dmap;

	x = data->game->player_x;
	y = data->game->player_y;
	map = data->game->map;
	dmap = duplicate_map(map);
	if (!check_exit(y, x, dmap, map))
	{
		free_map(data);
		ft_error("Error\nInvalid map there are no way to exit", data);
	}
	else if (!check_collectibles(map))
	{
		free_map(data);
		ft_error("Error\nInvalid map there are no way to collectibles", data);
	}
}
