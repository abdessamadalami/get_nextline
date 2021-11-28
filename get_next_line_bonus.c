/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 06:17:11 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/28 06:17:15 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include <unistd.h>
#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
#include<stdlib.h>
#include"get_next_line.h"

char	*ft_strdup(char *src)
{
	char	*ptr;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(src);
	ptr = malloc((len + 1) * sizeof (char));
	if (ptr == NULL)
		return (0);
	while (src[i] != '\0')
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	check_fun(char *s)
{
	int	index;

	if (!s)
		return (-1);
	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}

char	*line_remainder(char *src, int startindex)
{
	char	*tmp;
	char	*line;

	tmp = src;
	line = ft_strdup(src + startindex + 1);
	free(tmp);
	return (line);
}
//-fsanitize=address -g

char	*read_join(int fd, char *str, int *k)
{
	char	*ptr;

	*k = 1;
	ptr = malloc(BUFFER_SIZE + 1);
	while (check_fun(str) == -1 && *k != 0)
	{
		*k = read(fd, ptr, BUFFER_SIZE);
		if (*k == -1)
		{
			free(ptr);
			return (NULL);
		}
		ptr[*k] = '\0';
		str = ft_strjoin(str, ptr);
	}
	free(ptr);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	int			k;
	char		*line;
	int			index_line;

	str[fd] = read_join(fd, str[fd], &k);
	if (str[fd] == NULL)
		return (0);
	if (ft_strlen(str[fd]) == 0 && k == 0)
	{
		free(str[fd]);
		str[fd] = NULL;
		return (0);
	}
	index_line = check_fun(str[fd]);
	if (index_line == -1)
	{
		line = str[fd];
		str[fd] = (NULL);
		return (line);
	}
	line = ft_substr(str[fd], 0, index_line + 1);
	str[fd] = line_remainder(str[fd], index_line);
	return (line);
}

// //printf("line {%s} ptr <%s> str <%s>", line, ptr,str);

// int main()
// {

//  //int fd = open("nl", O_RDWR);
//  int fd = open("text.txt", O_RDWR);
//  int f = open("text1.txt",O_RDWR);
//  char *c;
// //  char *line;
// //  line = malloc(BUFFER_SIZE);
// //  int k = read(fd, line, BUFFER_SIZE);
// // printf(" %d ",k);
// int index = 0;
//  printf("%s", get_next_line(fd));
//  printf("%s", get_next_line(f));
//  printf("%s", get_next_line(fd));
//  printf("%s", get_next_line(f));
//  close(fd);
//  //system("leaks a.out");
// }
