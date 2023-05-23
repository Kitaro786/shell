#include "main.h"

/**
 * _putchar - prints to stdout
 * @c: char to print
 * Return: 1 on succes
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * get_input - prints prompt if shell interactive & gets user input
 * @ac: no. of arguments
 * @av: list of arguments
 * Return: 1 on success
 */
char *get_input(int ac, char **av)
{
	unsigned int i;
	char prompt[] = "Shell$ ", *input = NULL;
	size_t l;
	ssize_t r;
	(void)ac;
	(void)av;

	if (isatty(STDIN_FILENO))
	{
		for (i = 0; prompt[i] != '\0'; i++)
		{
			_putchar(prompt[i]);
		}
	}

	r = getline(&input, &l, stdin);
	if (r == -1 || input == NULL)
	{
		free(input);
		return (NULL);
	}
	if (feof(stdin))
	{
		free(input);
		exit(0);
	}
	strtok(input, "\n");
	if (strcmp(input, "exit") == 0)
	{
		free(input);
		exit(-1);
	}

	return (input);
}
