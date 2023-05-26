/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:27:38 by snagulap          #+#    #+#             */
/*   Updated: 2023/05/26 14:08:23 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_img(t_data *data)
{	
	mlx_delete_texture(data->player);
	mlx_delete_image(data->mlx, data->pimg);
	mlx_delete_texture(data->wall);
	mlx_delete_image(data->mlx, data->wallimg);
	mlx_delete_texture(data->col);
	if (data->colimg != NULL)
		mlx_delete_image(data->mlx, data->colimg);
	mlx_delete_texture(data->xit);
	mlx_delete_image(data->mlx, data->exitimg);
	ft_free(data->map);
	ft_free(data->map1);
	mlx_terminate(data->mlx);
	free(data);
}

void	ft_free(char **data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		free(data[i]);
		i++;
	}
	free(data);
}
