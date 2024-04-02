/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:49:56 by mabril            #+#    #+#             */
/*   Updated: 2024/04/01 20:19:50 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include "get_next_line.h"

int ft_strchr_n(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlen(const char	*s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*copie;
	int		i;

	len = 0;
	i = 0;
	while (s1[len])
		len++;
	printf("size first buf :%d\n", len);
	copie = malloc(sizeof(char) * (len + 1));
	if (!copie)
		return (0);
	while (s1[i])
	{
		copie[i] = s1[i];
		i++;
	}
	copie[i] = '\0';
	return (copie);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		i;
	int		j;

	new_str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!new_str)
		return (0);
	i = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new_str[i + j] = s2[j];
		j++;
	}
	new_str[i + j] = '\0';
	return (new_str);
}

char *gnl(int fd)
{
	int i;
	int c;
	char *buf;
	buf = malloc(sizeof(char) * BUFFER_SIZE);
	

	
	i = 0;
	stash = NULL;
	read(fd, buf, BUFFER_SIZE);
	while (buf)
	{
		// printf("AVANT DUP  %zu\n", ft_strlen(buf));
		
		if (!stash)
			stash = ft_strdup(buf);			
		else
			stash = ft_strjoin(stash, buf);
		c = read(fd, buf, BUFFER_SIZE);
		free(buf);
		if (c == 0)
			break;
	}
		// printf("STASH  %s\n", stash);
    return (stash);
}


int main()
{
	

	int fd = open("file.txt", O_RDWR);
    if (fd == -1)
	{
        perror("Error al abrir el archivo");
        return 1;
    }
    printf("%s\n", gnl(fd));
	// printf("%s", gnl(fd));
	// printf("%s", gnl(fd));
	// printf("%s", gnl(fd));
	// printf("%s", gnl(fd));
	// printf("%s", gnl(fd));

    close(fd);
	return (0);
}