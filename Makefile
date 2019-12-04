# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iromero- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/24 10:46:25 by iromero-          #+#    #+#              #
#    Updated: 2019/12/03 15:45:42 by iromero-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a
SRC_PF = ft_printf.c	aux.c	flags.c	hexnum.c	pointmem.c    \
		 spaces.c	unsgint.c	utils.c 
SRC_LFT = *.c
OBJET_PF =  $(SRC_PF:.c=.o)
OBJET_LFT = $(SRC_LFT:.c=.o)
LIBFT_PATH =  libft
FLAGS = -Wall -Werror -Wextra
LIB = $(addprefix $(LIBFT_PATH)/, $(OBJET_LFT))
GCC = gcc
AR = ar
ARFLAGS = rc
MAKE = make
.PHONY: clean fclean all re
all: $(NAME)
$(NAME): $(OBJET_PF) $(SRC_PF)
	@$(MAKE) -C $(LIBFT_PATH)
	@echo Compiling $(NAME)
	@$(GCC) $(FLAGS) -c $(SRC_PF)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJET_PF) $(LIB)
	@ranlib $(NAME)
	@echo ======[Done]=====
clean:
		@$(MAKE) -C $(LIBFT_PATH) clean
		@echo Clean objects $(NAME)
		@rm -rf $(OBJET_PF) *.o
fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@echo Clean $(NAME)
	@rm -rf $(NAME)
	@echo ======[Clean]======
re: fclean all
