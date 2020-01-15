/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 11:59:29 by ychahbar          #+#    #+#             */
/*   Updated: 2019/01/08 12:01:17 by ychahbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*new_map(t_map *map)
{
	int		i;

	i = 0;
	map->size = map->size + 1;
	if (!(map->str = (char **)malloc(sizeof(char *) * (map->size + 1))))
		return (NULL);
	while (i < (map->size + 1))
	{
		if (!(map->str[i] = (char *)malloc(sizeof(char) * (map->size + 1))))
			return (NULL);
		i++;
	}
	return (map);
}

t_map	*map_initialisation(void)
{
	t_map		*map;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	map->size = 1;
	return (map);
}

int		map_generator(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->size)
	{
		*map->str[map->size] = '\0';
		j = 0;
		while (j < map->size)
		{
			map->str[i][map->size] = '\0';
			map->str[i][j] = '.';
			j++;
		}
		i++;
	}
	return (0);
}

int		remove_tetri_from_map(t_tetri *tetri, t_map *map, int position)
{
	int		i;
	int		j;
	int		k;
	int		position_map;

	k = 0;
	while (k < 4)
	{
		position_map = position + ((tetri->position_blocks[k][0]) * map->size)
		+ (tetri->position_blocks[k][1]);
		i = position_map / map->size;
		j = position_map % map->size;
		map->str[i][j] = '.';
		k++;
	}
	return (0);
}

int		delete_map(t_map *map)
{
	int		i;

	i = map->size;
	while (i >= 0)
	{
		free(map->str[i]);
		map->str[i] = NULL;
		i--;
	}
	free(map->str);
	return (0);
}
