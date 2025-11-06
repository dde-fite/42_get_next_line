/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:50:08 by dde-fite          #+#    #+#             */
/*   Updated: 2025/11/06 20:52:57 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*global_buf;
	const char	*_global_buf = global_buf;
	char		*buf;
	char		*_buf;

	if (global_buf)
	{
		while (_global_buf && _global_buf != '\n')
			_global_buf++;
		if (_global_buf == '\n' || _global_buf - global_buf < BUFFER_SIZE)
		{
			buf = ft_strndup(global_buf, _global_buf - global_buf);
			if (!buf)
				return (NULL);
			if (_global_buf == '\n')
				_global_buf = ft_strdup(_global_buf + 1);
			else
				_global_buf = NULL;
			free(global_buf);
			global_buf = _global_buf;
			return (buf);
		}
	}
	if (!read(fd, buf, BUFFER_SIZE))
	{
		if (global_buf)
		{
			buf = ft_strdup(global_buf);
			if (!buf)
				free(global_buf);
			return (buf);
		}
		return (NULL);
	}
	while (_buf && _buf != '\n')
			_buf++;
	while (_global_buf && _global_buf != '\n')
	if (global_buf)
	{
		_global_buf = ft_strdup()
		buf = (global_buf, buf);


	}
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		i;
	int		fd;

	fd = open("tests/test1.txt", O_RDONLY);
	i = 4;
	while (i-- > 0)
		printf("%s", get_next_line(fd));
	close(fd);
}
