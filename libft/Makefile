# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/17 20:26:21 by edrodrig          #+#    #+#              #
#    Updated: 2021/09/19 22:05:15 by edrodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Werror -Wextra -c
CFLAGS_BONUS = -Wall -Werror -Wextra -I $(HEADERFILES) -c
CC = gcc
CC_BONUS = clang
HEADERFILES = libft.h 
FILES = ft_isalpha.c 	\
		ft_isdigit.c		\
		ft_isalnum.c		\
		ft_isascii.c		\
		ft_isprint.c		\
		ft_strlen.c		\
                ft_memset.c		\
		ft_bzero.c		\
		ft_memcpy.c		\
		ft_memmove.c 		\
		ft_strlcpy.c		\
		ft_strlcat.c		\
		ft_toupper.c		\
		ft_tolower.c		\
		ft_strchr.c		\
		ft_strrchr.c		\
		ft_strncmp.c		\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_strnstr.c		\
		ft_atoi.c		\
	        ft_isspace.c            \
		ft_calloc.c		\
		ft_strdup.c		\
		ft_substr.c		\
		ft_strjoin.c 		\
		ft_strtrim.c		\
		ft_split.c		\
		ft_itoa.c		\
		ft_striteri.c           \
		ft_putchar_fd.c        	\
		ft_putstr_fd.c		\
		ft_strmapi.c		\
		ft_putendl_fd.c		\
		ft_putnbr_fd.c 

BONUS =		ft_lstnew.c   		\
		ft_lstadd_front.c	\
		ft_lstsize.c		\
		ft_lstlast.c		\
		ft_lstadd_back.c	\
		ft_lstdelone.c		\
		ft_lstclear.c		\
		ft_lstiter.c		\
		ft_lstmap.c 

OBJFILES = $(FILES:%.c=%.o)
OBJFILES_BONUS = $(BONUS:%.c=%.o)

all: $(NAME) 

$(NAME): $(OBJFILES)
	ar rcs $(NAME) $^
	
$(OBJFILES): $(FILES)
	$(CC) $(CFLAGS) $^

$(OBJFILES_BONUS): $(BONUS)
	$(CC_BONUS) $(CFLAGS_BONUS) $^
clean:
	rm -f $(OBJFILES)
	rm -f $(OBJFILES_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJFILES_BONUS)
	ar rcs $(NAME) $(OBJFILES_BONUS)

.PHONY: clean fclean all re bonus
