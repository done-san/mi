NAME	= minitalk
CLIENT	= client
SERVER	= server
INCLUDE	= minitalk.h

CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP

SRC_CL = client.c
SRC_SE = server.c
OBJ_CL = $(SRC_CL:.c=.o)
OBJ_SE = $(SRC_SE:.c=.o)
DEP_CL = $(SRC_CL:.c=.d)
DEP_SE = $(SRC_SE:.c=.d)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all :  $(LIBFT) $(CLIENT) $(SERVER)

$(LIBFT) :
		make -C $(LIBFT_DIR)

$(CLIENT) : $(OBJ_CL)
		$(CC) $(CFLAGS) $(OBJ_CL) $(LIBFT) -o $(CLIENT)

$(SERVER) : $(OBJ_SE)
		$(CC) $(CFLAGS) $(OBJ_SE) $(LIBFT) -o $(SERVER)

clean:
		rm -f $(OBJ_CL) $(OBJ_SE) $(DEP_CL) $(DEP_SE)
		make clean -C $(LIBFT_DIR)

fclean: clean
		rm -f $(CLIENT) $(SERVER)
		rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re

-include $(DEP_CL) $(DEP_SE)