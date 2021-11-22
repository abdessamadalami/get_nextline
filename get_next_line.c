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
#define BUFFER_SIZE 3
#include"libft.h"
static char	*ft_strcat_p(char *dest, const char *src, int position)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (dest[i] != '\0' && position != 0)
		i++;
	while (src[len] != '\0')
	{
		dest[i] = src[len];
		i++;
		len++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		index;
	int		length;
	char	*ptr;

	index = 0;
	
	length = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc(length);
	if (ptr == NULL)
		return (0);
	ft_strcat_p(ptr, s1, 0);
	ft_strcat_p(ptr, s2, 1);
	return (ptr);
}

int chek_fun(char *s)
{
   int index;
   index = 0;
   while(s[index]!= '\0')
   {
   if(s[index] == '\n')
	   return 0;
   index++;
   }
   return 1;
}

int chek_back_s(char *s)
{
   int index;
   index = 0;
   while(s[index]!= '\0')
   {
   if(s[index] == '\n' || s[index+1]=='\0')
	   return index;
   index++;
   }
   if(index == 0)
	   return 1;
   return 0;
}

char *get_next_line(int fd)
{
	char		*ptr;
	char		*line;
	int			i;
	static char	*str;
	ssize_t		k;
	i = 0;
	ptr = 0;	
	line = malloc( BUFFER_SIZE);
	if (str != NULL)
		line = ft_strjoin(line, str);
	while (chek_fun(line))
	{
		ptr = malloc(BUFFER_SIZE);
		 k = read(fd, ptr, BUFFER_SIZE);
		 if(k == 0)
			 break;
		line = ft_strjoin(line, ptr);
		if(!chek_fun(line))
			break;
	}
	i = chek_back_s(line);
	if(line[i+2] !='\0' && line[i+2] != '\n')
		str = ft_strdup(line + i + 1);
	else
		str = 0;
	line[i+1] = 0;
	if(*line == '\n')
		return get_next_line(fd);
//	printf("%s",line);
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
	 printf("___ %s", c);
	 bytes++;
 }
 close(fd);  
}
