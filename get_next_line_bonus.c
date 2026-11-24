/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majnaou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 07:55:15 by majnaou           #+#    #+#             */
/*   Updated: 2026/11/24 10:26:49 by majnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	char		*buffer;
	static char	*stash[OPEN_MAX];
	char		*line;
	int			read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0 || ft_tcheck_fd(fd))
		return (free(stash[fd]), NULL);
	buffer = malloc(((size_t)BUFFER_SIZE) + 1);
	if (NULL == buffer)
		return (NULL);
	while (!has_newline(stash[fd]))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free_all(&stash[fd], buffer));
		else if (read_bytes == 0)
			break ;
		buffer[read_bytes] = '\0';
		stash[fd] = ft_strjoin(stash[fd], buffer);
		if (stash[fd] == NULL)
			return ((free(buffer), NULL));
	}
	line = extract_line(stash[fd]);
	stash[fd] = extract_reminder(stash[fd]);
	return (free(buffer), line);
}
