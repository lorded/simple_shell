#include "shell.h"

/**
 * check_for_builtin - Checks if the command is a built-in.
 * @args: The arguments array.
 *
 * This function checks if the command specified in the arguments array is a
 * built-in command. If it is, it executes the corresponding built-in function.
 *
 * Return: 1 if the command is a built-in, 0 otherwise.
 */
int check_for_builtin(char **args)
{
    if (!args[0])
        return 0;

    if (!_strcmp(args[0], "exit"))
        shell_exit(args);
    else if (!_strcmp(args[0], "env"))
        shell_env();
    else if (!_strcmp(args[0], "setenv"))
        shell_setenv(args);
    else if (!_strcmp(args[0], "unsetenv"))
        shell_unsetenv(args);
    else if (!_strcmp(args[0], "help"))
        shell_help();
    else if (!_strcmp(args[0], "cd"))
        shell_cd(args);
    else if (!_strcmp(args[0], "clear"))
        shell_clear(args);
    else
        return 0;

    return 1;
}

