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
#define BUFFER_SIZE 1

char *get_next_line(int fd)
{
	char *s;
	s = malloc(BUFFER_SIZE);
  ssize_t k = read(fd, s, BUFFER_SIZE);
  printf("%zu %s ",k,s);
  return 0;
}

int main()
{

 int fd = open("test.txt", O_RDWR);
 char c; 
 int bytes;
   printf(" %d ",fd);

    get_next_line(fd);

 close(fd);  
}
