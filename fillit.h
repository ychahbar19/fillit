/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 11:44:00 by ychahbar          #+#    #+#             */
/*   Updated: 2019/02/27 10:15:34 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>
# include "libft.h"
# define BUFF_SIZE 30

typedef struct		s_tetri
{
	int				height;
	int				width;
	int				count_bloc;
	char			str[5][5];
	int				position_blocks[4][2];
	int				count_line;
	int				count_link;
	int				count_dot;
	char			ascii;
	struct s_tetri	*next;
}					t_tetri;

typedef struct		s_map
{
	int				size;
	char			**str;
}					t_map;

/*
** Checking Program Entry
*/
int					check_reader(int fd, t_tetri *tetri);
int					check_links_tetri(t_tetri *tetri);
int					check_last_line(int i, char *line);
int					count_tetris_index(t_tetri *tetri);
int					check_line(char *line, t_tetri *tetri);
int					is_valid_line(char *line, t_tetri *tetri, char *s);
int					no_valid_file(char *line, t_tetri *tetri, char *s);
int					valid_tetri(char *line, t_tetri *tetri);
int					get_nxt_line(const int fd, char **line, char **s);

/*
** Tetri
*/
t_tetri				*new_tetri(void);
int					add_tetri_to_last(t_tetri *first_tetri,
		t_tetri *new_tetri);
int					rename_tetriminos(t_tetri *tetri, int i);
int					get_width_tetri(t_tetri *tetri);
int					get_height_tetri(t_tetri *tetri);
int					get_position_blocks(t_tetri *tetri);
void				tetri_manager(t_tetri *tetri);
void				del_all_tetri(t_tetri *tetri);

/*
** Map
*/
t_map				*map_initialisation(void);
t_map				*new_map(t_map *map);
int					delete_map(t_map *map);
int					remove_tetri_from_map(t_tetri *tetri, t_map *map,
		int position);
int					map_generator(t_map *map);
void				print_map(t_map *map);

/*
** Solving For The Smallest Square Of Tetrominos
*/
int					tetri_solver(t_tetri *tetri, t_map *map);
#endif
