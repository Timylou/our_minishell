# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/01 07:16:59 by brturcio          #+#    #+#              #
#    Updated: 2025/05/01 08:21:11 by brturcio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= minishell
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror


DIR_SRCS		:= srcs
DIR_OBJS		:= objs
DIR_LIBFT		:= libft

SRCS			:= $(wildcard $(DIR_SRCS)/*.c) \
					$(wildcard $(DIR_SRCS)/builtins/*.c) \
					# $(wildcard $(DIR_SRCS)/filename/*.c) \
					# Add other folders below if needed (e.g., parser, utils, etc.) \
					# SRCS := $(shell find $(DIR_SRCS) -type f -name "*.c")

# Object files: convert each source file path into a corresponding .o path in objs/
# For example: srcs/builtins/echo.c → objs/builtins/echo.o
OBJS 			:= $(patsubst %.c, $(DIR_OBJS)/%.o, $(subst $(DIR_SRCS)/,,$(SRCS)))
LIBFT			:= $(DIR_LIBFT)/libft.a

# Include paths for headers (local and from libft)
INCLUDES		:= -I$(DIR_LIBFT)/inc -Iinclude

all : $(LIBFT) $(NAME)

# Compile each .c file into a .o file
# Also creates necessary subdirectories inside objs/ automatically
$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Link all object files with libft to produce the final executable
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@
	@echo "✅ Compilation completed: $(NAME)"

# Build libft only if libft.a does not already exist
$(LIBFT):
	@if [ ! -f $@ ] ; then \
		$(MAKE) -s -C $(DIR_LIBFT); \
	fi

clean :
	@rm -rf $(DIR_OBJS)
	@$(MAKE) -s -C $(DIR_LIBFT) clean
	@echo "✅ clean done."

fclean : clean
	@rm -f $(NAME)
	@$(MAKE) -s -C $(DIR_LIBFT) fclean
	@echo "✅ fclean done."

re : fclean all

.PHONY : all clean fclean re libft


# Debug target: compiles the program with -g flag to enable debugging with gdb
# Usage: run `make debug` to recompile everything with debugging information
debug: CFLAGS += -g					# Add -g to the CFLAGS (enables debug symbols)
debug: re							# Rebuild everything from scratch using fclean and all
	@echo "🔍 Compiled with -g for debugging."

# Example: when you run `make debug` \
# 1. It performs `fclean` to remove all compiled files \
# 2. Then it runs `make` and compiles the project with the `-g` flag \
# 3. Now you can run `gdb` to debug the program

