CFLAGS = -Werror -Wall -Wextra

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

NAME = libft.a

SRCS = ft_memset.c     \
        ft_bzero.c      \
        ft_memcpy.c     \
        ft_memmove.c    \
        ft_memchr.c     \
        ft_memcmp.c     \
        ft_strlen.c     \
        ft_isalpha.c    \
        ft_isdigit.c    \
        ft_isalnum.c    \
        ft_isascii.c    \
        ft_isprint.c    \
        ft_toupper.c    \
        ft_tolower.c    \
        ft_strchr.c     \
        ft_strrchr.c    \
        ft_strncmp.c    \
        ft_strlcpy.c    \
        ft_strlcat.c    \
        ft_strnstr.c    \
        ft_atoi.c       \
        ft_calloc.c     \
        ft_strdup.c     \
        ft_substr.c     \
        ft_strjoin.c    \
        ft_strtrim.c    \
        ft_split.c      \
        ft_itoa.c       \
        ft_strmapi.c    \
        ft_putchar_fd.c \
        ft_putstr_fd.c  \
        ft_putendl_fd.c \
        ft_putnbr_fd.c  \
        ft_striteri.c \
		ft_freed_split.c \
        ft_lstnew.c \
        ft_lstadd_front.c \
        ft_lstsize.c \
        ft_lstlast.c \
        ft_lstadd_back.c \
        ft_lstclear.c \
        ft_lstdelone.c \
        ft_lstiter.c \
        ft_lstmap.c \
        ft_free_array.c \
        ft_array_size.c \
		ft_swap.c \
                
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar -crs $(NAME) $(OBJS)
	@echo "\n✅ $(GREEN)SUCCESS: libft has been created$(RESET)\n"

bonus:
	make all

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME) 

re: fclean all

.PHONY: all clean fclean re
