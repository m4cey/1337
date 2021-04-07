/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-haih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 13:13:00 by mel-haih          #+#    #+#             */
/*   Updated: 2020/02/08 13:13:01 by mel-haih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	my_read(int fd, char **buffer)
{
	int	r;

	if (!(*buffer = malloc(BUFFER_SIZE + 1)))
		return (-1);
	r = read(fd, *buffer, BUFFER_SIZE);
	(*buffer)[r] = 0;
	return (r);
}

int	init(int fd, char **line, char **temp, char **buffer)
{
	if (fd < 0 || !line || BUFFER_SIZE > INT_MAX)
		return (-1);
	if (*temp && (ft_strchr(*temp, '\n')))
	{
		*buffer = ft_strdup(*temp);
		free(*temp);
		*temp = NULL;
		return (1);
	}
	return (my_read(fd, buffer));
}

int	put_line(int bytes_read, char **line, char *buffer, char **temp)
{
	char *newline;

	newline = ft_strchr(buffer, '\n');
	if (bytes_read)
		*newline = '\0';
	if (*temp)
	{
		*line = ft_memcat(*temp, buffer);
		free(*temp);
		*temp = NULL;
	}
	else
		*line = ft_strdup(buffer);
	if (bytes_read)
		*temp = ft_strdup(newline + 1);
	free(buffer);
	return (bytes_read > 0 ? 1 : bytes_read);
}

int	get_next_line(int fd, char **line)
{
	static char	*temp;
	char		*buffer;
	char		*newline;
	char		*temp_temp;
	ssize_t		bytes_read;

	if ((bytes_read = init(fd, line, &temp, &buffer)) < 0)
		return (-1);
	while (!(newline = ft_strchr(buffer, '\n')))
	{
		if (temp)
		{
			temp_temp = temp;
			temp = ft_memcat(temp, buffer);
			free(temp_temp);
		}
		else
			temp = ft_strdup(buffer);
		if (bytes_read == 0)
			break ;
		free(buffer);
		bytes_read = my_read(fd, &buffer);
	}
	return (put_line(bytes_read, line, buffer, &temp));
}
