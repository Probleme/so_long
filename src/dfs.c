/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:31:28 by ataouaf           #+#    #+#             */
/*   Updated: 2023/04/12 21:02:07 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
	{
		dmap[y] = ft_strdup(map[y]);
	}
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

int	player_path(char **map)
{
	int		x;
	int		y;
	char	**dmap;

	y = 0;
	x = x_return(map, &y);
	dmap = duplicate_map(map);
	if (!check_exit(y, x, dmap, map))
		return (INVALID_EXIT);
	else if (!check_collectibles(map))
		return (INVALID_COINS);
	free(dmap);
	return (VALID);
}
