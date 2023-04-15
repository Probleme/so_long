/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:36:40 by ataouaf           #+#    #+#             */
/*   Updated: 2023/04/13 21:35:05 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

size_t	ft_strlen_nl(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\n' && s[i])
		++i;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	if (!s1)
		return (NULL);
	i = 0;
	str = malloc(ft_strlen(s1) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

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
	while (map[y])
	{
		dmap[y] = ft_strdup(map[y]);
		y++;
	}
	dmap[y] = 0;
	return (dmap);
}

void	free_args(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		free(map[y]);
		y++;
	}
	free(map);
	map = NULL;
}

void	free_map(t_data *data)
{
	free_args(data->game->map);
}
