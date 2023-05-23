#include "main.h"
/**
 * get_cmd - 
 * @input: user input
 * Return: pointer to args
 */

char **get_cmd(char *input, char **av)
{
	unsigned int i = 0, j;
	char *token, *buff = NULL, **path = NULL, **args = NULL;

	token = strtok(input, " ");
	path = malloc(1000 * sizeof(char *));
	if (path == NULL)
	{
		perror(av[0]);
		exit(0);
	}

	while (token != NULL && i < 1000)
	{
		path[i] = strdup(token);
		i++;
		token = strtok(NULL, " ");
	}

	if (strncmp(path[0], "/bin/", strlen("/bin/")) != 0)
	{
		/*if input doesnt include path adds: /bin/ */
		buff = malloc(strlen("/bin/") + strlen(path[0]) + 1);
		if (buff == NULL)
		{
			perror(av[0]);
			exit(0);
		}
		strcpy(buff, "/bin/");
		strcat(buff, path[0]);
		path[0] = buff;
	}
	args = malloc((i + 1) * sizeof(char *));
	if (args == NULL)
	{
		perror(av[0]);
		exit(0);
	}
	for (j = 0; j < i; j++)
	{
		args[j] = path[j];
	}
	args[j] = NULL;

	free(buff);
	free(path);
	return (args);
}
