/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:57:18 by snagulap          #+#    #+#             */
/*   Updated: 2023/05/26 11:53:52 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./MLX42/include/MLX42/MLX42.h"
# include "./libft2/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

typedef struct data
{
	mlx_t			*mlx;
	char			*name;
	int				width;
	int				height;
	char			**map;
	char			**map1;
	char			*steps_str;
	int				i;
	int				j;
	int				steps;
	int				col_count;
	int				x;
	int				y;
	int				exit_;
	int				collectibles;
	mlx_texture_t	*wall;
	mlx_texture_t	*col;
	mlx_texture_t	*xit;
	mlx_texture_t	*player;
	mlx_texture_t	*path;
	mlx_image_t		*str_steps;
	mlx_image_t		*wallimg;
	mlx_image_t		*colimg;
	mlx_image_t		*exitimg;
	mlx_image_t		*pimg;
}	t_data;

int			start(char *data);
void		print_screen(t_data *data);
int			height(char *name);
int			width(char *name);
int			check_map1(t_data *data, int i, int j);
int			check_map(t_data *data, int i, int j);
int			check(t_data *data);
int			check_filename(char *name);
void		creat_map(t_data *data);
int			check_count(t_data *data, char c);
void		map_construct(t_data *data);
void		map(t_data *data);
void		key_pressed_w(t_data *data);
void		player_position(t_data *data);
void		key_pressed_a(t_data *data);
void		key_pressed_s(t_data *data);
void		key_pressed_d(t_data *data);
void		replacing_coins(t_data *data);
void		textures(t_data *data);
int			col_count(t_data *data);
void		path_(t_data *data, int x, int y);
void		player_check(t_data *data);
void		close_game(t_data *data);
int			valid_path(t_data *data);
void		free_img(t_data *data);
void		free_images_textures(t_data *data);
void		ft_free(char **data);
void		player_render(void *param);
#endif