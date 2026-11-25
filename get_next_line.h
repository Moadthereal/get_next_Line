/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majnaou <majnaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 10:34:56 by majnaou           #+#    #+#             */
/*   Updated: 2026/11/25 08:47:12 by majnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42 
# endif

# include <stdlib.h>
# include <unistd.h>

int		has_newline(char *stash);
int		ft_tcheck_fd(int fd);
int		ft_strlen(char *str);
char	*get_next_line(int fd);
char	*extract_line(char *stash);
char	*extract_reminder(char *stash);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);
char	*free_stash(char **stash);
char	*free_all(char **stash, char *buffer);

#endif
