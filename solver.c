/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:02:36 by ychahbar          #+#    #+#             */
/*   Updated: 2019/01/30 11:33:38 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		can_place_tetri(t_tetri *tetri, t_map *map, int position)
{
	int		i;
	int		j;
	int		k;
	int		position_map;
	int		can_place;

	i = 0;
	can_place = 0;
	while (i < 4)
	{
		j = position / map->size + tetri->position_blocks[i][0];
		k = position % map->size + tetri->position_blocks[i][1];
		position_map = (j * map->size) + k;
		if (position_map >= (map->size * map->size))
			return (0);
		if (map->str[j][k] && (map->str[j][k] == '.'))
			can_place++;
		i++;
	}
	if (can_place == 4)
		return (1);
	return (0);
}

static int		place_tetri(t_tetri *tetri, t_map *map, int position)
{
	int		i;
	int		j;
	int		k;
	int		position_map;

	i = 0;
	while (i < 4)
	{
		position_map = position + (tetri->position_blocks[i][0]
			* map->size) + tetri->position_blocks[i][1];
		if (position_map == (map->size * map->size))
			return (-1);
		j = position / map->size + tetri->position_blocks[i][0];
		k = position % map->size + tetri->position_blocks[i][1];
		if (map->str[j][k] && map->str[j][k] == '.')
			map->str[j][k] = tetri->ascii;
		i++;
	}
	return (0);
}

static int		solver(t_tetri *tetri, t_map *map, int position)
{
	int		height_min;
	int		width_min;

	if (tetri == NULL)
		return (1);
	width_min = (tetri->width) + (position % map->size);
	height_min = (tetri->height) + (position / map->size);
	while (position < (map->size * map->size))
	{
		if ((width_min > map->size) || (height_min > map->size))
			return (0);
		if (can_place_tetri(tetri, map, position) == 1)
		{
			place_tetri(tetri, map, position);
			if (solver(tetri->next, map, 0))
				return (1);
			remove_tetri_from_map(tetri, map, position);
		}
		position++;
	}
	return (0);
}

static int		fillit(t_tetri *tetri, t_map *map)
{
	while (!(solver(tetri, map, 0)))
	{
		delete_map(map);
		if (!(map = new_map(map)))
			return (-1);
		map_generator(map);
	}
	return (0);
}

int				tetri_solver(t_tetri *tetri, t_map *map)
{
	tetri_manager(tetri);
	map_generator(map);
	if (fillit(tetri, map) == -1)
		return (-1);
	print_map(map);
	delete_map(map);
	del_all_tetri(tetri);
	free(map);
	return (0);
}
