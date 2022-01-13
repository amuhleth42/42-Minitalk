#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int	main(int argc, char **argv)
{
	int	id;

	id = fork();
	wait(0);
	printf("%d, parent : %d\n", getpid(), getppid());
	return (0);
}
