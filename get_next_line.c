/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 17:31:22 by vboissel          #+#    #+#             */
/*   Updated: 2018/01/19 16:13:22 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		fill_file(t_file **file, char *buf)
{
	char	*tmp_str;

	if ((tmp_str = ft_strnew(ft_strlen((*file)->n_lines) + ft_strlen(buf) + 1))
	== NULL)
		return (-1);
	tmp_str = ft_strjoin((*file)->n_lines, buf);
	if (ft_strlenc(tmp_str, '\n') == ft_strlen(tmp_str) && ft_strlen(buf) != 0)
	{
		free((*file)->n_lines);
		if (((*file)->n_lines = ft_strdup(tmp_str)) == NULL)
			return (-1);
		free(tmp_str);
		return (1);
	}
	(*file)->c_line = ft_strsub(tmp_str, 0, ft_strlenc(tmp_str, '\n'));
	(*file)->n_lines = ft_strsub(tmp_str, ft_strlenc(tmp_str, '\n') + 1,
	ft_strlen(tmp_str));
	free(tmp_str);
	if (!(*file)->c_line || !(*file)->n_lines)
		return (-1);
	return (0);
}

int		read_file(t_file **file)
{
	char	buf[BUFF_SIZE + 1];
	int		res_fill;
	int		res_read;

	ft_bzero(buf, BUFF_SIZE + 1);
	printf("test\n");
	while (read((*file)->fd, buf, BUFF_SIZE))
	{
		printf("test\n");
		res_fill = fill_file(&(*file), buf);
		if (res_fill == -1)
			return (-1);
		if (res_fill == 0)
			return (ft_strlen((*file)->c_line) > 0 ? 1 : 0);
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	if (res_read == -1)
		return (-1);
	fill_file(&(*file), buf);
	return (ft_strlen((*file)->c_line) > 0 ? 1 : 0);
}

int		prelim_checks(const int fd, t_file **file)
{
	if (fd < 0)
		return (-1);
	if (!(*file))
	{
		if (((*file) = malloc(sizeof(t_file))) == NULL)
			return (-1);
		(*file)->fd = fd;
		(*file)->c_line = ft_strnew(0);
		(*file)->n_lines = ft_strnew(0);
	}
	if (fd != (*file)->fd)
		return (-1);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_file	*file;
	int				res;

	if (prelim_checks(fd, &file))
		return (-1);
	res = read_file(&file);
	if (res != -1)
		*line = ft_strdup(file->c_line);
	return (res);
}

int		main(int argc, char const *argv[])
{
	int		fd;
	int		res_gnl;
	char	*line;

	res_gnl = get_next_line(fd, &line);
	printf("%d\n", res_gnl);
	if (line)
	{
		printf("%s\n", line);
	}
	else
		printf("empty return\n");
	return (0);
}
