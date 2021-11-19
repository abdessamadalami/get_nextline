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


char *get_next_line(int fd)
{
	char *s;
	ssize_t k;
	s = malloc(BUFFER_SIZE);
   	k = read(fd, s, BUFFER_SIZE);
	printf("%zd ",k);
  return s;
}

int main()
{

 int fd = open("test.txt", O_RDWR);
 char c; 
 int bytes = 0;

 while ( bytes < 9)
 {
     printf(" %s ",(get_next_line(fd)));
	 bytes++;
 }
 close(fd);  
}
