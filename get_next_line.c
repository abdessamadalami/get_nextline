/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+
 *                                                #+#+#+   +#+           */
/*   Created: 2021/11/18 08:10:04 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/18 09:18:31 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include <unistd.h>
#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
#include<stdlib.h>
#define BUFFER_SIZE 300
#include"get_next_line.h"

int	check_fun(char *s)
{
	int index;

	index = 0;
	while (s[index] != '\0')
	{
		if(s[index] == '\n')
			return (0);
		index++;
	}
	return (1);
}

int check_back_s(char *s)
{
	int index;

	index = 0;
	while (s[index] != '\0')
	{
		if(s[index] == '\n')
			return (index);
		index++;
	}
	return (0);
}

char	*d_line(char *line)
{
	int		i;
	char	*str;

	i = check_back_s(line);
	if(line[i + 1] != '\0')
		str = ft_strdup(line + i + 1);
	else
		str = 0;
	line[i + 1] = 0;
	return (str);
}

char	*get_next_line(int fd)
{
	char		*ptr;
	char		*line;
	static char	*str;
	ssize_t		k;

	if(BUFFER_SIZE <= 0)
		return (0);
	line = malloc(BUFFER_SIZE);
	if (str != NULL)
		line = ft_strjoin(line, str);
	while (check_fun(line) && k != 0)
	{
		ptr = malloc(BUFFER_SIZE);
	   	k = read(fd, ptr, BUFFER_SIZE);
		if(k < 0)
			return (0);
		line = ft_strjoin(line, ptr);
	}
	str = d_line(line);
	if (*line == '\n')
		return (get_next_line(fd));
	return (line);
}

int main()
{

 int fd = open("test.txt", O_RDWR);
 char *c; 
 int bytes = 0;
 
while (1)
 {
     c = get_next_line(fd);
	 if(*c == 0)
		 break;
	 printf("-----> %s", c);
	 bytes++;
 }
 close(fd);  
}
