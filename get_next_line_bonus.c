/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 06:17:11 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/28 17:53:48 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include<stdlib.h>
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <unistd.h>

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

char	*read_join(int fd, char *str, int *k)
{
	char	*ptr;

	*k = 1;
	ptr = malloc(BUFFER_SIZE + 1);
	if (ptr == NULL)
		return (0);
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
	static char	*str[OPEN_MAX];
	int			k;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	str[fd] = read_join(fd, str[fd], &k);
	if (str[fd] == NULL || (ft_strlen(str[fd]) == 0 && k == 0))
	{
		if (str[fd] == NULL)
			return (0);
		free(str[fd]);
		str[fd] = NULL;
		return (0);
	}
	if (check_fun(str[fd]) == -1)
	{
		line = str[fd];
		str[fd] = (NULL);
		return (line);
	}
	line = ft_substr(str[fd], 0, check_fun(str[fd]) + 1);
	str[fd] = line_remainder(str[fd], check_fun(str[fd]));
	return (line);
}
