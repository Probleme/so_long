/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:52:35 by ataouaf           #+#    #+#             */
/*   Updated: 2023/04/07 13:31:40 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

int	side_walls(t_data *data, int len)
{
	int	height;

	height = 1;
	while (height < data->game->height)
	{
		if (data->game->map[height][0] != '1')
			return (0);
		else if (data->game->map[height][len - 1] != '1')
			return (0);
		height += 1;
	}
	return (1);
}

int	walls(t_data *data, int *height, int *width, int len)
{
	*width = 0;
	while (data->game->map[0][*width] != '\n')
	{
		if (data->game->map[0][*width] != '1')
			return (0);
		*width += 1;
	}
	*width = 0;
	*height = data->game->height - 1;
	while (data->game->map[*height][*width] != '\n' &&
			data->game->map[*height][*width] != '\0')
	{
		if (data->game->map[*height][*width] != '1')
			return (0);
		*width += 1;
	}
	if (!(side_walls(data, len)))
		return (0);
	return (1);
}
