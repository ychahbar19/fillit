/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_height_tetri.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 11:49:52 by ychahbar          #+#    #+#             */
/*   Updated: 2019/01/08 11:49:54 by ychahbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	get_y_start(t_tetri *tetri)
{
	int i;
	int y_start;

	i = 0;
	y_start = 0;
	while ((i < 4) && (tetri->str[y_start][i] == '.'))
	{
		if ((i == 3) && (tetri->str[y_start][3] == '.'))
		{
			y_start++;
			i = 0;
		}
		else
			i++;
	}
	return (y_start);
}

static int	get_y_end(t_tetri *tetri)
{
	int i;
	int y_end;

	i = 0;
	y_end = 3;
	while ((i < 4) && (tetri->str[y_end][i] == '.'))
	{
		if ((i == 3) && (tetri->str[y_end][i] == '.'))
		{
			y_end--;
			i = 0;
		}
		else
			i++;
	}
	return (y_end);
}

int			get_height_tetri(t_tetri *tetri)
{
	int y_start;
	int y_end;

	y_start = get_y_start(tetri);
	y_end = get_y_end(tetri);
	tetri->height = (y_end - y_start) + 1;
	return (0);
}
