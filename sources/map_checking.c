/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:58:06 by chhoflac          #+#    #+#             */
/*   Updated: 2024/03/26 22:35:23 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_bordlines(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\n' && line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_midlines(char *line)
{
	size_t	size;

	size = 0;
	while (line[size] != '\n')
		size++;
	if (line[0] != '1' && line[size - 1] != '1')
		return (0);
	return (1);
}

int	ft_check_shape(char **map)
{
	size_t	i;

	i = 0;
	while (map[i + 1])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[i + 1]))
			return (0);
		i++;
	}
	if (i + 1 == ft_strlen(map[i]))
		return (0);
	return (1);
}

int	ft_check_forbidden_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr("10ECP", map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
