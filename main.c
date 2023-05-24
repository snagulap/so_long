/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:06:05 by snagulap          #+#    #+#             */
/*   Updated: 2023/05/24 15:51:25 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hook(void *param)
{
	t_data	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W)
		|| mlx_is_key_down(data->mlx, MLX_KEY_UP))
		key_pressed_w(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S)
		|| mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		key_pressed_s(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A)
		|| mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		key_pressed_a(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D)
		|| mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		key_pressed_d(data);
}

int	check(t_data *data)
{
	if (check_map1(data, 0, 0)
		&& check_map(data, 0, 0)
		&& check_count(data, 'E') == 1
		&& check_count(data, 'P') == 1
		&& check_count(data, 'C') != 0
		&& valid_path(data))
		return (0);
	return (1);
}

int	start(char *data)
{
	t_data	*d;
	mlx_t	*mlx;

	d = malloc(sizeof(t_data));
	if (d == NULL)
		return (0);
	d->name = ft_strjoin("./maps/", data);
	creat_map(d);
	d->width = width(d->name);
	d->height = height(d->name);
	d->steps = 0;
	d->collectibles = 0;
	d->col_count = col_count(d);
	if (check(d))
	{
		ft_printf("Error\nmap invalid\n");
		return (0);
	}
	d->mlx = mlx_init((d->width -1) * 60, (d->height) * 84, "game", false);
	map_construct(d);
	mlx_loop_hook(d->mlx, &ft_hook, d);
	print_screen(d);
	mlx_loop(d->mlx);
	free_img(d);
	return (0);
}

int	main( int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "Please give valid .ber file", 27);
		return (0);
	}
	else if (check_filename(argv[1]))
	{
		start(argv[1]);
	}
	return (0);
}
