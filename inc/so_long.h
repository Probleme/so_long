/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:58:33 by ataouaf           #+#    #+#             */
/*   Updated: 2023/04/12 20:39:39 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <mlx.h>
#include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
char	*ft_read_and_save(int fd, char *save);
char	*ft_save(char *save);
char	*ft_get_line(char *save);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin_gnl(char *s1, char *s2);

# define WIDTH_WIN 1240
# define HEIGHT_WIN 600

# define A		0
# define S		1
# define D		2
# define Q		12
# define W		13
# define SPACE	49
# define ESC	53
# define LEFT	123
# define RIGHT	124
# define DOWN	125
# define UP		126

# define VALID			0
# define INVALID_RECT	3 
# define INVALID_WALLS	4
# define INVALID_CHARS	5
# define PLAYER_ERROR	6
# define EXIT_ERROR		7
# define COLLECT_ERROR	8
# define INVALID_EXIT	9
# define INVALID_COINS	10

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		moves;
	int		collect;
	int		i;
}			t_game;

typedef struct s_data {
	void		*mlx_ptr;
	void		*mlx_win;
	void		*mlx_img;
	t_game		*game;
}				t_data;

void	free_map(t_data *data);
size_t	ft_strlen_nl(char *s);
void	ft_error_display(t_data *data, int i);
void	ft_error_free(char *error, t_data *data);
int		walls(t_data *data, int *height, int *width, int len);
int		ft_open_map(t_data *data);
void	open_map(t_data *data, char *file);
char	*ft_strdup(char *s1);
size_t	ft_strlen(const char *s);
void	ft_error(char *msg, t_data *data);
int		ft_exit(t_data *data);
void	draw(t_data *data);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void    ft_putchar_fd(char c, int fd);
void	print_moves(t_data *data);
void	msg_out(t_data *data, char c);
void	draw_img(char *img, int x, int y, t_data *data);
void	ft_mlx(t_data *data);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putendl_fd(char *s, int fd);
int		player_path(char **map);
void	dfs(t_data *data);
void	init_map(t_data *data, int fd, int height, char *file);
void	free_args(char **map);
void	ft_init_game(t_game *game);
#endif