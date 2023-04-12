/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:46:39 by ataouaf           #+#    #+#             */
/*   Updated: 2023/04/05 18:35:45 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_check_chars(t_data *data)
{
	int	height;
	int	width;

	height = 0;
	while (height < data->game->height)
	{
		width = 0;
		while (data->game->map[height][width] != '\n' &&
				data->game->map[height][width] != '\0')
		{
			if (ft_strchr("01CEP", data->game->map[height][width]) == NULL)
				return (0);
			width++;
		}
		height++;
	}
	return (1);
}

int	char_check(t_data *data, char car, int *count)
{
	int	height;
	int	width;

	height = 0;
	*count = 0;
	while (height < data->game->height)
	{
		width = 0;
		while (data->game->map[height][width] != '\0')
		{
			if (data->game->map[height][width] == car)
				*count += 1;
			width += 1;
		}
		height += 1;
	}
	if (car == 'P' && (*count > 1 || *count == 0))
		return (0);
	else if (*count == 0)
		return (0);
	return (1);
}

int	check_every_char(t_data *data)
{
	int	count;

	if (!(ft_check_chars(data)))
		return (INVALID_CHARS);
	if (!(char_check(data, 'P', &count)))
		return (PLAYER_ERROR);
	if (!(char_check(data, 'E', &count)))
		return (EXIT_ERROR);
	if (!(char_check(data, 'C', &count)))
		return (COLLECT_ERROR);
	else
		data->game->collect = count;
	return (VALID);
}

int	ft_open_map(t_data *data)
{
	int		height;
	int		width;
	size_t	len;
	int		res;

	len = ft_strlen_nl(data->game->map[0]);
	height = 0;
	while (height < data->game->height)
	{
		if (len != (ft_strlen_nl(data->game->map[height])))
			return (INVALID_RECT);
		height++;
	}
	data->game->width = (int)len;
	if (!(walls(data, &height, &width, len)))
		return (INVALID_WALLS);
	res = check_every_char(data);
	if (res > 0)
		return (res);
	return (VALID);
}
