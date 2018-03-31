/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitcnt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 16:33:28 by vboissel          #+#    #+#             */
/*   Updated: 2018/02/09 15:40:02 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strsplitcnt(char const *s, char c)
{
	size_t	words;
	size_t	i;

	if (s == NULL || !c)
		return (0);
	i = 0;
	words = 0;
	while (i < ft_strlen(s))
	{
		words = (s[i] != c && (s[i - 1] == c || !i)) ? words + 1 : words;
		i++;
	}
	return (words - 1);
}
