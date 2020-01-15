/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width_tetri.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 11:56:09 by ychahbar          #+#    #+#             */
/*   Updated: 2019/02/22 12:30:50 by ychahbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		get_x_start(t_tetri *tetri)
{
	int		i;
	int		x_start;

	i = 0;
	x_start = 0;
	while ((i < 4) && (tetri->str[i][x_start] == '.'))
	{
		if ((i == 3) && (tetri->str[3][x_start] == '.'))
		{
			x_start++;
			i = 0;
		}
		else
			i++;
	}
	return (x_start);
}

static int		get_x_end(t_tetri *tetri)
{
	int		i;
	int		x_end;

	i = 0;
	x_end = 3;
	while ((i < 4) && (tetri->str[i][x_end] == '.'))
	{
		if ((i == 3) && (tetri->str[3][x_end] == '.'))
		{
			x_end--;
			i = 0;
		}
		else
			i++;
	}
	return (x_end);
}

int				get_width_tetri(t_tetri *tetri)
{
	int		x_start;
	int		x_end;

	x_start = get_x_start(tetri);
	x_end = get_x_end(tetri);
	tetri->width = (x_end - x_start) + 1;
	return (0);
}
