# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 18:22:57 by vboissel          #+#    #+#              #
#    Updated: 2018/01/13 21:22:30 by vboissel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_dec_to_base.c\
	ft_isdigit.c\
	ft_lstdelone.c\
	ft_memccpy.c\
	ft_memmove.c\
	ft_putendl_fd.c\
	ft_strcat.c\
	ft_strdel.c\
	ft_strjoin.c\
	ft_strncat.c\
	ft_strnstr.c\
	ft_strsub.c\
	ft_ipower.c\
	ft_isprint.c\
	ft_lstiter.c\
	ft_memchr.c\
	ft_memset.c\
	ft_putnbr.c\
	ft_strchr.c\
	ft_strdup.c\
	ft_strlcat.c\
	ft_strncmp.c\
	ft_strrchr.c\
	ft_strtrim.c\
	ft_atoi.c\
	ft_isalnum.c\
	ft_itoa.c\
	ft_lstmap.c\
	ft_memcmp.c\
	ft_putchar.c\
	ft_putnbr_fd.c\
	ft_strclr.c\
	ft_strequ.c\
	ft_strlen.c\
	ft_strncpy.c\
	ft_strrev.c\
	ft_to_utf8.c\
	ft_base_to_dec.c\
	ft_isalpha.c\
	ft_lstadd.c\
	ft_lstnew.c\
	ft_memcpy.c\
	ft_putchar_fd.c\
	ft_putstr.c\
	ft_strcmp.c\
	ft_striter.c\
	ft_strmap.c\
	ft_strnequ.c\
	ft_strsplit.c\
	ft_tolower.c\
	ft_bzero.c\
	ft_isascii.c\
	ft_lstdel.c\
	ft_memalloc.c\
	ft_memdel.c\
	ft_putendl.c\
	ft_putstr_fd.c\
	ft_strcpy.c\
	ft_striteri.c\
	ft_strmapi.c\
	ft_strnew.c\
	ft_strstr.c\
	ft_toupper.c\
	ft_lstlen.c\
	ft_lstget.c\
	ft_strsplitlst.c\
	ft_strlenc.c\
	ft_lstrem.c\
	ft_lstsrchi.c

OBJS :=  ft_dec_to_base.o\
	ft_isdigit.o\
	ft_lstdelone.o\
	ft_memccpy.o\
	ft_memmove.o\
	ft_putendl_fd.o\
	ft_strcat.o\
	ft_strdel.o\
	ft_strjoin.o\
	ft_strncat.o\
	ft_strnstr.o\
	ft_strsub.o\
	ft_ipower.o\
	ft_isprint.o\
	ft_lstiter.o\
	ft_memchr.o\
	ft_memset.o\
	ft_putnbr.o\
	ft_strchr.o\
	ft_strdup.o\
	ft_strlcat.o\
	ft_strncmp.o\
	ft_strrchr.o\
	ft_strtrim.o\
	ft_atoi.o\
	ft_isalnum.o\
	ft_itoa.o\
	ft_lstmap.o\
	ft_memcmp.o\
	ft_putchar.o\
	ft_putnbr_fd.o\
	ft_strclr.o\
	ft_strequ.o\
	ft_strlen.o\
	ft_strncpy.o\
	ft_strrev.o\
	ft_to_utf8.o\
	ft_base_to_dec.o\
	ft_isalpha.o\
	ft_lstadd.o\
	ft_lstnew.o\
	ft_memcpy.o\
	ft_putchar_fd.o\
	ft_putstr.o\
	ft_strcmp.o\
	ft_striter.o\
	ft_strmap.o\
	ft_strnequ.o\
	ft_strsplit.o\
	ft_tolower.o\
	ft_bzero.o\
	ft_isascii.o\
	ft_lstdel.o\
	ft_memalloc.o\
	ft_memdel.o\
	ft_putendl.o\
	ft_putstr_fd.o\
	ft_strcpy.o\
	ft_striteri.o\
	ft_strmapi.o\
	ft_strnew.o\
	ft_strstr.o\
	ft_toupper.o\
	ft_lstlen.o\
	ft_lstget.o\
	ft_strsplitlst.o\
	ft_strlenc.o\
	ft_lstrem.o\
	ft_lstsrchi.o

INCLUDES = libft.h

GCH = libft.h.gch

FLAGS = -Wall -Wextra -Werror

$(NAME) : $(OBJ)
	gcc $(FLAGS) -c $(SRCS) -I $(INCLUDES)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

all : $(NAME)

clean :
	/bin/rm -f $(OBJS) $(GCH)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all

.phony : clean fclean
