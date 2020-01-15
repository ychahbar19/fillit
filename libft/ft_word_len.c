/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:56:19 by asouat            #+#    #+#             */
/*   Updated: 2018/10/12 13:52:45 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_word_len(char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s == c)
		s++;
	while (s[i] && (s[i] != c))
		i++;
	return (i);
}