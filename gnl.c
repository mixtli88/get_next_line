/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:49:56 by mabril            #+#    #+#             */
/*   Updated: 2024/04/11 09:49:03 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



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

char *gnl(int fd)
{
	int c;
	int pos;
	char *tem;
	char buf[BUFFER_SIZE + 1];
	static char *stash;
	char *line;
	
	c = 0;
	pos = 0;
	c = read(fd, buf, BUFFER_SIZE);
	stash = ft_strdup(buf);			
	while (c > 0)
	{			
		pos = ft_strchr_pos(stash,'\n');
		printf("%d ", pos);
		if (pos != 0)
		{
			line = malloc(sizeof(char*) * pos);
			line = ft_strncpy(line, stash, pos);
			free (stash);
			return(line);
		}
		else
		{
			c = read(fd, buf, BUFFER_SIZE);
			tem = ft_strjoin(stash, buf);
			free (stash);
			stash = tem;
			
		}
		
		if (c == 0)
			break;
		
		
		
	}
    return (line);
}

int main()
{
	char *str;

	int fd = open("file.txt", O_RDWR);
    if (fd == -1)
	{
        perror("Error al abrir el archivo");
        return 1;
    }
	while (fd > 0)
	{
		str = gnl(fd);
		if (str)
		{
			printf("\n\n\n\n%s", str);
			free(str);
		}
	}
    close(fd);
	return (0);
}
