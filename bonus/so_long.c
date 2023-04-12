/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:58:12 by ataouaf           #+#    #+#             */
/*   Updated: 2023/04/12 17:35:43 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

int	check_args(char *ptr)
{
	char	*search;

	search = NULL;
	search = ft_strchr(ptr, '.');
	if (search == NULL)
		return (0);
	if ((ft_strcmp(".ber", search)) == 0)
		return (1);
	return (0);
}

void	ft_get_liine(t_data *data, char *file)
{
	int		fd;
	char	*line;

	line = NULL;
	data->game->height = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Error\nFile openning", data);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		data->game->height += 1;
		free(line);
		line = NULL;
	}
	close(fd);
}


void	open_map(t_data *data, char *file)
{
	int		fd;
	char	*line;
	int		height;

	line = NULL;
	height = data->game->height;
	data->game->map = malloc(sizeof(char *) * (height + 1));
	if (!data->game->map)
		ft_error("Error\nMemory malloc", data);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Error\nFile openning", data);
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		data->game->map[height] = ft_strdup(line);
		height++;
		free(line);
		line = NULL;
	}
	data->game->map[height] = 0;
	close(fd);
}

int	init_game(t_data *data, char *ptr)
{
	int		i;

	ft_get_liine(data, ptr);
	if (data->game->height == 0)
		ft_error("Error\nMap Empty", data);
	data->game->moves = 0;
	open_map(data, ptr);
	i = ft_open_map(data);
	if (i > 0)
		ft_error_display(data, i);
	return (0);
}

void	leak()
{
	system("leaks so_long_bonus");
}

int main(int argc, char **argv)
{
	atexit(leak);
	t_data	data;

	if (argc != 2)
		ft_error("Error\nTry ./so_long maps.ber", &data);
	if (!check_args(argv[1]))
		ft_error("Error\nInvalid extension file", &data);
	data.game = malloc(sizeof(t_game));
	if (data.game == NULL)
		ft_error("Error\nAllocation failed", &data);
	ft_init_game(data.game);
	init_game(&data, argv[1]);
	open_map(&data, argv[1]);
	ft_mlx(&data);
	ft_exit(&data);
	return (0);
}
