#include "main.h"

/**
 * _putchar - prints to stdout
 * @c: char to print
 * Return: 1 on success
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}

/**
 * get_input - prints prompt if shell interactive & gets user input
 * @ac: no. of arguments
 * @av: list of arguments
 * Return: pointer to input on success, NULL on failure or EOF
 */
char *get_input(int ac, char **av)
{
    unsigned int i;
    char prompt[] = "Shell$ ";
    char *input = NULL;
    size_t l = 0;
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
        return NULL;
    }

    if (feof(stdin))
    {
        free(input);
        exit(0);
    }

    if (input[strlen(input) - 1] == '\n')
    {
        input[strlen(input) - 1] = '\0';
    }

    if (strcmp(input, "exit") == 0)
    {
        free(input);
        exit(-1);
    }

    return input;
}
