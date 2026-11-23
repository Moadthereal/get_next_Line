/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majnaou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 07:59:37 by majnaou           #+#    #+#             */
/*   Updated: 2026/11/23 09:33:38 by majnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef SIZE 
#  define SIZE 1024 
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		has_newline(char *stash);
char	*extract_line(char *stash);
char	*extract_reminder(char *stash);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);

#endif
