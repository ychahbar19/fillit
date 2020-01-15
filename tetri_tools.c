/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:04:18 by ychahbar          #+#    #+#             */
/*   Updated: 2019/01/28 18:52:52 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			del_all_tetri(t_tetri *tetri)
{
	t_tetri *tmp;

	tmp = tetri;
	while (tmp)
	{
		tetri = tetri->next;
		free(tmp);
		tmp = tetri;
	}
}

t_tetri			*new_tetri(void)
{
	t_tetri		*tetri;

	if (!(tetri = (t_tetri *)malloc(sizeof(*tetri))))
		return (NULL);
	tetri->height = 0;
	tetri->width = 0;
	tetri->count_bloc = 0;
	tetri->count_line = 0;
	tetri->count_link = 0;
	tetri->count_dot = 0;
	tetri->ascii = 65;
	tetri->next = NULL;
	return (tetri);
}

int				add_tetri_to_last(t_tetri *first_tetri, t_tetri *new_tetri)
{
	t_tetri		*tmp;

	if (!(first_tetri) || !(new_tetri))
		return (-1);
	tmp = first_tetri;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_tetri;
	return (0);
}

int				rename_tetriminos(t_tetri *tetri, int k)
{
	int			i;
	int			j;

	i = -1;
	tetri->ascii += k;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (tetri->str[i][j] == '#')
				tetri->str[i][j] = tetri->ascii;
		}
	}
	return (0);
}

void			tetri_manager(t_tetri *tetri)
{
	int			j;

	j = 0;
	while (tetri)
	{
		get_width_tetri(tetri);
		get_height_tetri(tetri);
		get_position_blocks(tetri);
		rename_tetriminos(tetri, j);
		j++;
		tetri = tetri->next;
	}
}
