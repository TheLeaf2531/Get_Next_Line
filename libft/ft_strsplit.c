/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:33:35 by vboissel          #+#    #+#             */
/*   Updated: 2017/12/16 21:07:13 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	words;
	size_t	i;
	size_t	y;

	if (s == NULL || !c)
		return (NULL);
	i = -1;
	words = 0;
	while (++i < ft_strlen(s))
		words = (s[i] != c && (s[i - 1] == c || !i)) ? words + 1 : words;
	if ((tab = malloc(sizeof(char*) * (words + 1))) == NULL)
		return (NULL);
	i = -1;
	words = -1;
	while (s[++i])
	{
		if (s[i] != c && (s[i - 1] == c || !i))
			y = i;
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			tab[++words] = ft_strsub(s, y, i - y + 1);
	}
	tab[words + 1] = NULL;
	return (tab);
}
