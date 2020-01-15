/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:01:58 by ychahbar          #+#    #+#             */
/*   Updated: 2019/01/08 12:02:32 by ychahbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_tetri(t_tetri *tetri)
{
	int		i;

	i = 0;
	while (*tetri->str[i] != '\0')
	{
		ft_putendl(tetri->str[i]);
		i++;
	}
	ft_putchar('\n');
}

void	print_map(t_map *map)
{
	int		i;

	i = 0;
	while (*map->str[i] != '\0')
	{
		ft_putendl(map->str[i]);
		i++;
	}
}
