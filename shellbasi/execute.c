#include "main.h"
/**
 */

pid_t exec_cmd(char **args, char **av)
{
    char *buffer = NULL;
    pid_t pid;
    int i, status, exitstatus, cmd = 0;

    pid = fork();

    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        cmd = execve(args[0], args, NULL);
        if (cmd == -1)
	{
            perror(args[0]);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        if (wait(&status) == -1)
	{
            perror("wait");
            exit(EXIT_FAILURE);
        }
	if (WIFEXITED(status))
	{
		exitstatus = WEXITSTATUS(status);
	}
	for (i = 0; av[i]; i++)
	
	free(av[i]);
	free(av);
	free(buffer);
	return (exitstatus);
    }
    return (pid);
}

