/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:36:40 by ataouaf           #+#    #+#             */
/*   Updated: 2023/03/21 23:48:50 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (haystack == 0 && len == 0)
		return (0);
	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (haystack[i + j] == needle[j] && i + j < len)
			{
				if (needle[j + 1] == '\0')
					return ((char *) &haystack[i]);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	s1 = NULL;
	return (str);
}

int	lenght_line(int fd)
{
	int	i;
	int	readed;
	char	buff[1];

	i = 0;
	buff[0] = '\0';
	readed = 1;
	while (readed == 1)
	{
		readed = read(fd, buff, 1);
		if (buff[0] != '\n')
			i++;
		else
			break ;
	}
	return (i);
}

int	lines_counter(int fd, int i, int width)
{
	int		count;
	char	*line;

	count = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if ((int)ft_strlen(line) < i / width || (ft_strlen(line) == 1 && *line != '\n'))
		{
			free(line);
			ft_error("Error\nInvalid map wrong diensions");
		}
		else
		{
			free(line);
			count++;
		}
	}
	return (count);
}
