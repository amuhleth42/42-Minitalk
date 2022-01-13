#include <unistd.h>
#include "libft.h"


int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("PID : %d\n", pid);
	return (0);
}
