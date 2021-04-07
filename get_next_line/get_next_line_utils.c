/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-haih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 13:12:53 by mel-haih          #+#    #+#             */
/*   Updated: 2020/02/08 13:12:54 by mel-haih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(const char *s)
{
	int len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_memcat(char *s1, char *s2)
{
	char	*ret;

	if (!(ret = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	ret[0] = 0;
	if (!(ft_strcat(ret, s1)) || !(ft_strcat(ret, s2)))
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}

char	*ft_strdup(const char *str)
{
	char	*ret;
	int		len;

	len = 0;
	while (str[len])
		len++;
	ret = malloc(len + 1);
	if (!ret)
		return (NULL);
	ret[len] = 0;
	while (len--)
		ret[len] = str[len];
	return (ret);
}

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (!c)
		return ((char*)(s + ft_strlen(s)));
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char*)s + i);
		i++;
	}
	if (!c)
		return ((char*)s);
	return (NULL);
}

char	*ft_strcat(char *s1, char *s2)
{
	char *save;

	save = s1;
	while (*s1)
		s1++;
	while (*s2)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = 0;
	s1 = save;
	return (s1);
}
