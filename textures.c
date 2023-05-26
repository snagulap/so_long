/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:00:34 by snagulap          #+#    #+#             */
/*   Updated: 2023/05/26 11:57:01 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_position(t_data *data)
{
	data->i = 0;
	while (data->map[data->i])
	{
		data->j = 0;
		while (data->map[data->i][data->j])
		{
			if (data->map[data->i][data->j] == 'P')
				return ;
			data->j++;
		}
		data->i++;
	}
}

void	textures(t_data *data)
{
	data->wall = mlx_load_png("./images/wall.png");
	data->wallimg = mlx_texture_to_image(data->mlx, data->wall);
	data->player = mlx_load_png("./images/player.png");
	data->pimg = mlx_texture_to_image(data->mlx, data->player);
	data->xit = mlx_load_png("./images/basic2.png");
	data->exitimg = mlx_texture_to_image(data->mlx, data->xit);
	data->col = mlx_load_png("./images/collectibles.png");
	data->colimg = mlx_texture_to_image(data->mlx, data->col);
}

void	map_construct(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	textures(data);
	player_position(data);
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				mlx_image_to_window(data->mlx, data->wallimg, j * 60, i * 84);
			else if (data->map[i][j] == 'P')
				mlx_image_to_window(data->mlx, data->pimg, j * 60, i * 84);
			else if (data->map[i][j] == 'C')
				mlx_image_to_window(data->mlx, data->colimg, j * 60, i * 84);
			else if (data->map[i][j] == 'E')
				mlx_image_to_window(data->mlx, data->exitimg, j * 60, i * 84);
			j++;
		}
		i++;
	}
}

void	print_screen(t_data *data)
{
	data->steps_str = ft_itoa(data->steps);
	if (data->str_steps)
		mlx_delete_image(data->mlx, data->str_steps);
	data->str_steps = mlx_put_string(data->mlx, data->steps_str, 12, 5);
	free(data->steps_str);
}

void	player_render(void *param)
{
	t_data	*data;

	data = param;
	mlx_delete_image(data->mlx, data->pimg);
	data->pimg = mlx_texture_to_image(data->mlx, data->player);
	mlx_image_to_window(data->mlx, data->pimg, data->j * 60, data->i * 84);
}
