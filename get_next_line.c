/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 19:27:13 by dde-fite          #+#    #+#             */
/*   Updated: 2025/11/12 18:10:46 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	str_join(char **original, char *s2, ssize_t n)
{
	char			*new;
	const size_t	len_original = ft_strlen(*original);

	new = ft_strndup(*original, len_original + n);
	if (!new)
		return (-1);
	ft_strlcpy(new + len_original, s2, n + 1);
	free(*original);
	*original = new;
	return (0);
}

static int	extract_file(int fd, char **global, ssize_t *n)
{
	char			*buf;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	*n = read(fd, buf, BUFFER_SIZE);
	if (*n <= 0)
		return (free (buf), -1);
	if (!*global)
	{
		*global = ft_strndup("", 1);
		if (!*global)
			return (free (buf), -1);
	}
	buf[*n] = '\0';
	if (str_join(global, buf, *n))
		return (free (buf), -1);
	return (free (buf), 0);
}

static char	*eof_management(char **global, ssize_t n)
{
	char	*str;

	if (n < 0)
	{
		free(*global);
		*global = NULL;
		return (NULL);
	}
	if (!*global)
		return (NULL);
	if (!**global)
		return (free(*global), NULL);
	str = ft_strndup(*global, ft_strlen(*global));
	free(*global);
	*global = NULL;
	if (!str)
		return (NULL);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*global;
	const char	*_tmp = NULL;
	char		*rtrn;
	ssize_t		n;

	if (global)
		_tmp = ft_strchr(global, '\n');
	while (!_tmp)
	{
		if (extract_file(fd, &global, &n))
			return (eof_management(&global, n));
		_tmp = ft_strchr(global, '\n');
	}
	rtrn = ft_strndup(global, _tmp - global + 1);
	if (!rtrn)
		return (NULL);
	_tmp = ft_substr(global, _tmp - global + 1, ft_strlen(_tmp) - 1);
	if (!_tmp)
		return (free(rtrn), NULL);
	free(global);
	global = NULL;
	if (!*_tmp)
		return (free((char *)_tmp), rtrn);
	global = (char *)_tmp;
	return (rtrn);
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*gnl;

// 	fd = open("tests/read_error.txt", O_RDONLY);
// 	// while (gnl)
// 	for (int i = 0; i<20; i++)
// 	{
// 		if (i == 2)
// 		{
// 			gnl = get_next_line(5);
// 			close(fd);
// 			fd = open("tests/read_error.txt", O_RDONLY);
// 		}
// 		else
// 			gnl = get_next_line(fd);
// 		printf(" %s", gnl);
// 		free(gnl);
// 	}
// 	close(fd);
// 	return (0);
// }
