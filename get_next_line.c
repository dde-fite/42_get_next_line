/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 19:27:13 by dde-fite          #+#    #+#             */
/*   Updated: 2025/11/08 22:52:18 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

const char	*bcktrim(const char *s)
{
	s += ft_strlen(s);
	while (*s == '\n')
		s--;
	return (s);
}

int	extract_file(int fd, char **global)
{
	char			buf[BUFFER_SIZE];
	char			*_tmp;
	ssize_t			n;
	const size_t	len_global = ft_strlen(*global);

	n = read(fd, buf, BUFFER_SIZE);
	if (n <= 0)
		return (-1);
	_tmp = ft_strndup(*global, len_global + n);
	if (!_tmp)
		return (-1);
	ft_strlcpy(_tmp + len_global, buf, n + 1);
	free(*global);
	*global = _tmp;
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*global;
	char		*_tmp;
	char		*rtrn;

	if (!global)
	{
		global = ft_strndup("", 1);
		if (!global)
			return (NULL);
	}
	_tmp = ft_strchr(global, '\n');
	while (!_tmp && !extract_file(fd, &global))
		_tmp = ft_strchr(global, '\n');
	rtrn = ft_strndup(global, _tmp - global);
	if (!rtrn)
		return (NULL);
	_tmp = ft_substr(global, _tmp - global + 1, ft_strlen(_tmp) - 1);
	if (!_tmp)
	{
		free(rtrn);
		return (NULL);
	}
	free(global);
	global = _tmp;
	return (rtrn);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		i;
	int		fd;

	fd = open("tests/test1.txt", O_RDONLY);
	for(int i = 0; i <= 500; i++)
	{
		printf("%s\n", get_next_line(fd));
	}
	close(fd);
}
