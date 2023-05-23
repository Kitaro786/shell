#include "main.h"
/**
 * main - entry point for shell
 * @ac: no. of cmd line arguments
 * @av: list of cmd line arguments
 * @env: env variables
 * Return: 0 on success
 */

int main(int ac, char **av, char **env)
{
	unsigned int i, j;
	char *input = NULL, **args;
	/*pid_t pid;*/
	int command_count = 0;
	/*extern char **environ;*/
	struct stat st;

	while (1)
	{
		input = get_input(ac, av);
		command_count++;
		
		if (strcmp(input, "env") == 0 || strcmp(input, "printenv") == 0)
		{
			for (i = 0; env[i] != NULL; i++)
			{
				for (j = 0; env[i][j] != '\0'; j++)
				{
					_putchar(env[i][j]);
				}
				_putchar('\n');
			}
		}
		if (strcmp(input, " ") == 0 || strcmp(input, "\n") == 0)
		{
			continue;
		}
		
		args = malloc(100 * sizeof(char *));
		if (args == NULL)
		{
			perror(av[0]);
			exit(-1);
		}
		args = get_cmd(input, av);

		if (stat(args[0], &st) != 0) /*checks if command exists, if not exits */
		{
			perror(av[0]);
			continue;
		}

		exec_cmd(args, av);

		free(args);
		free(input);
	}
	return (0);
}
