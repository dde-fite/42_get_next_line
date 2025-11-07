/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:50:02 by dde-fite          #+#    #+#             */
/*   Updated: 2025/11/07 22:05:02 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                         GET_NEXT_LINE by dde-fite                          */
/* ************************************************************************** */

/* ************************ PREPROCESSOR STATEMENTS ************************* */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>

/* ******************** STRUCTS, TYPES, OTHER STATEMENTS ******************** */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* ****************************** MAIN PROTOYPE ***************************** */
char	*get_next_line(int fd);
/* ************************************************************************** */

/* ********************************* UTILS ********************************** */
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/* **************************** BONUS FUNCTIONS ***************************** */

// ft_lstnew
t_list	*ft_lstnew(void *content);

// ft_lstlast
t_list	*ft_lstlast(t_list *lst);

// ft_lstadd_back
void	ft_lstadd_back(t_list **lst, t_list *new);

// ft_lstdelone
void	ft_lstdelone(t_list *lst, void (*del)(void*));

// ft_lstclear
void	ft_lstclear(t_list **lst, void (*del)(void*));

#endif