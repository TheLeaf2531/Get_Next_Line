/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 18:44:57 by vboissel          #+#    #+#             */
/*   Updated: 2018/03/30 19:05:00 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		remove_lst(t_list **lst, t_list **current)
{
	size_t	lst_size;
	size_t	i;

	i = 0;
	if ((*lst)->content_size == (*current)->content_size)
		*lst = (*current)->next;
	else
	{
		lst_size = ft_lstlen(lst);
		while (i <= lst_size)
		{
			if (ft_lstget(lst, i)->content_size == (*current)->content_size)
			{
				ft_lstget(lst, i - 1)->next = (*current)->next;
			}
			i++;
		}
	}
	ft_memdel((void**)&(*current));
}

t_list		*get_lst_fd(int fd, t_list **lst)
{
	t_list *current_file;
	size_t i;

	if (*lst != NULL)
	{
		i = 0;
		while (i <= ft_lstlen(lst))
		{
			if (ft_lstget(lst, i)->content_size == (size_t)fd)
				return (ft_lstget(lst, i));
			i++;
		}
	}
	current_file = malloc(sizeof(t_list));
	if (current_file == NULL)
		return (NULL);
	current_file->content_size = fd;
	current_file->content = ft_strnew(0);
	current_file->next = NULL;
	if (*lst == NULL)
		*lst = current_file;
	else
		ft_lstadd(lst, current_file);
	return (current_file);
}

int			get_line(t_list **current_file, char **line, int fd)
{
	char	*buf;
	char	*tmp;
	int		ret;

	buf = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		(*current_file)->content = ft_strncatf((*current_file)->content, buf);
		if (ft_fchar('\n', (*current_file)->content))
			break ;
		buf = ft_strnew(BUFF_SIZE);
	}
	if (ret >= 0 && ft_strlen((*current_file)->content) > 0)
	{
		*line = ft_strnew(ft_strlenc((*current_file)->content, '\n'));
		*line = ft_strncpy(*line, (*current_file)->content,
					ft_strlenc((*current_file)->content, '\n'));
		tmp = ft_strsub((*current_file)->content,
				ft_strlenc((*current_file)->content, '\n') + 1,
				ft_strlen((*current_file)->content));
		ft_memdel(&(*current_file)->content);
		(*current_file)->content = tmp;
		ret = 1;
	}
	return (ret);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*files;
	t_list			*current_file;
	int				ret;

	if (fd < 0 || line == 0)
		return (-1);
	current_file = get_lst_fd(fd, &files);
	if (current_file == NULL)
		return (-1);
	if ((ret = get_line(&current_file, line, fd)) <= 0)
		remove_lst(&files, &current_file);
	if (ret == 0)
		ft_memdel((void**)&(*line));
	return (ret);
}
