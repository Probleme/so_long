/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:58:33 by ataouaf           #+#    #+#             */
/*   Updated: 2023/03/22 00:07:45 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
char	*ft_read_and_save(int fd, char *save);
char	*ft_save(char *save);
char	*ft_get_line(char *save);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin_gnl(char *s1, char *s2);

# define IMG_WIDTH 164
# define IMG_HEIGHT 164
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1


typedef struct s_map
{
	char	**map;
	char	*obj;
	int		x;
	int		y;
	int		collect;
}			t_map;

typedef struct s_image
{
	void	*up;
	void	*down;
	void	*left;
	void	*right;
	void	*bg;
}				t_image;

typedef struct s_info
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		count;
	int		coins;
	int		si_x;
	int		si_y;
	int		pl_x;
	int		pl_y;
	t_map	*map;
	t_image	*img;
}			t_info;

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t	ft_strlen(const char *s);
void	ft_error(char *msg);
char	*ft_strjoin(char *s1, char *s2);
void	open_map(t_info *info, char **argv);
int		lenght_line(int fd);
int		lines_counter(int fd, int i, int width);
void    image_bg(t_info *info);
void    image_player(t_info *info);
void    image_obj(t_info *info, char *path);
void	ft_putendl_fd(char *s, int fd);
int		destroy_win(t_info * info);
void	game_win(t_info *info);
void    move_player(t_info *info, int direc, char posi);
int		key_hook(int key, t_info *info);

#endif