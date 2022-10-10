/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencaucheteux <juliencaucheteux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:43:59 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/07 21:41:29 by juliencauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_reader(char *storage, int fd)
{
	int		ret;
	char	buf[BUFFER_SIZE + 1];

	ret = 1;
	while (ret && (!gnl_ft_strchr(storage, '\n')))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
			return (NULL);
		else
			buf[ret] = '\0';
		storage = gnl_ft_strjoin(storage, buf);
	}
	return (storage);
}

char	*ft_seek_line(char *storage)
{
	char	*line;
	int		i;

	i = 0;
	if (!storage)
		return (NULL);
	if (storage[i] == '\0')
		return (NULL);
	while (storage[i] != '\n' && storage[i] != '\0')
		i++;
	line = malloc ((i + 2) * sizeof(char));
	i = 0;
	while (storage[i] != '\n' && storage[i] != '\0')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
	{
		line[i] = storage[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_new_storage(char *storage)
{
	char	*new_storage;
	int		i;

	i = 0;
	if (!storage)
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\0')
	{
		free (storage);
		return (NULL);
	}
	i++;
	new_storage = gnl_ft_substr(storage, i, gnl_ft_strlen(storage));
	if (!new_storage)
		return (NULL);
	free(storage);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*line;

	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	storage = ft_reader(storage, fd);
	line = ft_seek_line(storage);
	storage = ft_new_storage(storage);
	return (line);
}
