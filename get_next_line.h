/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabatu <sabatu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 22:53:07 by sabatu            #+#    #+#             */
/*   Updated: 2023/08/30 15:26:02 by sabatu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_read(int fd, char *left_str);
char	*get_line_a(char *left_str);
char	*get_extract(char *left_str);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen(char *str);
char	*ft_calloc_gnl(char *ptr);
int		my_strchr(char *s, int c);
char	*my_strjoin(char *s1, char *s2);

#endif
