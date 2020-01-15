/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 11:42:55 by ychahbar          #+#    #+#             */
/*   Updated: 2019/02/12 14:53:52 by ychahbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				check_reader(int fd, t_tetri *tetri)
{
	int		i;
	char	*line;
	char	*s;

	i = 0;
	line = NULL;
	while (get_nxt_line(fd, &line, &s) > 0 && i < 5)
	{
		if (is_valid_line(line, tetri, s) == -1)
			return (-1);
		ft_strcpy(tetri->str[i++], line);
		if (valid_tetri(line, tetri))
		{
			if ((add_tetri_to_last(tetri, new_tetri()) == -1))
				return (-1);
			tetri = tetri->next;
			i = 0;
			continue;
		}
		else if (no_valid_file(line, tetri, s) == -1)
			return (-1);
		tetri->count_line++;
	}
	return (check_last_line(i, line));
}
