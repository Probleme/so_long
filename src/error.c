/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:20:23 by ataouaf           #+#    #+#             */
/*   Updated: 2023/04/15 16:26:35 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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

void	ft_error(char *msg, t_data *data)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	free(data->game);
	data->game = NULL;
	exit(1);
}

void	free_map(t_data *data)
{
	free_args(data->game->map);
}

void	error_free(char *error, t_data *data)
{
	free_map(data);
	ft_putendl_fd(error, STDERR_FILENO);
	exit(1);
}

void	error_display(t_data *data, int num)
{
	if (num == INVALID_RECT)
		error_free("Error\nMap is not rectangular", data);
	else if (num == INVALID_WALLS)
		error_free("Error\nInvalid walls", data);
	else if (num == INVALID_CHARS)
		error_free("Error\nMap has invalid characters", data);
	else if (num == PLAYER_ERROR)
		error_free("Error\n Only 1 Player", data);
	else if (num == EXIT_ERROR)
		error_free("Error\nMap has no exit", data);
	else if (num == COLLECT_ERROR)
		error_free("Error\nMap has no collectibles", data);
	else if (num == INVALID_COINS)
		error_free("Error\nMap Invalid no way to collectible", data);
	else if (num == INVALID_EXIT)
		error_free("Error\nMap Invalid no way to exit\n", data);
}
