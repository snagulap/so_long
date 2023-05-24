/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:28:46 by snagulap          #+#    #+#             */
/*   Updated: 2023/05/24 03:45:11 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_check(t_data *data)
{
	data->x = 0;
	while (data->map1[data->x])
	{
		data->y = 0;
		while (data->map1[data->x][data->y])
		{
			if (data->map1[data->x][data->y] == 'P')
				return ;
			data->y++;
		}
		data->x++;
	}
}

void	path_(t_data *data, int x, int y)
{
	if (data->map1[x][y] == '1'
		&& data->map1[x][y] == 0)
		return ;
	if (data->map1[x][y] == 'C')
		data->collectibles++;
	if (data->map1[x][y] == 'E')
		data->exit_ = 1;
	data->map1[x][y] = 'x';
	if (data->map1[x][y + 1] != '1'
		&& data->map1[x][y + 1] != 'x')
		path_(data, x, y + 1);
	if (data->map1[x + 1][y] != '1'
		&& data->map1[x +1][y] != 'x')
		path_(data, x + 1, y);
	if (data->map1[x][y - 1] != '1'
		&& data->map1[x][y - 1] != 'x')
		path_(data, x, y - 1);
	if (data->map1[x - 1][y] != '1'
		&& data->map1[x - 1][y] != 'x')
		path_(data, x - 1, y);
}

int	valid_path(t_data *data)
{
	player_check(data);
	path_(data, data->x, data->y);
	if ((data->exit_ == 1) && (data->collectibles == data->col_count))
		return (1);
	return (0);
}
