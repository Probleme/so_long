/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:20:23 by ataouaf           #+#    #+#             */
/*   Updated: 2023/04/12 21:03:47 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_args(char **map)
{
	int y = 0;
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
	// int	i;

	// i = 0;
	// while (i < data->game->height)
	// {
	// 	free(data->game->map[i]);
	// 	i++;
	// }
	// free(data->game->map);
	// data->game->map = NULL;
}

int	ft_exit(t_data *data)
{
	free_map(data);
	free(data->game);
	data->game = NULL;
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	exit(EXIT_SUCCESS);
}
