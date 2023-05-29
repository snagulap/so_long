/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:06:05 by snagulap          #+#    #+#             */
/*   Updated: 2023/05/26 20:47:20 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hook(mlx_key_data_t key_data, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)
		mlx_close_window(data->mlx);
	else if (key_data.key == MLX_KEY_D && key_data.action == MLX_PRESS)
		key_pressed_d(data);
	else if (key_data.key == MLX_KEY_W && key_data.action == MLX_PRESS)
		key_pressed_w(data);
	else if (key_data.key == MLX_KEY_S && key_data.action == MLX_PRESS)
		key_pressed_s(data);
	else if (key_data.key == MLX_KEY_A && key_data.action == MLX_PRESS)
		key_pressed_a(data);
}

int	check(t_data *data)
{
	if (check_map1(data, 0, 0)
		&& check_map(data, 0, 0)
		&& check_count(data, 'E') == 1
		&& check_count(data, 'P') == 1
		&& check_count(data, 'C') != 0
		&& valid_path(data)
		&& rect_check(data))
		return (ft_free(data->map), ft_free(data->map1), 0);
	ft_printf("Error\nmap invalid\n");
	return (1);
}

int	start(char *data)
{
	t_data	*d;
	mlx_t	*mlx;

	d = malloc(sizeof(t_data));
	if (d == NULL)
		return (0);
	d->name = data;
	creat_map(d);
	d->width = width(d->name);
	d->height = height(d->name);
	d->steps = 0;
	d->collectibles = 0;
	d->col_count = col_count(d);
	if (check(d))
		return (0);
	d->mlx = mlx_init((d->width -1) * 60, (d->height) * 84, "game", false);
	map_construct(d);
	mlx_key_hook(d->mlx, &ft_hook, d);
	mlx_loop_hook(d->mlx, &player_render, d);
	print_screen(d);
	mlx_loop(d->mlx);
	free_img(d);
	return (0);
}

int	main( int argc, char **argv)
{
	int	i;

	if (argc != 2)
	{
		write(1, "Please give valid .ber file", 27);
		return (0);
	}
	i = check_filename(argv[1]);
	if (i == 1)
	{
		printf("Error\nmap invalid\n");
		return (0);
	}
	start(argv[1]);
	return (0);
}
