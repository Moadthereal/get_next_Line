/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majnaou <majnaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 09:51:46 by majnaou           #+#    #+#             */
/*   Updated: 2026/11/20 07:36:12 by majnaou          ###   ########.fr       */
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
// h e l l o \n w o r l \0
//
char    *extract_line(char *stash)
{
	int	i;
	int newLine;
	char	*line;
	int k;

	if ( NULL == stash )
		return (NULL);
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
	k = 0;
	while (stash[i] && stash[i] != '\n')
		line[i++] = stash[k++];
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
	char	*reminder;

	if (NULL == stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
		return (free(stash), NULL);
	i++;
	j = 0;
	while (stash[i + j])
		j++;
	reminder = malloc(j + 1);
	if (NULL == reminder)
		return (free(stash), NULL);
	j = 0;
	while (stash[i]) 
		reminder[j++] = stash[i++];
	reminder[j] = '\0';
	return (free (stash), reminder); 
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
	free(s1);
	join[j] = '\0';
	return (join);
}
