/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:49:56 by mabril            #+#    #+#             */
/*   Updated: 2024/04/04 12:54:51 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr_pos(const char *s, int c)
{
	int i;
	int t;

	t = '\0';
	while (*s)
	{
		if (*s == (char)c)
			return (i);
		s++;
		i++;
	}
	if (*s == (char)t)
		return (i);
	return (0);
}
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
	free(s1);
	new_str[i + j] = '\0';
	return (new_str);
}

char	*ft_strjoin_fin(char const *s1, char const *s2, size_t n)
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
	while (j < n)
	{
		new_str[i + j] = s2[j];
		j++;
	}
	new_str[i + j] = '\0';
	return (new_str);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*copie;
	int		i;

	len = 0;
	i = 1;
	while (s1[len])
		len++;
	copie = malloc(sizeof(char) * (len + 1));
	if (!copie)
		return (0);
	while (s1[i - 1])
	{
		copie[i - 1] = s1[i - 1];
		i ++;
	}
	copie[i - 1] = '\0';
	return (copie);
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

char	*ft_strncpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize)
		dst[i] = '\0';
	return (dst);
}

char *gnl(int fd)
{
	int c;
	int pos;
	char buf[BUFFER_SIZE];
	static char *stash;
	char *line;
	
	c = read(fd, buf, BUFFER_SIZE);
	stash = ft_strdup(buf);			
	while (c > 0)
	{				
		if ((pos =ft_strchr_pos(stash,'\n')) != 0)
		{
			line = malloc(sizeof(char*) * pos);
			line = ft_strncpy(line, stash, pos);
			return(line);
		}
		else
		{
			c = read(fd, buf, BUFFER_SIZE);
			stash = ft_strjoin(stash, buf);
		}
		// printf("buf_____   %s\n", buf);
		
		if (c == 0)
			break;
		
		// stash = ft_strjoin_fin(stash, buf, c);
		// line = ft_strchr(stash,'\n');
	}
    return (line);
}

int main()
{
	

	int fd = open("file.txt", O_RDWR);
    if (fd == -1)
	{
        perror("Error al abrir el archivo");
        return 1;
    }
    printf("\n\n\n\n%s", gnl(fd));
	printf("%s", gnl(fd));
	// printf("%s", gnl(fd));
	// printf("%s", gnl(fd));
	// printf("%s", gnl(fd));
	// printf("%s", gnl(fd));

    close(fd);
	return (0);
}
		// if (salto_line != NULL)
		// posicion_n = ft_strchr_n(stash, '\n');
		// if (posicion_n >=  0)
		// {
		// 	line = malloc(sizeof(char*) * posicion_n + 1);
		// 	ft_strncpy(line, stash, posicion_n);
		// 	return(line);
		// }
		// if (ft_strdup(ft_strchr(stash, '\n')))
	// } printf("STASH  %s\n", stash);