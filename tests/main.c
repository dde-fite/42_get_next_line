/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:39:04 by dde-fite          #+#    #+#             */
/*   Updated: 2025/11/06 17:18:25 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"


int	main(void)
{
	int		fd;
	char	*buf;

	buf = malloc(BUFFER_SIZE);
	if (!buf)
		return (NULL);
	fd = open("test1.txt", O_RDONLY);
	read(fd, buf, BUFFER_SIZE);
	close(fd);
}
