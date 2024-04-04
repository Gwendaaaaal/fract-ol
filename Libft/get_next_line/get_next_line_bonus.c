/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:09:43 by gholloco          #+#    #+#             */
/*   Updated: 2024/03/19 17:29:38 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_n_fill(int fd, char **stock)
{
	char	*buffer;
	int		bytes;

	bytes = 10;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(stock[fd], '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			if (stock[fd])
				free(stock[fd]);
			return (free(buffer), NULL);
		}
		buffer[bytes] = 0;
		stock[fd] = ft_strjoinn(stock[fd], buffer);
	}
	free(buffer);
	return (stock[fd]);
}

char	*get_line(int fd, char **stock)
{
	char	*line;
	int		i;

	i = 0;
	if (!stock[fd] || !stock[fd][0])
		return (NULL);
	line = ft_strdup(stock[fd]);
	if (!line)
		return (NULL);
	if (ft_strchr(stock[fd], '\n'))
	{
		while (line[i] != '\n')
			i++;
		line = ft_substrr(line, 0, i + 1);
		return (line);
	}
	return (line);
}

char	*clean_stock(int fd, char **stock)
{
	if (ft_strchr(stock[fd], '\n'))
	{
		ft_strcpyy(stock[fd], ft_strchr(stock[fd], '\n') + 1);
		return (stock[fd]);
	}
	if (stock[fd])
	{
		free(stock[fd]);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stock[MAX_FILES];

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	stock[fd] = read_n_fill(fd, stock);
	line = get_line(fd, stock);
	stock[fd] = clean_stock(fd, stock);
	return (line);
}
