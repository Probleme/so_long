/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:20:23 by ataouaf           #+#    #+#             */
/*   Updated: 2023/04/12 17:30:40 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	free_dmap(char **map)
{
	while (*map)
	{
		free(*map);
		map++;
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

void	ft_delete_list(t_enemy **head)
{
	t_enemy	*next;

	if (*head != NULL)
	{
		while (*head != NULL)
		{
			next = (*head)->next;
			free(*head);
			*head = NULL;
			*head = next;
		}
	}
	free(*head);
	*head = NULL;
}

void	free_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->game->height)
	{
		free(data->game->map[i]);
		i++;
	}
	free(data->game->map);
	data->game->map = NULL;
}

int	ft_exit(t_data *data)
{
	free_map(data);
	// if (data->enm != NULL)
	// 	ft_delete_list(&data->enm);
	free(data->game);
	data->game = NULL;
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	exit(EXIT_SUCCESS);
}

