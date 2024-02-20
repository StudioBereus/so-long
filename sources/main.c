/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:47:24 by chhoflac          #+#    #+#             */
/*   Updated: 2024/02/20 15:22:03 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//delete it 
//void	ft_display_info(t_elements count, int fd);

int		ft_check_extension(char *f)
{
	int		sze;

	sze = ft_strlen(f);
	if ((sze >= 5) && (f[sze - 1] == 'r' && f[sze - 2] == 'e'
			&& f[sze - 3] == 'b' && f[sze - 4] == '.'))
		return (1);
	return (0);
}

void	ft_display_info(char **map, t_elements count, char *path)
{
	int	i;

	i = 0;
	ft_printf("%s", path);
		ft_printf("\n----------\n");
	while (map[i])
	{
		ft_printf("%s", map[i]);
		i++;
	}
	ft_printf("\n----------\n");
	i = 0;
	while (map[i])
	{
		ft_printf("%d\n", ft_strlen(map[i]));
		i++;
	}
	ft_printf("----------\n");
	ft_printf("player : %d\n", count.start);
	ft_printf("collectibles : %d\n", count.collectibles);
	ft_printf("exit : %d", count.exit);
	ft_printf("\n----------\n");
	if (ft_check_equal(map))
		ft_printf("map ok");
	else if (!ft_check_equal(map))
		ft_printf("map not ok");
}

int		main(int argc, char **argv)
{
	char		**map;
	char		*path;
	int			fd;
	t_elements	count;

	if (argc == 2)
	{
		path = argv[1];
		fd = open(path, O_RDONLY);
		map = ft_stock_map(fd);
		count = ft_set_struct(map);
		ft_display_info(map, count, path);
		close(fd);
	}
}
