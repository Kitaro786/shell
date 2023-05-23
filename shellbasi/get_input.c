#include "main.h"

int _putchar(char c)
{
    return write(1, &c, 1);
}

char *get_input(int ac, char **av)
{
    unsigned int i;
    char prompt[] = "Shell$ ";
    char *input = NULL;
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
    if (r == -1)
    {
        if (feof(stdin))
        {
            free(input);
            printf("\n");
            exit(0);
        }
        else
        {
            perror("getline");
            free(input);
            return NULL;
        }
    }
    strtok(input, "\n");
    if (strcmp(input, "exit") == 0)
    {
        free(input);
        exit(-1);
    }

    return input;
}
