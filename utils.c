#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cp;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen((char *)s))
		return (ft_strdup(""));
	if (len > ft_strlen((char *)s) - start)
		len = ft_strlen((char *)s) - start;
	cp = malloc((len + 1) *(sizeof(char)));
	if (!cp)
		return (0);
	while (len > 0)
	{
		cp[i] = s[start + i];
		i++;
		len--;
	}
	cp[i] = '\0';
	return (cp);
}

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*new_str;
// 	int		i;
// 	int		j;

// 	new_str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
// 	if (!new_str)
// 		return (0);
// 	i = 0;
// 	while (s1[i])
// 	{
// 		new_str[i] = s1[i];
// 		i++;
// 	}
// 	j = 0;
// 	while (s2[j])
// 	{
// 		new_str[i + j] = s2[j];
// 		j++;
// 	}
// 	new_str[i + j] = '\0';
// 	return (new_str);
// }
size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t  len;
    size_t  i;
    len = 0;
    len = ft_strlen(src);
    if (!src)
        return (0);
    i = 0;
    while (*src != '\0' && (i + 1 < dstsize))
    {
        *dst++ = *src++;
        i++;
    }
    if (dstsize > 0)
    {
        *dst = '\0';
    }
    return (len);
}
size_t  ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t  src_len;
    size_t  dst_len;
    size_t  i;
    if (!src || !dst || !src)
        return (0);
    src_len = ft_strlen(src);
    dst_len = ft_strlen(dst);
    if (dstsize == 0)
        return (src_len);
    i = 0;
    while (dst[i])
        i++;
    while (*src != '\0' && (i < dstsize - 1))
    {
        dst[i] = *src;
        i++;
        src++;
    }
    if (dstsize > 0)
        dst[i] = '\0';
    if (dstsize < i)
        return (dstsize + src_len);
    return (src_len + dst_len);
}
char    *ft_strjoin(char *s1, char *s2)
{
    char    *copie;
    copie = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!copie)
        return (0);
    ft_strlcpy(copie, s1, (ft_strlen(s1) + ft_strlen(s2)) + 1);
    ft_strlcat(copie, s2, (ft_strlen(s1) + ft_strlen(s2)) + 1);
    // free(s1);
    return (copie);
}
