/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:14:43 by mabril            #+#    #+#             */
/*   Updated: 2024/04/25 21:26:05 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchrcheck(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	return (NULL);
}

char	*ft_strdup(char *s1)
{
	int		len;
	char	*copie;

	len = 0;
	while (s1[len] != '\0')
		len++;
	// printf ("OE : %i\n", len);
	copie = malloc(sizeof(char) * (len + 1));
	if (!copie)
		return (0);
	len = 0;
	while (s1[len])
	{
		copie[len] = s1[len];
		len++;
	}
	copie[len] = '\0';
	return (copie);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	new_str = malloc(sizeof(char) * ((i + j + 2)));
	if (!new_str)
		return (0);
	i = -1;
	while (s1[++i])
		new_str[i] = s1[i];
	j = -1;
	while (s2[++j])
		new_str[i + j] = s2[j];
	if (s1)
		free(s1);
	new_str[i + j] = '\0';
	return (new_str);
}

char	*ft_strdup_n(char *s1)
{
	int		len;
	char	*copie;
	int		i;

	len = 0;
	i = 0;
	while (s1[len] != '\n' && s1[len] != '\0')
		len++;
	copie = malloc(sizeof(char) * (len + 2));
	if (!copie)
		return (0);
	while (i <= len)
	{
		copie[i] = s1[i];
		i++;
	}
	copie[i] = '\0';
	return (copie);
}
// *str ['\0']
char	*ft_strdup_apr_n(char *s1)
{
	int		len;
	char	*copie;
	int		i;

	len = 0;
	i = 0;
	while (s1[len + 1] != '\0')
		len++;
	while (s1[i] != '\n')
		i++;
	if (len == i)
		return (free(s1), NULL);
	copie = malloc(sizeof(char) * ((len - i) + 1));
	if (!copie)
		return (0);
	len = 0;
	while (s1[i + 1] != '\0')
	{
		copie[len] = s1[i + 1];
		len++;
		i++;
	}
	copie[len] = '\0';
	free(s1);
	return (copie);
}
