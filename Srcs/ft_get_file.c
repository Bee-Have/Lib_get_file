/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:13:03 by amarini-          #+#    #+#             */
/*   Updated: 2021/08/31 19:03:59 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_get_file.h"

int	ft_count_lines(char *path)
{
	int		result;
	int		has_read;
	int		fd;
	char	*line;

	result = 0;
	has_read = 1;
	line = ft_strdup("");
	fd = open(path, O_RDONLY);
	if (read(fd, line, 1) <= 0)
	{
		free(line);
		return (-1);
	}
	free(line);
	close(fd);
	fd = open(path, O_RDONLY);
	while (has_read > 0 && has_read != -1)
	{
		has_read = get_next_line(fd, &line);
		free(line);
		result++;
	}
	close(fd);
	return (result);
}

int	ft_get_file(char *path, char ***content)
{
	int		length;
	int		index;
	int		read;
	int		fd;

	index = 0;
	read = 1;
	length = ft_count_lines(path);
	fd = open(path, O_RDONLY);
	if (length < 0)
		return (-1);
	(*content) = (char **)malloc((length + 1) * sizeof(char *));
	if (!(*content))
		return (-1);
	(*content)[length] = NULL;
	while (read > 0 && read != -1 && index < length)
	{
		read = get_next_line(fd, &(*content)[index]);
		index++;
	}
	if (read == -1)
		return (-1);
	close(fd);
	return (1);
}
