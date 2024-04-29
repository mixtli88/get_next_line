/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:20:37 by mabril            #+#    #+#             */
/*   Updated: 2024/04/29 09:56:41 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *stic)
{
	char	buff[BUFFER_SIZE + 1];
	size_t	n_read;

	n_read = 0;
	while (2)
	{
		n_read = read(fd, buff, BUFFER_SIZE);
		if (n_read == 0)
			return (stic);
		buff[n_read] = '\0';
		if (!stic)
			stic = ft_strdup(buff);
		else
			stic = ft_strjoin(stic, buff);
		if (ft_strchr(stic, '\n') || n_read < BUFFER_SIZE)
			return (stic);
	}
}

char	*get_next_line(int fd)
{
	char		*nl;
	static char	*stock;

	if (fd < 0 || read(fd, 0, 0) < 0)
		return (free(stock), stock = NULL, NULL);
	stock = ft_read_line(fd, stock);
	if (!stock)
		return (NULL);
	nl = ft_strdup_n(stock);
	if (ft_strchr(stock, '\n'))
		stock = ft_strdup_apr_n(stock);
	else
	{
		free(stock);
		stock = NULL;
	}
	return (nl);
}

// int	main(void)
// {
// 	int fd =  open("file.txt", O_RDWR);
// 	char *str;
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