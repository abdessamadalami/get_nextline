/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 06:18:01 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/28 17:55:57 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include<stdlib.h>
# include <limits.h>

size_t	ft_strlen(const char *str);
int		check_fun(char *s);
int		check_back_s(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);
char	*d_line(char *line);
char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
