/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:20:37 by mabril            #+#    #+#             */
/*   Updated: 2024/04/22 20:24:04 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *lin)
{
	char	buff[BUFFER_SIZE + 1];
	char	*tempo;
	int		flag;

	flag = 0;
	tempo = NULL;
	while (2)
	{
		flag = read(fd, buff, BUFFER_SIZE);
		buff[flag] = '\0';
		if (flag == 0)
		{
			if (lin)
				return (lin);
			else
		 	 	return (tempo);
		}
		if (lin)
		{
			tempo = ft_strjoin(lin, buff);
			lin = NULL;
			if (ft_strchr(tempo, '\n') || flag < BUFFER_SIZE)
				return (tempo);
		}
		else if (tempo)
		{
			lin = ft_strjoin(tempo, buff);
			tempo = NULL;
			if (ft_strchr(lin, '\n'))
				return (lin);
		}
		else
			tempo = ft_strdup(buff);
	}
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stock;

	stock = ft_read_line(fd, stock);
	if (stock == NULL || *stock == '\0')
		return (NULL);
	line = ft_strdup_n(stock);
	if (ft_strchr(stock, '\n'))
		stock = ft_strdup_apr_n(stock);
	else
	{
		free(stock);
		stock = NULL;
	}
	return (line);
}

// int	main(void)
// {
// 	int fd = open("file.txt", O_RDWR);
// 	char *str;
	
// 	str = get_next_line(fd);
// 		printf("%s", str);
// 		if (str)
// 			free(str);
// 	while (str)
// 	{
// 		str = get_next_line(fd);
// 		printf("%s", str);
// 		if (str)
// 			free(str);
// 	}
// 	close(fd);
// 	return (0);
// }