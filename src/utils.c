/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:36:40 by ataouaf           #+#    #+#             */
/*   Updated: 2023/04/14 16:30:37 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

size_t	ft_strlen_nl(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\n' && s[i])
		++i;
	return (i);
}

char	*ft_strdup(char *s1)
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

	dmap = NULL;
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

int	ft_exit(t_data *data)
{
	free_map(data);
	free(data->game);
	data->game = NULL;
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	exit(EXIT_SUCCESS);
}
