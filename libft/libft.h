/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencaucheteux <juliencaucheteux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:05:39 by jcauchet          #+#    #+#             */
/*   Updated: 2022/03/07 12:16:16 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include "../push_swap.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		word_count(char *s, char c);
int		word_len(int pos, char *s, char c);
int		ft_strncpy(char *array, int pos, char *s, char c);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memset(void *b, int c, size_t len);
char	**ft_split(char *s, char c);
char	**ft_freed_split(char *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *s1);
int		ft_strlen(const char *s);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
int		ft_tolower(int c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_toupper(int c);
char	*ft_substr(char *s, int start, int len);
char	*ft_itoa(int n);
int		ft_isalpha(int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strtrim(char const *s1, char const *set);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	error(void);
void	ft_free_array(char **array);
int		ft_array_size(char	**array);
void	ft_swap(int *a, int *b);

#endif
