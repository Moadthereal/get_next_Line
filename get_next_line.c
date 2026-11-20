/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majnaou <majnaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 10:35:09 by majnaou           #+#    #+#             */
/*   Updated: 2026/11/20 07:32:47 by majnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*	stash = "hello\nworld" --> "hello\n" "world"
	stash = "hello" --> "hello" "NULL"
	stash = "\nhello" -- > "\n" "hello"
	stash = "\n" -->"\n" NULL
*/

char *free_all(char **stash, char *buffer)
{
	free(buffer);
	free(*stash);
	*stash = NULL;
	return (NULL);
}
char *get_next_line(int fd)
{
	static char	*stash = NULL;
	char	*buffer;
	char	*line;
	int	bytes_read;

	buffer = malloc((size_t)(BUFFER_SIZE) + 1);
	if (NULL == buffer)
		return (NULL);
	while (!(has_newLine(stash)))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return(free_all(&stash, buffer)) ;
		else if (bytes_read == 0)
			break;
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (NULL == stash)
			return (free(buffer), NULL);
	}
	line = extract_line(stash);
	stash = extract_reminder(stash);
	return (free(buffer), line);
}

/*
                  read()
                   |
          +--------+--------+
          |        |        |
        > 0       -1       0
          |        |        |
       append    error     EOF
          |                 |
          |          +------+------+
          |          |             |
       continue   stash == NULL  stash != NULL
                         |             |
                       NULL          break
                                       |
                                  extract line
                                       |
                                  return last line
*/
