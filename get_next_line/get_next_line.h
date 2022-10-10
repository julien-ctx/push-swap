/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencaucheteux <juliencaucheteux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:45:08 by jcauchet          #+#    #+#             */
/*   Updated: 2022/03/02 10:32:24 by juliencauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*gnl_ft_strjoin(char *s1, char *s2);
int		gnl_ft_strlen(char *s);
char	*gnl_ft_strchr(char *s, int c);
char	*gnl_ft_substr(char *s, int start, int len);
char	*gnl_ft_strdup(char *s1);

#endif
