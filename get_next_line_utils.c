/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:50:05 by dde-fite          #+#    #+#             */
/*   Updated: 2025/11/06 20:39:51 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	const size_t	s1_len = ft_strlen(s1);
	const size_t	len = s1_len + ft_strlen(s2);
	char			*str;

	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcpy(str + s1_len, s2, len - s1_len + 1);
	return (str);
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

char	*ft_strdup(const char *s)
{
	return (ft_strndup(s, ft_strlen(s)));
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

size_t	ft_strlen(const char *s)
{
	const char	*_s = s;

	while (*_s)
		_s++;
	return (_s - s);
}
