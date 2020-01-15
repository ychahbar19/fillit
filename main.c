/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 11:57:30 by ychahbar          #+#    #+#             */
/*   Updated: 2019/02/27 10:39:25 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	clean_all(t_tetri *first_tetri, t_map *map, int fd)
{
	del_all_tetri(first_tetri);
	free(map);
	close(fd);
	ft_putendl("error");
	return (-1);
}

int			main(int argc, char **argv)
{
	t_tetri		*first_tetri;
	t_map		*map;
	int			fd;

	map = NULL;
	first_tetri = NULL;
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit filename");
		return (-1);
	}
	if (((fd = open(argv[1], O_RDONLY)) < 0) ||
	(!(first_tetri = new_tetri())) ||
	(check_reader(fd, first_tetri) == -1) ||
	(count_tetris_index(first_tetri) == -1) ||
	(check_links_tetri(first_tetri) == -1))
		return (clean_all(first_tetri, map, fd));
	if (((map = map_initialisation()) == NULL) ||
	((map = new_map(map)) == NULL) ||
	(tetri_solver(first_tetri, map) == -1))
		return (clean_all(first_tetri, map, fd));
	close(fd);
	return (0);
}
