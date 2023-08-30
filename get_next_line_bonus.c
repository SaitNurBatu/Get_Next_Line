/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabatu <sabatu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:03:41 by sabatu            #+#    #+#             */
/*   Updated: 2023/08/30 17:09:05 by sabatu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	x;
	size_t	i;

	x = ft_strlen(s);
	if (start >= x)
		return (0);
	if (len > x - start)
		len = x - start;
	s2 = malloc((len + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s2[i] = s[start + i];
		i++;
	}
	if (!s)
		free(s);
	s2[i] = '\0';
	return (s2);
}

char	*ft_read(int fd, char *left_str)
{
	char	*buffer;
	int		x;

	x = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	while (x > 0 && !my_strchr(left_str, '\n'))
	{
		x = read(fd, buffer, BUFFER_SIZE);
		if (x == -1)
		{
			free(buffer);
			free(left_str);
			return (NULL);
		}
		buffer[x] = '\0';
		left_str = my_strjoin(left_str, buffer);
	}
	free(buffer);
	return (left_str);
}

char	*get_line_a(char *left_str)
{
	char	*new;
	int		i;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (left_str[i] == '\n')
		i++;
	new = ft_substr(left_str, 0, i);
	return (new);
}

char	*get_extract(char *left_str)
{
	char	*last_str;
	int		i;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	i++;
	last_str = ft_substr(left_str, i, ft_strlen(left_str) - i);
	free(left_str);
	return (last_str);
}

char	*get_next_line(int fd)
{
	static char	*left_str[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left_str[fd] = ft_read(fd, left_str[fd]);
	if (!left_str[fd])
		return (NULL);
	line = get_line_a(left_str[fd]);
	left_str[fd] = get_extract(left_str[fd]);
	return (line);
}
