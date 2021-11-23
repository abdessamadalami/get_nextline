/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 07:58:10 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/23 08:12:17 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

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
