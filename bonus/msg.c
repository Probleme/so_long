/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:22:56 by ataouaf           #+#    #+#             */
/*   Updated: 2023/04/10 18:15:18 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	ft_init_game(t_game *game)
{
	game->width = 0;
	game->height = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->collect = 0;
	game->moves = 0;
	game->current_key = 0;
	game->enm_x = 0;
	game->enm_y = 0;
	game->enm_num = 0;
}

void	msg_out(t_data *data, char c)
{
	if (c == 'q')
		ft_putstr_fd("Quit game            \n", 1);
	else if (data->game->collect == 0 && c == 'e')
	{
		ft_putstr_fd("Congrats! You opened the door in ", 1);
		ft_putnbr_fd(data->game->moves, 1);
		if (data->game->moves == 1)
			ft_putstr_fd(" move\n", 1);
		else
			ft_putstr_fd(" moves\n", 1);
	}
	else if (c == 'N')
		ft_putstr_fd("Oh no! Goblin captured you!\n", 1);
}

void	print_moves(t_data *data)
{
	char	*moves;

	data->game->moves += 1;
	moves = ft_itoa(data->game->moves);
	draw_img("assets/info.xpm", 0, 0, data);
	mlx_string_put(data->mlx_ptr, data->mlx_win, 15, 24, 0x545252, moves);
	free(moves);
	moves = NULL;
}
