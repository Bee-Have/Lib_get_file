/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 11:03:00 by amarini-          #+#    #+#             */
/*   Updated: 2022/01/31 12:59:06 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_file.h"

char	*gnl_substr(char *str, int start, int len, int line)
{
	int		i;
	char	*result;

	i = 0;
	if (line == 0 && start == 0)
	{
		start = gnl_strlen(str) - 1;
		len = 0;
	}
	if (line == 1 && str[start] == '\n')
		start++;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (str[start] != '\0' && i < len)
	{
		result[i] = str[start];
		i++;
		start++;
	}
	if (line == 0)
		free(str);
	return (result);
}

char	*gnl_strdup(const char *s1)
{
	int		i;
	char	*cp;

	i = 0;
	cp = (char *)malloc(sizeof(char) * (gnl_strlen(s1) + 1));
	if (!cp)
		return (NULL);
	cp[gnl_strlen(s1)] = '\0';
	while (s1[i] != '\0')
	{
		cp[i] = s1[i];
		i++;
	}
	return (cp);
}

int	gnl_strlen(const char *s)
{
	int		len;

	len = 0;
	if (!s)
		return (0);
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*gnl_fill_str(char const *src, char *dst, int index)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[index] = src[i];
		i++;
		index++;
	}
	return (dst);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	int		j;
	char	*str;

	j = 0;
	if (!s1 && !s2)
		return (NULL);
	else if (!s1 && s2)
		return (gnl_strdup(s2));
	else if (!s2 && s1)
		return (gnl_strdup(s1));
	str = (char *)malloc((gnl_strlen(s1) + gnl_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str = gnl_fill_str(s1, str, j);
	j += gnl_strlen(s1);
	str = gnl_fill_str(s2, str, j);
	j += gnl_strlen(s2);
	str[j] = '\0';
	return (str);
}
