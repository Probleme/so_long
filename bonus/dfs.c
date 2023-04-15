/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:31:28 by ataouaf           #+#    #+#             */
/*   Updated: 2023/04/14 20:47:40 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

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

	dmap = NULL;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][++x])
		{
			if (map[y][x] == 'C')
			{
				dmap = duplicate_map(map);
				if (!map_path(y, x, dmap, map))
				{
					free_args(dmap);
					return (0);
				}
				free_args(dmap);
			}
		}
		y += 1;
	}
	return (1);
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

static	int	x_return(char **map, int *y)
{
	int	x;

	while (map[*y])
	{
		x = 0;
		while (map[*y][x])
		{
			if (map[*y][x] == 'P')
				return (x);
			x++;
		}	
		*y += 1;
	}
	return (x);
}

int	dfs(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	x = x_return(data->game->map, &y);
	data->game->dmap = duplicate_map(data->game->map);
	if (!check_exit(y, x, data->game->dmap, data->game->map))
	{
		free_args(data->game->dmap);
		return (INVALID_EXIT);
	}
	else if (!check_collectibles(data->game->map))
	{
		free_args(data->game->dmap);
		return (INVALID_COINS);
	}
	free_args(data->game->dmap);
	free_args(data->game->map);
	return (VALID);
}
