/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:08:14 by chhoflac          #+#    #+#             */
/*   Updated: 2024/03/26 21:30:17 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	isaccessible(t_elements *count2, char element)
{
	if (element == '1' || element == '2')
		return (0);
	else if (element == 'E')
	{
		count2->exit++;
		return (0);
	}
	else if (element == 'C')
		count2->collectibles++;
	else if (element == 'P')
		count2->start++;
	return (1);
}

void	ft_flood(char **map, t_pos pos, t_elements *count2)
{
	if (map[pos.x] && map[pos.x][pos.y]
		&& isaccessible(count2, map[pos.x][pos.y]))
	{
		map[pos.x][pos.y] = '2';
		pos.x++;
		ft_flood(map, pos, count2);
		pos.x -= 2;
		ft_flood(map, pos, count2);
		pos.x++;
		pos.y++;
		ft_flood(map, pos, count2);
		pos.y -= 2;
		ft_flood(map, pos, count2);
	}
	else if (map[pos.x][pos.y] == 'E')
		map[pos.x][pos.y] = '1';
}

void	ft_start_flood(char **map, t_elements *count2)
{
	t_pos	start;

	start.x = 0;
	while (map[start.x])
	{
		start.y = 0;
		while (map[start.x][start.y])
		{
			if (map[start.x][start.y] == 'P')
				ft_flood(map, start, count2);
			start.y++;
		}
		start.x++;
	}
}
