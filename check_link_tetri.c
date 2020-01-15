/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_link_tetri.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 09:17:27 by asouat            #+#    #+#             */
/*   Updated: 2019/01/30 11:37:04 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		count_link_tetri(t_tetri *tetri, int i, int j)
{
	if (tetri->str[i][j] == '#' && tetri->str[i][j + 1] == '#')
		tetri->count_link += 1;
	if (tetri->str[i][j] == '#' && tetri->str[i][j - 1] == '#')
		tetri->count_link += 1;
	if (tetri->str[i][j] == '#' && tetri->str[i + 1][j] == '#')
		tetri->count_link += 1;
	if (tetri->str[i][j] == '#' && tetri->str[i - 1][j] == '#')
		tetri->count_link += 1;
}

int				check_links_tetri(t_tetri *tetri)
{
	int		i;
	int		j;

	while (tetri)
	{
		i = -1;
		while (++i < 4)
		{
			j = -1;
			while (++j < 4)
				count_link_tetri(tetri, i, j);
		}
		if (tetri->count_link < 6)
			return (-1);
		tetri = tetri->next;
	}
	return (0);
}

int				count_tetris_index(t_tetri *tetri)
{
	int		tetris_index;

	tetris_index = 0;
	while (tetri)
	{
		tetris_index++;
		tetri = tetri->next;
	}
	if (tetris_index > 26)
		return (-1);
	return (0);
}
