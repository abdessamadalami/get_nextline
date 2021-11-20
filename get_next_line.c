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
#define BUFFER_SIZE 4

int chek_fun(char *s)
{
   int index;
   index = 0;
   while(s[index]!= '\0')
   {
   if(s[index] == '\n')
	   return 1;
   index++;
   }
   return 0;
}

char *get_next_line(int fd)
{
	static char *s;
	static int i;
	ssize_t k;
	s = malloc(BUFFER_SIZE);
   	k = read(fd, s, BUFFER_SIZE);
	if(chek_fun(s))
	{
		printf("\n");
		return get_next_line(fd);
		printf("_d_");
	}
	i++;
//	printf(" %d ",i);
  return s;
}

int main()
{

 int fd = open("test.txt", O_RDWR);
 char *c; 
 int bytes = 0;
 
while (1)
 {
     c = get_next_line(fd);
	 printf("%s",c);
	 if(c[0]=='\0')
		 break;
 }
 close(fd);  
}
