/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:47:00 by ataouaf           #+#    #+#             */
/*   Updated: 2023/04/12 14:18:32 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static void	ft_up_down(t_enemy *temp, t_data *data, int *flag)
{
	int		pos_x;
	int		pos_y;
	int		mid_h;
	int		mid_w;

	mid_h = data->game->height / 2;
	mid_w = data->game->width / 2;
	pos_y = data->game->player_y;
	pos_x = data->game->player_x;
	if ((data->game->map[temp->enm_y + 1][temp->enm_x] == '0' \
		|| data->game->map[temp->enm_y + 1][temp->enm_x] == 'C') \
		&& (pos_y > mid_h || temp->enm_y <= pos_y))
		*flag = DOWN;
	else if ((data->game->map[temp->enm_y - 1][temp->enm_x] == '0' \
		|| data->game->map[temp->enm_y - 1][temp->enm_x] == 'C') \
		&& (pos_y <= mid_h || temp->enm_y > pos_y))
		*flag = UP;
}

static void	ft_left_right(t_enemy *temp, t_data *data, int *flag)
{
	int		pos_x;
	int		pos_y;
	int		mid_h;
	int		mid_w;

	mid_h = data->game->height / 2;
	mid_w = data->game->width / 2;
	pos_y = data->game->player_y;
	pos_x = data->game->player_x;
	if ((data->game->map[temp->enm_y][temp->enm_x - 1] == '0' \
		|| data->game->map[temp->enm_y][temp->enm_x - 1] == 'C') \
		&& (pos_x < mid_w || temp->enm_x > pos_x))
		*flag = LEFT;
	else if ((data->game->map[temp->enm_y][temp->enm_x + 1] == '0' \
		|| data->game->map[temp->enm_y][temp->enm_x + 1] == 'C') \
		&& (pos_x >= mid_w || temp->enm_x < pos_x))
		*flag = RIGHT;
}

void	ft_check_villain_dir(t_enemy *temp, t_data *data, int *flag)
{
	*flag = 0;
	ft_up_down(temp, data, flag);
	ft_left_right(temp, data, flag);
}
