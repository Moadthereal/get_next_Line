/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majnaou <majnaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 10:35:09 by majnaou           #+#    #+#             */
/*   Updated: 2026/11/19 12:05:59 by majnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*	stash = "hello\nworld" --> "hello\n" "world"
	stash = "hello" --> "hello" "NULL"
	stash = "\nhello" -- > "\n" "hello"
	stash = "\n" -->"\n" NULL
*/

char *get_next_line(int fd)
{
	static char	*stash = NULL;
	char	*buffer;
	char	*line;
	char	*tmp;
	int	bytes_read;

	buffer = malloc((size_t)(BUFFER_SIZE) + 1);
	if (NULL == buffer)
		return (NULL);
	while (!(has_newLine(stash)))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return(free(buffer), NULL) ;
		else if (bytes_read == 0)
			break;
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (NULL == stash)
			return (free(buffer), NULL);
	}
	tmp = stash;
	line = extract_line(stash);
	stash = extract_reminder(stash);
	free(tmp);
	return (line);
}
