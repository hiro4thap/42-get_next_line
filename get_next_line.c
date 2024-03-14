/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:53:38 by hiono             #+#    #+#             */
/*   Updated: 2024/03/14 16:31:40 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	if (n == 0)
		return ;
	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}

char	*readtonl(char *bf, int fd)
{
	char	*temp;
	int		len;

	if (ft_strchr(bf, '\n'))
		return (bf);
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (1)
	{
		len = read(fd, temp, BUFFER_SIZE);
		if (len == 0)
			break ;
		temp[len] = '\0';
		bf = ft_strjoin(bf, temp);
		if (ft_strchr(bf, '\n'))
			break ;
		ft_bzero(temp, BUFFER_SIZE + 1);
	}
	free(temp);
	return (bf);
}

size_t	ft_llen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] != '\n')
		i--;
	return (i);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*line;
	size_t			llen;
	char			*newbf;

	//not sure what it means
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0 || fd < 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = readtonl(buffer, fd);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	llen = ft_llen(buffer);
	line = ft_substr(buffer, 0, llen + 1);
	newbf = ft_substr(buffer, llen + 1, ft_strlen(buffer) - llen - 1);
	free(buffer);
	buffer = newbf;
	return (line);
}

