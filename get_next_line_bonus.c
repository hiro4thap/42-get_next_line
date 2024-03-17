/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:53:38 by hiono             #+#    #+#             */
/*   Updated: 2024/03/17 12:35:46 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*fill_bf(char *bf, int fd)
{
	char	*temp;
	int		b_read;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	b_read = 1;
	while (b_read > 0 && !ft_strchr(bf, '\n'))
	{
		b_read = read(fd, temp, BUFFER_SIZE);
		temp[b_read] = '\0';
		bf = ft_strjoin(bf, temp);
	}
	free(temp);
	return (bf);
}

size_t	getllen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static char		*buffers[1024];
	char			*line;
	size_t			llen;
	char			*newbf;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0 || fd < 0)
	{
		free(buffers[fd]);
		buffers[fd] = NULL;
		return (NULL);
	}
	if (!ft_strchr(buffers[fd], '\n'))
		buffers[fd] = fill_bf(buffers[fd], fd);
	if (!buffers[fd])
	{
		free(buffers[fd]);
		return (NULL);
	}
	llen = getllen(buffers[fd]);
	line = ft_substr(buffers[fd], 0, llen);
	newbf = ft_substr(buffers[fd], llen, ft_strlen(buffers[fd]) - llen);
	free(buffers[fd]);
	buffers[fd] = newbf;
	return (line);
}
