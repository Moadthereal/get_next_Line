/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majnaou <majnaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 10:34:56 by majnaou           #+#    #+#             */
/*   Updated: 2026/11/20 07:40:22 by majnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETNEXTLINE_H
# define FT_GETNEXTLINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2 
#endif


#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h> // just for testing
#include <unistd.h>

char	*get_next_line(int fd);
char	*extract_line(char *stash);
char	*extract_reminder(char *stash);
int	has_newLine(char *stash);
char	*ft_strjoin(char *s1, char *s2);
char    *ft_strdup(char *str);



#endif
