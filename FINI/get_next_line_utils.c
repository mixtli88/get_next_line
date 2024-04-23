/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:14:43 by mabril            #+#    #+#             */
/*   Updated: 2024/04/22 17:55:39 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*t;

	i = 0;
	t = (char *)s;
	while (*t)
	{
		if (*t == (char)c)
			return (++t);
		t++;
		i++;
	}
	return (NULL);
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

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
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
	if (s1)
		free(s1);
	s1 = NULL;
	new_str[i + j] = '\0';
	return (new_str);
}

char	*ft_strdup_n(const char *s1)
{
	int		len;
	char	*copie;
	int		i;

	len = 0;
	i = 0;
	while (s1[len] != '\n' && s1[len + 1] != '\0')
		len++;
	copie = malloc(sizeof(char) * (len + 1));
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
	free(s1);
	copie[len] = '\0';
	// if (*copie == '\0')
	// 	return (NULL);
	return (copie);
}
