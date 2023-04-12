/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:36:40 by ataouaf           #+#    #+#             */
/*   Updated: 2023/04/12 14:32:02 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

size_t	ft_strlen_nl(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\n' && s[i])
		++i;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	if (!s1)
		return (NULL);
	i = 0;
	str = malloc(ft_strlen(s1) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}


void	ft_error_free(char *error, t_data *data)
{
	free_map(data);
	ft_putstr_fd(error, STDERR_FILENO);
	exit(1);
}

void	ft_error_display(t_data *data, int num)
{
	if (num == INVALID_RECT)
		ft_error_free("Error\nMap is not rectangular\n", data);
	else if (num == INVALID_WALLS)
		ft_error_free("Error\nInvalid walls\n", data);
	else if (num == INVALID_CHARS)
		ft_error_free("Error\nMap has invalid characters\n", data);
	else if (num == PLAYER_ERROR)
		ft_error_free("Error\n Only 1 Player\n", data);
	else if (num == EXIT_ERROR)
		ft_error_free("Error\nMap has no exit\n", data);
	else if (num == COLLECT_ERROR)
		ft_error_free("Error\nMap has no collectibles\n", data);
}
