/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:33:08 by gholloco          #+#    #+#             */
/*   Updated: 2024/03/19 17:30:05 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substrr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	if (i - start < len)
		len = i - start;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (len > 0 && s[start])
	{
		sub[i] = s[start];
		start++;
		i++;
		len--;
	}
	sub[i] = 0;
	free(s);
	return (sub);
}

char	*ft_strjoinn(char *s1, char const *s2)
{
	int		i;
	int		j;
	int		index;
	char	*joined;

	i = 0;
	j = 0;
	index = 0;
	if (!s1)
		return (ft_strdup(s2));
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	joined = malloc(sizeof(char) * (i + j + 1));
	if (!joined)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		joined[index++] = s1[i++];
	while (s2[j])
		joined[index++] = s2[j++];
	joined[index] = 0;
	return (free(s1), joined);
}

char	*ft_strcpyy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*tab;

	i = 0;
	while (src[i])
		i++;
	tab = NULL;
	tab = malloc(sizeof(char) * (i + 1));
	if (tab == NULL)
		return (tab);
	ft_strcpyy(tab, src);
	return (tab);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (*(s + i))
	{
		if ((unsigned char) *(s + i) == (char) c)
			return ((char *)(s + i));
		i++;
	}
	if ((unsigned char) *(s + i) == (char) c)
		return ((char *)(s + i));
	return (NULL);
}
