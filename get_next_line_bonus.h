#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
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
