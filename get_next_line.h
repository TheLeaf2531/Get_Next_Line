/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 18:43:25 by vboissel          #+#    #+#             */
/*   Updated: 2018/03/30 19:06:38 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFF_SIZE 128

int		get_next_line(const int fd, char **line);

#endif
