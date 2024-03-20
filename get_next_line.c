/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:53:38 by hiono             #+#    #+#             */
/*   Updated: 2024/03/20 11:18:22 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

void	rls_buffer(char **buffer)
{
	if (*buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*line;
	size_t			llen;
	char			*newbf;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0 || fd < 0)
	{
		rls_buffer(&buffer);
		return (NULL);
	}
	if (!ft_strchr(buffer, '\n'))
		buffer = fill_bf(buffer, fd);
	if (!buffer)
	{
		rls_buffer(&buffer);
		return (NULL);
	}
	llen = getllen(buffer);
	line = ft_substr(buffer, 0, llen);
	newbf = ft_substr(buffer, llen, ft_strlen(buffer) - llen);
	free(buffer);
	buffer = newbf;
	return (line);
}
