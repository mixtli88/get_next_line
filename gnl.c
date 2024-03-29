/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:49:56 by mabril            #+#    #+#             */
/*   Updated: 2024/03/29 17:20:29 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *gnl(int fd)
{
	int i;
	char *buf;
	const char *stash;
	
	i = 0;

	read(fd, buf, BUFFER_SIZE);
	while(buf)
	{
		if (!stash)
			stash = ft_strdup(buf);
		else
		{
			stash = ft_strjoin(stash, buf);
		}
		read(fd, buf, BUFFER_SIZE);
	}
	// char *gnl(int fd) 
	// {
    // char *line = malloc(1024); // Asume que la línea tiene un máximo de 1024 caracteres
    // if (line == NULL) {
    //     perror("Error al asignar memoria");
    //     return NULL;
    // }

    // ssize_t bytes_read = read(fd, line, 1023); // Lee hasta 1023 caracteres y deja espacio para el carácter nulo
    // if (bytes_read == -1) {
    //     perror("Error al leer el archivo");
    //     free(line); // Libera la memoria asignada
    //     return NULL;
    // }

    // stash[nbyte] = '\0'; // Asegura que la cadena esté terminada en nulo
    return ((char *)stash);
}


int main(int ac, char **av)
{
	
	//open
	
	//validaciones del archivo
	//llamada a la funcion next_line
	//close

	int fd = open("file.txt", O_RDWR);
    if (fd == -1)
	{
        perror("Error al abrir el archivo");
        return 1;
    }
    char *line1 = gnl(fd);
	// char *line2 = gnl(fd);
	// char *line3 = gnl(fd);
	// char *line4 = gnl(fd);
    // if (line != NULL) 
	// {
    printf("%s\n", line1);
    //     free(line); // Libera la memoria asignada en gnl
    // }

    close(fd);
	return (0);
}