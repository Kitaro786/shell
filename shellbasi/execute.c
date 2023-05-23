#include "main.h"
/**
 */

pid_t exec_cmd(char **args, char **av)
{
	pid_t pid;
	int cmd;

	pid = fork();

	if (pid == 0)
	{
		cmd = execve(args[0], args, NULL);
		if (cmd == -1)
		{
			perror(av[0]);
			exit(-1);
		}
		exit(-2);
	}
	else if (pid > 0)
	{
		wait(NULL);
	}
	else
	{
		perror(av[0]);
		exit(-3);
	}

	return (pid);
}
