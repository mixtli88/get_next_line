/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnextline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:49:56 by mabril            #+#    #+#             */
/*   Updated: 2024/04/17 17:57:08 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_read_line(int fd, char *lin_n)
{
	
	char buff[BUFFER_SIZE + 1];
	int flag;

		
	while (2)
	{	
		flag = read(fd, buff, BUFFER_SIZE);
		if (flag == 0)
			return (lin_n);
		if (!lin_n)
		{
			lin_n = ft_strdup(buff);
			flag = read(fd, buff, BUFFER_SIZE);
		}
		buff[flag] = '\0';
		lin_n = ft_strjoin(lin_n, buff);
		// printf("%s\n", buff);
		if (ft_strchr(lin_n, '\n'))
			return (lin_n);
	}
	if (flag == -1)
		return (NULL);
	return (lin_n);
}

char *gnl(int fd)
{
	char *tem;
	char *line;
	static char *stock;
	
	stock  = ft_read_line(fd, stock);
	// printf("%s\n", stock);
	line = ft_strdup_n(stock);
	stock = ft_strchr(stock, '\n');
	// printf("*%s\n", stock);
	
	
	
	return (line);
}

int main()
{
	

	int fd = open("file.txt", O_RDWR);
	char *str;
		if (str)
		{
			str = gnl(fd);
			printf("%s", str);
			free(str);
		}
		
	str = gnl(fd);
	printf("%s", str);
	free(str);
	str = gnl(fd);
	printf("%s", str);
	free(str);

	str = gnl(fd);
	printf("%s", str);
	free(str);

	str = gnl(fd);
	printf("%s", str);
	free(str);

	str = gnl(fd);
	printf("%s", str);
	free(str);

	str = gnl(fd);
	printf("%s", str);
	free(str);

	str = gnl(fd);
	printf("%s", str);
	free(str);

	str = gnl(fd);
	printf("%s", str);
	free(str);

	str = gnl(fd);
	printf("%s", str);
	free(str);

	str = gnl(fd);
	printf("%s", str);
	free(str);

	str = gnl(fd);
	printf("%s", str);
	free(str);

	str = gnl(fd);
	printf("%s", str);
	free(str);
    close(fd);
	return (0);
}