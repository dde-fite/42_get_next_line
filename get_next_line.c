/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:50:08 by dde-fite          #+#    #+#             */
/*   Updated: 2025/11/07 22:05:35 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_saved_line(t_list **lst)
{
	t_list	*_lst;
	char	*str;

	_lst = *lst;
	str = ft_strndup((*lst)->content, ft_strlen(lst->content) - 1);
	if (!str)
		return (NULL);
	*lst = (*lst)->content;
	ft_lstdelone(_lst, free);
	return (str);
}

char	*finished_file(t_list *lst)
{
	char	*str;
	size_t	str_len;

	if (lst)
	{
		str_len = ft_strlen(lst->content);
		if (lst->content[str_len] == '\n')
			str_len--;
		str = ft_strndup(lst->content, ft_strlen(lst->content));
		if (!str)
			return (NULL);
		ft_lstclear(&lst, free);
		return (str);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_list	*acc_lst;
	t_list			*_lst;
	char			*buf;
	char			*_buf;
	char			*rtrn;
	char			*str;

	if (acc_lst && ft_strchr(acc_lst->content, '\n'))
		return (get_saved_line(&acc_lst));
	buf = malloc(BUFFER_SIZE);
	if (!buf)
		return (NULL);
	while (read(fd, buf, BUFFER_SIZE))
	{
		while (*buf)
		{
			_buf = ft_strchr(buf, '\n');
			if (_buf)
				rtrn = ft_strndup(buf, _buf + 1 - buf);
			else
				rtrn = ft_strdup(buf);
			if (!rtrn)
				return (NULL);
			if (!acc_lst)
			{
				_lst = ft_lstnew(rtrn);
				if (!_lst)
				{
					free(rtrn);
					return (NULL);
				}
				acc_lst = _lst;
			}
			else if (ft_strchr(ft_lstlast(acc_lst)->content, '\n'))
			{
				_lst = ft_lstnew(rtrn);
				if (!_lst)
				{
					free(rtrn);
					return (NULL);
				}
				ft_lstadd_back(&acc_lst, _lst);
			}
			else
			{
				_lst = ft_lstlast(acc_lst);
				str = ft_strjoin(_lst->content, rtrn);
				if (!str)
				{
					free(rtrn);
					return (NULL);
				}
				_lst->content = str;
				free(rtrn);
			}
			if (_buf)
				buf = _buf + 1;
			else
				break ;
		}
		if (acc_lst && ft_strchr(acc_lst->content, '\n'))
			return (get_saved_line(&acc_lst));
	}
	return (finished_file(acc_lst));
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		i;
	int		fd;

	fd = open("tests/test1.txt", O_RDONLY);
	i = 4;
	printf("%s\n", get_next_line(fd));
	close(fd);
}
