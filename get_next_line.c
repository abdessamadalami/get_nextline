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
		if(s[index] == '\n'|| s[index + 1] == '\0')
			return (index);
		index++;
	}
	return (0);
}

char	*d_line(char *line)
{
	size_t		i;
	char	*str;

    if (*line == '\n')
		return 0;
	i = check_back_s(line);
	if(i == ft_strlen(line))
		i--;
	if(line[i + 1] != '\0')
		str = ft_strdup(line + i + 1);
	else
		str = 0;
	line[i + 1] = 0;
	return (str);
}
//-fsanitize=address -g

char	*get_next_line(int fd)
{
	char		*ptr;
	char		*line;
	static char	*str;
	ssize_t		k;
	char		*temp;
     
	temp= NULL;
	line = calloc(BUFFER_SIZE + 1,1);
	if (str != NULL)
		line = ft_strjoin(line, str);
	while (check_fun(line))
	{ 	//printf("{ k <%zd> str <%s> ptr <%s> line <%s> } \n",k , str,ptr,line);
		ptr = malloc(BUFFER_SIZE + 1);
		k = read(fd, ptr, BUFFER_SIZE + 1);
		ptr[k] = '\0';
		if(k == 0 || k == -1) 
		{
			if (ft_strlen(line) == 0) 
				{
					free(line);
					free(ptr);
					return 0;
				}
			free(ptr);
			return line;
		}
		line = ft_strjoin(line, ptr);
		free(ptr);
	}		
	if (!check_fun(line))
		{
			temp = str;
			str = d_line(line);
			free(temp);
			return (line);
		}
		    free(line);
			free(str);
			free(temp);
			return 0;
}
//printf("line {%s} ptr <%s> str <%s>", line, ptr,str);
// int main()
// {

//  //int fd = open("nl", O_RDWR);
//  int fd = open("41_no_nl", O_RDWR); 
//  char *c;
// //  char *line; 
// //  line = malloc(BUFFER_SIZE);
// //  int k = read(fd, line, BUFFER_SIZE);
// // printf(" %d ",k);
// int index = 0;
// while (1)
//  {
//      c = get_next_line(fd);

// 	 printf("----->%s\n", c);
// 	 if(c == 0)
// 	     break;
// 	 index++;
// 	// system("leaks a.out");
//  }
//  close(fd); 
// }
