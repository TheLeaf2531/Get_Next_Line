/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 15:00:18 by vboissel          #+#    #+#             */
/*   Updated: 2017/12/08 17:51:42 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlenc(const char *str, char c)
{
	size_t size;

	if (str == NULL)
		return (0);
	size = 0;
	while (*str != c && *str)
	{
		str++;
		size++;
	}
	return (size);
}
