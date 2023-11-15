#include "shell.h"

/**
 * shell_env - Prints all the environment variables.
 *
 * This function prints all the environment variables to the standard output.
 *
 * Return: Always returns 0.
 */
int shell_env(void)
{
    int i;

    for (i = 0; environ[i]; i++)
    {
        _puts(environ[i]);
        _putchar('\n');
    }

    return 0;
}

