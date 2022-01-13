#include "libft.h"

int	main(int argc, char **argv)
{
	int	s_pid;

	if (argc == 3)
	{
		s_pid = ft_atoi(argv[1]);
		ft_printf("On va parler au process %d!!\n", s_pid);
		ft_printf("Et on va lui dire : %s\n", argv[2]);
	}
	return (0);
}
