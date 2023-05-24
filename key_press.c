/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:32:59 by snagulap          #+#    #+#             */
/*   Updated: 2023/05/24 14:25:39 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_pressed_w(t_data *data)
{
	if (data->map[data->i - 1][data->j] != '1')
	{
		if (data->map[data->i - 1][data->j] == 'C')
		{
			data->map[data->i - 1][data->j] = '0';
			mlx_delete_image(data->mlx, data->colimg);
			data->colimg = mlx_texture_to_image(data->mlx, data->col);
			data->col_count--;
			replacing_coins(data);
		}
		if (data->col_count == 0 && data->map[data->i - 1][data->j] == 'E')
		{
			mlx_delete_image(data->mlx, data->pimg);
			mlx_close_window(data->mlx);
			return ;
		}
		mlx_delete_image(data->mlx, data->pimg);
		data->pimg = mlx_texture_to_image(data->mlx, data->player);
		mlx_image_to_window(data->mlx, data->pimg, (data->j) * 60, \
		(data->i - 1) * 84);
		data->i = data->i - 1;
		data->steps++;
		ft_printf("steps count:%d\n", data->steps);
		print_screen(data);
	}
}

void	key_pressed_s(t_data *data)
{
	if (data->map[data->i + 1][data->j] != '1')
	{
		if (data->map[data->i + 1][data->j] == 'C')
		{
			data->map[data->i + 1][data->j] = '0';
			mlx_delete_image(data->mlx, data->colimg);
			data->colimg = mlx_texture_to_image(data->mlx, data->col);
			data->col_count--;
			replacing_coins(data);
		}
		if (data->col_count == 0 && data->map[data->i + 1][data->j] == 'E')
		{
			mlx_delete_image(data->mlx, data->pimg);
			mlx_close_window(data->mlx);
			return ;
		}
		mlx_delete_image(data->mlx, data->pimg);
		data->pimg = mlx_texture_to_image(data->mlx, data->player);
		mlx_image_to_window(data->mlx, data->pimg, (data->j) * 60, \
		(data->i + 1) * 84);
		data->i = data->i + 1;
		data->steps++;
		ft_printf("steps count:%d\n", data->steps);
		print_screen(data);
	}
}

void	key_pressed_a(t_data *data)
{
	if (data->map[data->i][data->j - 1] != '1')
	{
		data->j = data->j - 1;
		if (data->map[data->i][data->j] == 'C')
		{
			data->map[data->i][data->j] = '0';
			mlx_delete_image(data->mlx, data->colimg);
			data->colimg = mlx_texture_to_image(data->mlx, data->col);
			data->col_count--;
			replacing_coins(data);
		}	
		if (data->col_count == 0 && data->map[data->i][data->j - 1] == 'E')
		{
			mlx_delete_image(data->mlx, data->pimg);
			mlx_close_window(data->mlx);
			return ;
		}
		mlx_delete_image(data->mlx, data->pimg);
		data->pimg = mlx_texture_to_image(data->mlx, data->player);
		mlx_image_to_window(data->mlx, data->pimg, data->j * 60, \
		data->i * 84);
		data->steps++;
		ft_printf("steps count:%d\n", data->steps);
		print_screen(data);
	}
}

void	key_pressed_d(t_data *data)
{
	if (data->map[data->i][data->j + 1] != '1')
	{
		if (data->map[data->i][data->j + 1] == 'C')
		{
			data->map[data->i][data->j + 1] = '0';
			mlx_delete_image(data->mlx, data->colimg);
			data->colimg = mlx_texture_to_image(data->mlx, data->col);
			data->col_count--;
			replacing_coins(data);
		}
		if (data->col_count == 0 && data->map[data->i][data->j + 1] == 'E')
		{
			mlx_delete_image(data->mlx, data->pimg);
			mlx_close_window(data->mlx);
			return ;
		}
		mlx_delete_image(data->mlx, data->pimg);
		data->pimg = mlx_texture_to_image(data->mlx, data->player);
		mlx_image_to_window(data->mlx, data->pimg, (data->j + 1) * 60, \
			data->i * 84);
		data->j = data->j + 1;
		data->steps++;
		ft_printf("steps count:%d\n", data->steps);
		print_screen(data);
	}
}

void	replacing_coins(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				mlx_image_to_window(data->mlx, data->colimg, j * 60, \
					i * 84);
			j++;
		}
		i++;
	}
}
