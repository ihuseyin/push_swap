#include "checker.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (*s++)
	{
		length++;
	}
	return (length);
}

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*original_dst;

	original_dst = dst;
	while (*src && n)
	{
		*dst++ = *src++;
		n--;
	}
	*dst = '\0';
	return (original_dst);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if ((char)c == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*result;

	result = malloc(ft_strlen(s) + 1);
	if (!result)
		return (NULL);
	ft_strncpy(result, s, ft_strlen(s));
	return (result);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	if (s1)
		len1 = ft_strlen(s1);
	else
		len1 = 0;
	len2 = ft_strlen(s2);
	result = malloc(len1 + len2 + 1);
	if (!result)
		return (NULL);
	if (len1)
		ft_strncpy(result, s1, len1);
	ft_strncpy(result + len1, s2, len2);
	free(s1);
	return (result);
}
