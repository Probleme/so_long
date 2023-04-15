/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:27:38 by ataouaf           #+#    #+#             */
/*   Updated: 2023/04/15 15:40:30 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static void	push_enemy(t_enemy **first_enemy, t_enemy *new_enemy)
{
	t_enemy	*temp;

	if (*first_enemy == NULL)
		*first_enemy = new_enemy;
	else
	{
		temp = *first_enemy;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_enemy;
	}
}

static t_enemy	*new_enemy(int x, int y)
{
	t_enemy	*new_enemy;

	new_enemy = malloc(sizeof(t_enemy));
	if (!new_enemy)
		return (NULL);
	new_enemy->enm_x = x;
	new_enemy->enm_y = y;
	new_enemy->next = NULL;
	return (new_enemy);
}

t_enemy	*init_enemies(t_data *data)
{
	int		x;
	int		y;
	t_enemy	*enemy;

	y = 0;
	while (y < data->game->height)
	{
		x = 0;
		while (x < data->game->width)
		{
			if (data->game->map[y][x] == 'N')
			{
				enemy = new_enemy(x, y);
				push_enemy(&data->enm, enemy);
				enemy = NULL;
			}
			x += 1;
		}
		y += 1;
	}
	return (data->enm);
}
