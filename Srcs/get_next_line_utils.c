/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 11:03:00 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/19 12:43:29 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_get_file.h"

char	*gnl_substr(char *str, int start, int len, int line)
{
	int		i;
	char	*result;

	i = 0;
	if (line == 0 && start == 0)
	{
		start = ft_strlen(str) - 1;
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
