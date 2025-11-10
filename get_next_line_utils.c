/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:50:05 by dde-fite          #+#    #+#             */
/*   Updated: 2025/11/10 17:18:05 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (((unsigned char)c) == '\0')
		return ((char *)(s + ft_strlen(s)));
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strndup(const char *s, size_t len)
{
	char			*str;

	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, len + 1);
	return (str);
}

size_t	ft_strlen(const char *s)
{
	const char	*_s = s;

	while (*_s)
		_s++;
	return (_s - s);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	const char	*_s = src;

	if (size > 0)
	{
		while (size-- > 1 && *src)
			*(dst++) = *(src++);
		*dst = '\0';
	}
	return (ft_strlen(_s));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t const	s_len = ft_strlen(s);
	size_t			min_size;

	if (start >= s_len)
		return (ft_strndup("", 1));
	if (s_len - start < len)
		min_size = s_len - start;
	else
		min_size = len;
	return (ft_strndup(s + start, min_size));
}
