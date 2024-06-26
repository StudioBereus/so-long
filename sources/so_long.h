/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:32:31 by chhoflac          #+#    #+#             */
/*   Updated: 2024/03/27 14:42:26 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <string.h>
# include <errno.h>
# include "../MLX/include/MLX42/MLX42.h"

typedef struct s_elements
{
	int		collectibles;
	int		start;
	int		exit;
}	t_elements;

typedef struct s_position
{
	int		x;
	int		y;
}	t_pos;

typedef struct s_graphics
{
	mlx_image_t	*sup[4];
	mlx_image_t	*ground;
}	t_graphics;

typedef struct s_game
{
	mlx_t		*mlx;
	t_graphics	graphics;
	t_pos		pos_player;
	char		**map;
	int			s_x;
	int			s_y;
	int			fd;
	int			able_exit;
	int			collectibles;
}	t_game;

int			ft_check_extension(char *f);
int			ft_check_bordlines(char *line);
int			ft_check_midlines(char *line);
void		ft_get_elements(char *line, t_elements *elements);
t_elements	ft_set_struct(char **map);
char		**ft_stock_map(int fd);
int			ft_check_elements(t_elements count);
int			ft_check_shape(char **map);
void		ft_start_flood(char **map, t_elements *elements);
int			ft_check_forbidden_char(char **map);
int			ft_compare(t_elements cnt, t_elements cnt2);
char		**ft_setting(t_elements cnt1, int fd, t_game *game);
void		ft_clear(char **map);
int			ft_map_size_check(t_game *game);

void		keyboard_hook_count(mlx_key_data_t key_enter, void *game);

mlx_image_t	*ft_background(char **map, mlx_t *mlx);
void		ft_display_elements(char **map, mlx_t *mlx, t_graphics *graphics);
void		ft_clean_img(mlx_t *mlx, mlx_image_t **stock);
void		ft_graphics_set(t_game *game);
mlx_image_t	**ft_img_stock(mlx_t *mlx, t_graphics *graphics);
void		clean_graphics(mlx_t *mlx, t_graphics g);
t_elements	ft_set_cnt(void);
char		**ft_mapcopy(char **map);
char		**ft_setting(t_elements cnt1, int fd, t_game *game);

#endif
