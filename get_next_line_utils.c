/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabatu <sabatu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:06:02 by sabatu            #+#    #+#             */
/*   Updated: 2023/08/30 15:32:04 by sabatu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_calloc_gnl(char *ptr)
{
	if (!ptr)
	{
		ptr = malloc(1);
		if (!ptr)
			return (NULL);
		ptr[0] = '\0';
	}
	return (ptr);
}

int	my_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*my_strjoin(char *s1, char *s2)
{
	char	*stotal;
	size_t	x;
	size_t	a;
	size_t	b;

	b = 0;
	a = -1;
	s1 = ft_calloc_gnl(s1);
	x = ft_strlen(s1) + ft_strlen(s2) + 1;
	stotal = malloc(x * sizeof(char));
	if (!stotal)
		return (NULL);
	while (s1[b])
	{
		stotal[b] = s1[b];
		b++;
	}
	while (s2[++a])
	{
		stotal[b] = s2[a];
		b++;
	}
	stotal[b] = '\0';
	free(s1);
	return (stotal);
}
