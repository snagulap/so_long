/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:13:19 by snagulap          #+#    #+#             */
/*   Updated: 2023/05/26 18:22:37 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	width(char *name)
{
	int		fd;
	int		length;
	char	*data;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (0);
	data = get_next_line(fd);
	length = ft_strlen(data);
	close(fd);
	free(data);
	return (length);
}

int	height(char *name)
{
	int		i;
	char	*rows;
	int		fd;

	i = 0;
	fd = open(name, O_RDONLY);
	rows = get_next_line(fd);
	while (rows != NULL)
	{
		free(rows);
		i++;
		rows = get_next_line(fd);
	}
	close(fd);
	return (i);
}

void	creat_map(t_data *data)
{
	int		fd1;
	char	*str;
	char	*ret;
	char	*temp;
	int		i;

	i = 0;
	ret = malloc(1);
	ret[0] = '\0';
	fd1 = open(data->name, O_RDONLY);
	str = get_next_line(fd1);
	while (str != NULL)
	{
		temp = ft_strjoin(ret, str);
		free(ret);
		ret = temp;
		free(str);
		str = get_next_line(fd1);
	}
	data->map = ft_split(ret, '\n');
	data->map1 = ft_split(ret, '\n');
	close(fd1);
	free(ret);
}

int	check_filename(char *name)
{
	int	len;
	int	fd1;

	fd1 = open(name, O_RDONLY);
	if (fd1 < 0)
	{
		close(fd1);
		return (1);
	}
	close(fd1);
	len = ft_strlen(name);
	while (len >= 0)
	{
		if (name[len] == '.')
		{
			if (name[len + 1] == 'b' && name[len + 2] == 'e'
				&& name[len + 3] == 'r')
				return (0);
			else
				return (1);
		}
		len--;
	}
	return (1);
}

int	col_count(t_data *data)
{
	int	x;

	x = check_count(data, 'C');
	return (x);
}
