/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majnaou <majnaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 09:51:46 by majnaou           #+#    #+#             */
/*   Updated: 2026/11/19 12:16:23 by majnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int has_newLine(char  *stash)
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
// stash = "hello\nwo" --> "hello\n" "world"
char    *extract_line(char *stash)
{
	int	i;
	int newLine;
	char	*line;

	i = 0;
	while (stash[i] && stash[i] != '\n' )
		i++;
	if (stash[i] == '\n')
		newLine = 2;
	else 
		newLine = 1;
	line = malloc(i + newLine);
	if (NULL == line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		line[i++] = *stash++;
	if (newLine == 2)
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

// stash = "hello\nwo" --> "hello\n" "world"
char    *extract_reminder(char *stash)
{
	int	i;
	int	j;
	int 	k;
	char	*reminder;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	j = 0;
	i = i + 1;
	k = i;
	while (stash[i++])
		j++;
	reminder = malloc(j + 1);
	if (NULL == reminder)
		return (NULL);
	
	i = 0;
	while (stash[k]) 
		reminder[i++] = stash[k++];
	reminder[i] = '\0';
	return (reminder); 
}

char	*ft_strdup(char *str)
{
	int	i;
	char	*dup;

	i = 0;
	while (str[i])
		i++;
	dup = malloc(i + 1);
	if (NULL == dup)
		return (NULL);
	i = 0;
	while (*str)
		dup[i++] = *str++;
	dup[i] = '\0';
	return (dup);
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int	i;
	int	j;

	if (!s1 && s2)
		return (ft_strdup(s2));
	else if (s1 && !s2)
		return (ft_strdup(s1));
	else if (!s1 && !s2)
		return (NULL);
	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (NULL == join)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		join[j++] = s1[i++];
	i = 0;
	while (s2[i])
		join[j++] = s2[i++];
	join[j] = '\0';
	return (join);
}
