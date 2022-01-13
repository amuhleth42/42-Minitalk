S_SRCS		= server.c
C_SRCS		= client.c

FLAGS		= -Wall -Wextra -Werror
INCL		= -I./libft
LIBFT		= -L./libft -lft

all :		server client


server :	libft.a
			gcc $(FLAGS) $(INCL) $(LIBFT) $(S_SRCS) -o server


client :	libft.a
			gcc $(FLAGS) $(INCL) $(LIBFT) $(C_SRCS) -o client


libft.a :
			make -C ./libft

clean :
			make clean -C ./libft

fclean :	clean
			make fclean -C ./libft
			rm server client

re :		fclean all

.PHONY :	re all clean fclean
