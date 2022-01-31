/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:16:18 by amarini-          #+#    #+#             */
/*   Updated: 2022/01/31 12:58:51 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_file.h"

int	find_newline(char *str, int read)
{
	int		i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	if ((read > 0 && read < BUFFER_SIZE)
		|| (read == 0 && gnl_strlen(str) == 0))
		return (i);
	return (-1);
}

int	read_fd(int fd, int *index, char **leftover)
{
	int		result;
	char	*buffer;
	char	*tmp;

	result = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (result > 0 && *index == -1)
	{
		if (!buffer)
			return (-1);
		result = read(fd, buffer, BUFFER_SIZE);
		buffer[result] = '\0';
		tmp = gnl_strjoin(*leftover, buffer);
		free(*leftover);
		*leftover = tmp;
		*index = find_newline(*leftover, result);
	}
	free(buffer);
	return (result);
}

int	get_next_line(int fd, char **line)
{
	static char		*leftover = NULL;
	int				result;
	int				index;

	index = -1;
	result = 1;
	if (fd == -42 && leftover)
		return (del_leftover(&leftover, 0));
	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (leftover != NULL && leftover[0] != '\0')
		index = find_newline(leftover, 0);
	if (index == -1)
		result = read_fd(fd, &index, &leftover);
	if (index == -1)
		*line = gnl_substr(leftover, 0, gnl_strlen(leftover), 1);
	else
		*line = gnl_substr(leftover, 0, index, 1);
	index++;
	leftover = gnl_substr(leftover, index, gnl_strlen(leftover) - index, 0);
	if (result == -1 || (result == 0 && gnl_strlen(leftover) == 0))
		return (del_leftover(&leftover, result));
	return (1);
}

int	del_leftover(char	**leftover, int ret)
{
	free(*leftover);
	*leftover = NULL;
	return (ret);
}
