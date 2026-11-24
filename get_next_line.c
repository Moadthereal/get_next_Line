/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majnaou <majnaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 10:35:09 by majnaou           #+#    #+#             */
/*   Updated: 2026/11/23 18:50:29 by majnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_all(char **stash, char *buffer)
{
	free(buffer);
	free(*stash);
	*stash = NULL;
	return (NULL);
}

int	has_newline(char *stash)
{
	int	i;

	if (NULL == stash)
		return (0);
	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_tcheck_fd(int fd)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc(((size_t)BUFFER_SIZE) + 1);
	if (NULL == buffer)
		return (1);
	read_bytes = read(fd, buffer, 0);
	if (read_bytes == -1)
	{
		free(buffer);
		return (1);
	}
	else
	{
		free(buffer);
		return (0);
	}
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || ft_tcheck_fd(fd))
		return (free(stash), NULL);
	buffer = malloc((size_t)(BUFFER_SIZE) + 1);
	if (NULL == buffer)
		return (NULL);
	while (!(has_newline(stash)))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_all(&stash, buffer));
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (NULL == stash)
			return (free(buffer), NULL);
	}
	line = extract_line(stash);
	stash = extract_reminder(stash);
	return (free(buffer), line);
}
