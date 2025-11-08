/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:50:02 by dde-fite          #+#    #+#             */
/*   Updated: 2025/11/08 22:10:42 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                         GET_NEXT_LINE by dde-fite                          */
/* ************************************************************************** */

/* ************************ PREPROCESSOR STATEMENTS ************************* */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
// #  define BUFFER_SIZE 1024
#  define BUFFER_SIZE 4
# endif

# include <unistd.h>
# include <stdlib.h>

/* ****************************** MAIN PROTOYPE ***************************** */
char	*get_next_line(int fd);
/* ************************************************************************** */

/* ********************************* UTILS ********************************** */
char	*ft_strchr(const char *s, int c);
char	*ft_strndup(const char *s, size_t len);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_minsize(size_t n1, size_t n2);

#endif