#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int	pid;
	int	file;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		file = open("file.txt", O_WRONLY | O_CREAT, 0777 );
        if (file == -1)
            return 2;
		printf("the fd to file: %d\n", file);
        int file2 = dup2(file, STDOUT_FILENO);
        printf("the duplicated fd: %d\n", file2);
        printf("t fd: %d\n", file2);
        close(file);
		if (execve(av[1], &av[1], NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		printf("Hello from the main process\n");
	}
	return (0);
}
