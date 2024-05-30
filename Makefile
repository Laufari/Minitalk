#COLORS#
GREEN = \033[1;92m
RED = \033[1;91m
NC = \033[0m
YELLOW=\033[1;93m

SRCS_SERVER = server.c ft_memcpy.c
SRCS_CLIENT = client.c
SERVER = server
CLIENT = client

CFLAGS = -Wall -Werror -Wextra #-fsanitize=address
LDFLAGS = -L $(PRINTF) -lftprintf

CC = cc
RM = rm -f

PRINTF = ./ft_printf

all:  print $(SERVER) $(CLIENT)


print:
		@make -C $(PRINTF)

$(SERVER): server.h
	$(CC) $(CFLAGS) $(SRCS_SERVER) $(LDFLAGS) -I$(PRINTF) -o  $@

$(CLIENT): client.h
	$(CC) $(CFLAGS) $(SRCS_CLIENT) $(LDFLAGS) -I$(PRINTF) -o  $@

clean:
		@make clean -s -C $(PRINTF)
		@$(RM) $(SERVER) $(CLIENT)
		@echo "$(RED)SERVER AND CLIENT DELETED $(NC)"

fclean: clean
		@make fclean -s -C $(PRINTF)
		@$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re print
