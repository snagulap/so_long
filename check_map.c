/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:38:38 by snagulap          #+#    #+#             */
/*   Updated: 2023/05/26 20:46:07 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_data *data, int i, int j)
{
	while (data->map[i] && data->map[i][j])
	{
		if (data->map[i][j] != '1')
			return (0);
		j++;
	}
	while (data->map[i])
		i++;
	i--;
	j = 0;
	while (data->map[i] && data->map[i][j])
	{
		if (data->map[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	check_map1(t_data *data, int i, int j)
{
	i = 0;
	while (data->map[i])
	{
		if (data->map[i][0] != '1')
			return (0);
		i++;
	}
	while (data->map[0][j])
		j++;
	j--;
	i = 0;
	while (data->map[i])
	{
		if (data->map[i][j] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	rect_check(t_data *data)
{
	int	i;

	i = 1;
	while (data->map[i])
	{
		if (ft_strlen(data->map[i - 1]) != ft_strlen(data->map[i]))
			return (ft_free(data->map), 0);
		i++;
	}
	return (1);
}

int	check_count(t_data *data, char c)
{
	int	i;
	int	j;
	int	x;

	x = 0;
	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] != '0' && data->map[i][j] != '1' &&
				data->map[i][j] != 'C' && data->map[i][j] != 'P' &&
				data->map[i][j] != 'E')
				return (0);
			if (data->map[i][j] == c)
				x++;
			j++;
		}
		j = 0;
		i++;
	}
	return (x);
}
