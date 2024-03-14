/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:06:34 by hiono             #+#    #+#             */
/*   Updated: 2024/03/14 16:31:46 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int			i;
	const char	*ptr;

	if (!str)
		return (0);
	i = 0;
	ptr = str;
	while (*ptr != '\0')
	{
		i++;
		ptr++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	actlen;

	if (ft_strlen(s) < start)
	{
		ptr = malloc(sizeof(char));
		*ptr = '\0';
		return (ptr);
	}
	actlen = 0;
	while (actlen < len && s[start + actlen])
		actlen++;
	if (actlen == 0)
		return (NULL);
	ptr = malloc(sizeof(char) * (actlen + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < actlen)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static const char	*ft_strncat(char *dst, const char *src, unsigned int l)
{
	int		i;
	int		len;

	len = ft_strlen(dst);
	i = 0;
	while (src[i] && i < (int)l)
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[len + i] = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*ptr;
	size_t	ls1;
	size_t	ls2;

	if (!s1 && !s2)
		return (NULL);
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	// printf("%zu %zu, ", ls1, ls2);
	ptr = malloc(sizeof(char) * (ls1 + ls2 + 1));
	if (ptr == NULL)
		return (NULL);
	ptr[0] = '\0';
	if (ls1 > 0)
	{
		ft_strncat(ptr, s1, ls1);
		free(s1);
	}
	if (ls2 > 0)
		ft_strncat(ptr, s2, ls2);
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	cc;

	if (!s)
		return (NULL);
	str = (char *)s;
	cc = (char)c;
	while (*str || *str == cc)
	{
		if (*str == cc)
			return (str);
		str++;
	}
	return (NULL);
}
