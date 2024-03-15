/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:06:34 by hiono             #+#    #+#             */
/*   Updated: 2024/03/15 16:21:48 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int			i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	if (len == 0)
		return (NULL);
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
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
	ptr = malloc(sizeof(char) * (ls1 + ls2 + 1));
	if (ptr == NULL)
		return (NULL);
	ptr[0] = '\0';
	if (ls1 > 0)
		ft_strncat(ptr, s1, ls1);
	if (ls2 > 0)
		ft_strncat(ptr, s2, ls2);
	free(s1);
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	cc;

	str = (char *)s;
	cc = (char)c;
	if (!s)
		return (NULL);
	while (*str || *str == cc)
	{
		if (*str == cc)
			return (str);
		str++;
	}
	return (NULL);
}
