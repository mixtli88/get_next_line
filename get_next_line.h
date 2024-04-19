/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:22:27 by mabril            #+#    #+#             */
/*   Updated: 2024/04/19 18:29:32 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3


#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<fcntl.h>


char	*gnl(int fd);
char	*ft_strchr(const char *s, int c);
int 	ft_strchr_n(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char	*s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);

size_t  ft_strlcat(char *dst, const char *src, size_t dstsize);
// char  ft_strcpy(char *dst, const char *src);
int	ft_strchr_pos(const char *s, int c);
char	*ft_strdup_n(const char *s1);
char	*ft_strdup_apr_n(const char *s1);

#endif
#endif
