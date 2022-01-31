/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:14:11 by amarini-          #+#    #+#             */
/*   Updated: 2022/01/31 12:59:33 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_FILE_H
# define FT_GET_FILE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

int		find_newline(char *str, int read);
int		read_fd(int fd, int *index, char **leftover);
int		get_next_line(int fd, char **line);
int		del_leftover(char	**leftover, int ret);

char	*gnl_substr(char *str, int start, int len, int line);
char	*gnl_strdup(const char *s1);
int		gnl_strlen(const char *s);
char	*gnl_fill_str(char const *src, char *dst, int index);
char	*gnl_strjoin(char const *s1, char const *s2);

int		ft_get_file(char *path, char ***content);
int		ft_count_lines(char *path);

#endif
