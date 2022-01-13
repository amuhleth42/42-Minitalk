S_SRCS		= server.c
C_SRCS		= client.c
S_OBJS		= ${S_SRCS:.c=.o}
C_OBJS		= ${C_SRCS:.c=.o}

FLAGS		= -Wall -Wextra -Werror
LIBFT		= -L./libft -lft

all :		server client


server :	libft
			gcc $(FLAGS) $(LIBFT) $(S_SRCS) -o server


client :	libft
			gcc $(FLAGS) $(LIBFT) $(C_SRCS) -o client


libft :
			$(MAKE) -C .libft

clean :
			$(MAKE) clean -C ./libft
			rm *.o

fclean :	clean
			$(MAKE) fclean -C ./libft
			rm server
			rm client

re :		fclean all

.PHONY :	re all clean fclean
