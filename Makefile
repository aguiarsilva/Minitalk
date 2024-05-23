# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 14:53:49 by baguiar-          #+#    #+#              #
#    Updated: 2024/05/21 14:53:49 by baguiar-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minitalk

CC			= cc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -rf

LIBFT = ./LIBFT

LIBFT_LIB = $(LIBFT)/libft.a

SERVER_SRC		= server.c
CLIENT_SRC		= client.c

SERVER_OBJ		= $(SERVER_SRC:.c=.o)
CLIENT_OBJ		= $(CLIENT_SRC:.c=.o)

SERVER = server
CLIENT = client

all: libft $(SERVER) $(CLIENT)

libft:
	@$(MAKE) -C $(LIBFT)

$(SERVER): $(SERVER_OBJ) $(OBJS)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJ) $(OBJS) $(LIBFT_LIB)

$(CLIENT): $(CLIENT_OBJ) $(OBJS)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJ) $(OBJS) $(LIBFT_LIB)

clean:
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ) $(OBJS)
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
		$(RM) $(SERVER_OBJ) $(CLIENT_OBJ)
		@$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re libft
