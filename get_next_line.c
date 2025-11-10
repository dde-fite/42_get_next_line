/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 19:27:13 by dde-fite          #+#    #+#             */
/*   Updated: 2025/11/10 20:47:12 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	extract_file(int fd, char **global)
{
	char			buf[BUFFER_SIZE + 1];
	char			*_tmp;
	ssize_t			n;
	const size_t	len_global = ft_strlen(*global);

	n = read(fd, buf, BUFFER_SIZE);
	if (n <= 0)
		return (-1);
	if (!*global)
	{
		*global = ft_strndup("", 1);
		if (!*global)
			return (-1);
	}
	buf[n] = '\0';
	_tmp = ft_strndup(*global, len_global + n);
	if (!_tmp)
		return (-1);
	ft_strlcpy(_tmp + len_global, buf, n + 1);
	free(*global);
	*global = _tmp;
	return (0);
}

char	*eof_management(char **global)
{
	char	*str;

	if (!*global)
		return (NULL);
	str = ft_strndup(*global, ft_strlen(*global));
	if (!str)
		return (NULL);
	free(*global);
	*global = NULL;
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*global;
	char		*_tmp;
	char		*rtrn;

	if (global)
		_tmp = ft_strchr(global, '\n');
	else
		_tmp = NULL;
	while (!_tmp)
	{
		if (!extract_file(fd, &global))
			_tmp = ft_strchr(global, '\n');
		else
			return (eof_management(&global));
	}
	rtrn = ft_strndup(global, _tmp - global + 1);
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

// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*gnl;

// 	fd = open("tests/constitucion copy.txt", O_RDONLY);
// 	gnl = get_next_line(fd);
// 	while (gnl)
// 	{
// 		printf("%s", gnl);
// 		free(gnl);
// 		gnl = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }
