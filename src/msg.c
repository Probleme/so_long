/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:22:56 by ataouaf           #+#    #+#             */
/*   Updated: 2023/04/12 17:22:14 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_init_game(t_game *game)
{
	game->width = 0;
	game->height = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->collect = 0;
	game->moves = 0;
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
}

void	print_moves(t_data *data)
{
	ft_putstr_fd("You made ", 1);
	ft_putnbr_fd(data->game->moves, 1);
	if (data->game->moves == 1)
		ft_putstr_fd(" move\r", 1);
	else
		ft_putstr_fd(" moves\r", 1);
}
