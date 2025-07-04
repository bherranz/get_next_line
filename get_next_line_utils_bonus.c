/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bherranz <bherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:47:01 by bherranz          #+#    #+#             */
/*   Updated: 2024/02/19 12:56:26 by bherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (s[count])
		count++;
	return (count);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ip;
	size_t			total;

	total = count * size;
	ip = malloc (total);
	if (!ip)
		return (NULL);
	while (total > 0)
	{
		ip[total - 1] = '\0';
		total--;
	}
	return (ip);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	if (!s)
		return (NULL);
	while (*s)
	{
		if (uc == *s)
			return ((char *)s);
		s++;
	}
	if (uc == *s)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (!s2)
		return (NULL);
	new = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i])
		{
			new[i] = s1[i];
			i++;
		}
		free(s1);
	}
	while (s2[j])
		new[i++] = s2[j++];
	return (new);
}

char	*ft_substr(char *s, unsigned int start, size_t sub_len)
{
	char	*sub;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_calloc(1, sizeof(char)));
	if (sub_len > s_len - start)
		sub_len = s_len - start;
	sub = ft_calloc(sub_len + 1, sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while ((sub_len > i) && s[start])
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	return (sub);
}
