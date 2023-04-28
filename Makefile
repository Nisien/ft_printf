# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrossa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/26 18:34:13 by nrossa            #+#    #+#              #
#    Updated: 2023/03/29 21:32:11 by nrossa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean bclean mclean norme

NAME = libftprintf.a
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
MAIN = main_printf.c
OUTPUT = output.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = /bin/rm -f

HDR = libftprintf.h libftprintf_bonus.h
SRC = ft_printf.c ft_print_all.c ft_print_hexa.c ft_print_aptr.c ft_putncount.c ft_utoa.c
OBJS = $(SRC:.c=.o)
SRC_BONUS = ft_printf_bonus.c ft_print_all_bonus.c ft_print_aptr_bonus.c ft_print_hexa_bonus.c ft_putncount.c ft_utoa.c ft_print_flags_bonus.c ft_util_bonus.c
OBJS_BONUS = $(SRC_BONUS:.c=.o)

BLACK = \033[30m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
WHITE = \033[37m
NC = \033[0m

.c.o:
	@echo "$(RED)Creating object files...$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "$(YELLOW)Copying libft...$(NC)"
	@cp $(LIBFT) $(NAME)
	@echo "$(RED)Compilation in progress...$(NC)"
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)Compilation complete !$(NC)"

$(LIBFT):
	@echo "$(YELLOW)Creating libft...$(NC)"
	@make -s -C $(LIBFT_DIR) all

bonus: bclean $(LIBFT) $(OBJS_BONUS)
	@cp $(LIBFT) $(NAME)
	@echo "$(YELLOW)Bonus compilation in progress...$(NC)"
	@$(AR) $(NAME) $(OBJS_BONUS)
	@echo "$(GREEN)Bonus compilation complete !$(NC)"

main:
	@echo "$(RED)Compilation in progress...$(NC)"
	@$(CC) $(CFLAGS) -o $(OUTPUT) $(MAIN) $(NAME)
	@echo "$(GREEN)Compilation complete !\nOutput :$(NC)"
	@./$(OUTPUT)

cmain:
	clear
	@make -s main

clean:
	@echo "$(YELLOW)Cleaning libft object files...$(NC)"
	@make -s -C $(LIBFT_DIR) clean
	@echo "$(YELLOW)Cleaning object files...$(NC)"
	@$(RM) *.o
	@echo "$(GREEN)Cleaning complete !$(NC)"

fclean: clean
	@echo "$(YELLOW)Cleaning libft library...$(NC)"
	@make -s -C $(LIBFT_DIR) fclean
	@echo "$(YELLOW)Cleaning libftprintf library...$(NC)"
	@$(RM) $(NAME)
	@echo "$(GREEN)Cleaning complete !$(NC)"

bclean:
	@$(RM) $(NAME)

mclean:
	@echo "$(YELLOW)Cleaning output...$(NC)"
	@$(RM) $(OUTPUT)
	@echo "$(GREEN)Cleaning complete !$(NC)"

re: fclean all

norme:
	@echo "$(YELLOW)Checking Norme...$(NC)"
	@norminette $(SRC) $(SRC_BONUS) $(HDR)
	@echo "$(GREEN)Checking complete !$(NC)"
