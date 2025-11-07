/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:50:05 by dde-fite          #+#    #+#             */
/*   Updated: 2025/11/07 21:45:37 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}

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

char	*ft_strdup(const char *s)
{
	return (ft_strndup(s, ft_strlen(s)));
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

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while ((*lst)->next)
		lst = &(*lst)->next;
	(*lst)->next = new;
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*nxtlst;

	while (*lst)
	{
		nxtlst = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = nxtlst;
	}
}

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
