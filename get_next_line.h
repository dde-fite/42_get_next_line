/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:50:02 by dde-fite          #+#    #+#             */
/*   Updated: 2025/11/06 20:40:55 by dde-fite         ###   ########.fr       */
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

/* ****************************** MAIN PROTOYPE ***************************** */
char	*get_next_line(int fd);
/* ************************************************************************** */

/* ********************************* UTILS ********************************** */
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strndup(const char *s, size_t len);
char	*ft_strdup(const char *s);

#endif