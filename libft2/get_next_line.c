/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:30:39 by snagulap          #+#    #+#             */
/*   Updated: 2023/05/15 13:37:08 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_line(char *buff)
{
	int		i;
	char	*str;

	if (!buff || !buff[0])
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n' )
		i++;
	if (buff[i] == '\n')
		i++;
	str = (char *)malloc(sizeof (char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		str[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*read_buff(int fd, char *buffer)
{
	int		i;
	char	*read_ret;

	read_ret = malloc((sizeof(char)) * (BUFFER_SIZE + 1));
	if (!read_ret)
		return (NULL);
	i = 1;
	while (!(str_chr(buffer, '\n')) && i != 0)
	{
		i = read(fd, read_ret, BUFFER_SIZE);
		if (i == -1)
		{
			free(read_ret);
			free(buffer);
			return (NULL);
		}
		read_ret[i] = '\0';
		buffer = str_combine(buffer, read_ret);
	}
	free(read_ret);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = read_buff(fd, buff);
	if (!buff)
		return (NULL);
	line = read_line(buff);
	buff = ft_strdup1(buff);
	return (line);
}
