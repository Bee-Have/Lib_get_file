/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:14:11 by amarini-          #+#    #+#             */
/*   Updated: 2022/01/28 19:05:15 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_FILE_H
# define FT_GET_FILE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

int		find_newline(char *str, int read);
int		read_fd(int fd, int *index, char **leftover);
int		get_next_line(int fd, char **line);
int		del_leftover(char	**leftover, int ret);

char	*gnl_substr(char *str, int start, int len, int line);

int		ft_get_file(char *path, char ***content);
int		ft_count_lines(char *path);

#endif
