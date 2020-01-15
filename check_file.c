/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 11:42:55 by ychahbar          #+#    #+#             */
/*   Updated: 2019/01/22 09:36:55 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_line(char *line)
{
	int		len_line;
	int		count_bloc;

	count_bloc = 0;
	len_line = 0;
	if (ft_strlen(line) != 4)
		return (-1);
	while (*line && (*line == '.' || *line == '#'))
	{
		if (*line == '#')
			count_bloc++;
		len_line++;
		line++;
	}
	if (*line && (len_line != 4))
		return (-1);
	return (count_bloc);
}

int		is_valid_line(char *line, t_tetri *tetri, char *s)
{
	int		count_bloc;

	count_bloc = check_line(line);
	if (*line && (count_bloc == -1))
	{
		ft_strdel(&line);
		free(s);
		return (-1);
	}
	if (count_bloc != -1)
		tetri->count_bloc += count_bloc;
	return (0);
}

int		no_valid_file(char *line, t_tetri *tetri, char *s)
{
	if ((!(*line) && (tetri->count_bloc != 4)) ||
			((tetri->count_line > 3 || tetri->count_bloc > 4)))
	{
		ft_strdel(&line);
		free(s);
		return (-1);
	}
	return (0);
}

int		valid_tetri(char *line, t_tetri *tetri)
{
	return (!(*line) && (tetri->count_bloc == 4) &&
	(tetri->count_line == 4));
}

int		check_reader(int fd, t_tetri *tetri)
{
	int		ret;
	int		i;
	char	*line;
	char	*s;

	i = 0;
	line = NULL;
	while ((ret = gnl(fd, &line, &s)) > 0)
	{
		if (is_valid_line(line, tetri, s) == -1)
			return (-1);
		ft_strcpy(tetri->str[i++], line);
		if (valid_tetri(line, tetri))
		{
			add_tetri_to_last(tetri, new_tetri());
			tetri = tetri->next;
			i = 0;
			continue;
		}
		else if (no_valid_file(line, tetri, s) == -1)
			return (-1);
		tetri->count_line++;
	}
	ft_strdel(&line);
	return (0);
}
