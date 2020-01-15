/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position_blocks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 11:50:42 by ychahbar          #+#    #+#             */
/*   Updated: 2019/01/08 11:55:31 by ychahbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		stock_negative_block(t_tetri *tetri, int i, int j, int k)
{
	if ((tetri->position_blocks[k][0] == 0)
	&& (tetri->position_blocks[k][1] == 2)
	&& (tetri->str[i + 1][j - 2]) && (tetri->str[i + 1][j - 2] != '.')
	&& tetri->width < 4)
	{
		tetri->position_blocks[k][0] = 1;
		tetri->position_blocks[k][1] = -2;
	}
	if (tetri->position_blocks[k][0] == 0 && tetri->position_blocks[k][1] == 3
	&& tetri->str[i + 1][j - 1] && tetri->str[i + 1][j - 1] != '.')
	{
		tetri->position_blocks[k][0] = 1;
		tetri->position_blocks[k][1] = -1;
	}
	if (tetri->position_blocks[k][0] == 1 && tetri->position_blocks[k][1] == 3
	&& tetri->str[i + 2][j - 1] && tetri->str[i + 2][j - 1] != '.')
	{
		tetri->position_blocks[k][0] = 2;
		tetri->position_blocks[k][1] = -1;
	}
}

static int		get_negative_block(t_tetri *tetri)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (*tetri->str[i])
	{
		j = 0;
		while (tetri->str[i][j] && tetri->str[i][j] == '.')
			j++;
		if (tetri->str[i][j] && tetri->str[i][j] != '.')
			break ;
		i++;
	}
	k = 1;
	while (k < 4)
	{
		stock_negative_block(tetri, i, j, k);
		k++;
	}
	return (0);
}

static int		init_position(int k, int position)
{
	if (k == 0)
		position = 0;
	return (position);
}

int				get_position_blocks(t_tetri *tetri)
{
	int		i;
	int		j;
	int		k;
	int		position;

	i = -1;
	k = 0;
	position = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (tetri->str[i][j] != '.')
			{
				position = init_position(k, position);
				tetri->position_blocks[k][0] = position / 4;
				tetri->position_blocks[k][1] = position % 4;
				k++;
			}
			position++;
		}
	}
	get_negative_block(tetri);
	return (0);
}
