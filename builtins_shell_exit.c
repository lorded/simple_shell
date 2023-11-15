#include "shell.h"

/**
 * shell_exit - Exit the shell.
 * @args: Arguments.
 *
 * This function exits the shell. If an argument is provided, it is used as the
 * exit status; otherwise, the default exit status is 0.
 *
 * Return: This function does not return.
 */
void shell_exit(char **args)
{
    int status = 0;

    if (args[1] != NULL)
    {
        status = _atoi(args[1]);
    }
    free_tokens(args);
    free_last_input();
    exit(status);
}

