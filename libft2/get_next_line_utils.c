/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:30:48 by snagulap          #+#    #+#             */
/*   Updated: 2023/05/15 13:36:55 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	str_len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*str_chr(char *str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}

char	*str_join(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	ret = (char *)malloc(str_len(str1) + str_len(str2)+ 1);
	if (!ret)
		return (NULL);
	while (str1[i] != '\0')
	{
		ret[i] = str1[i];
		i++;
	}
	while (str2[j] != '\0')
		ret[i++] = str2[j++];
	ret[i] = '\0';
	return (ret);
}

char	*str_combine(char *str1, char *str2)
{
	char	*com_str;

	if (!str1)
	{
		str1 = malloc(sizeof(char) * 1);
		str1[0] = '\0';
	}
	if (!str1 || !str2)
		return (0);
	com_str = str_join(str1, str2);
	free(str1);
	return (com_str);
}

char	*ft_strdup1(char *s1)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	while (s1[i] && s1[i] != '\n')
		i++;
	if (!s1[i])
	{
		free(s1);
		return (NULL);
	}
	dst = (char *)malloc(sizeof(char) * (str_len(s1) - i + 1));
	if (!dst)
		return (NULL);
	i++;
	j = 0;
	while (s1[i + j])
	{
		dst[j] = s1[i + j];
		j++;
	}
	dst[j] = '\0';
	free(s1);
	return (dst);
}
