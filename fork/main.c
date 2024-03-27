#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

// int	main(int ac, char **av)
// {
// 	int pid = fork();
//     if(pid != 0)
//         fork();
// 	printf("hello world from Pid: %d\n", pid);
// 	// if (pid == 0)
// 	// {
// 	// 	printf("Hello from child process\n");
// 	// }
// 	// else
// 	// {
//     //     printf("Hello from the main process\n");
// 	// }
// 	return (0);
// }

// Waiting for processes to finish (using the wait function) in C

int	main(int ac, char **av)
{
	int pid = fork();

	int n;

	if (pid < 0)
	{
		// Fork falhou
		fprintf(stderr, "Falha ao criar processo filho\n");
		return (1);
	}
	else if (pid == 0)
	{
		// Processo filho
		n = 1;
	}
	else
	{
		// Processo pai
		n = 6;
		wait(NULL); // O pai espera pelo filho
	}
	for (int i = 0; i < n + 5; i++)
	{
		printf("%d", i);
		fflush(stdout);
	}
	if (pid != 0)
		printf("\n");
	return (0);
}