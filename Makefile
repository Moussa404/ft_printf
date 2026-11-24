# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjaafar <mjaafar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/20 15:24:14 by mjaafar           #+#    #+#              #
#    Updated: 2026/11/23 15:54:34 by mjaafar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
RM = rm -f

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_TMP = .libft_tmp

SRC = ft_printf.c \
      ft_putnbr_count.c \
      ft_putunsigned_count.c \
      ft_puthex_count.c \
      ft_putptr_count.c \
      ft_handle_conversion.c \
	  ft_print_extra.c \
	  ft_process_format.c
	  

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	mkdir -p $(LIBFT_TMP)
	cd $(LIBFT_TMP) && $(AR) x ../$(LIBFT)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ) $(LIBFT_TMP)/*.o
	rm -rf $(LIBFT_TMP)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(LIBFT_TMP)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
