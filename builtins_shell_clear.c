#include "shell.h"

/**
 * shell_clear - Clears the terminal screen.
 * @args: An array of arguments (unused, avoids "unused parameter" warning).
 *
 * This function clears the terminal screen using ANSI escape codes.
 *
 * Return: 1 to continue executing, or 0 to exit.
 */
int shell_clear(char **args)
{
    (void)args; /* Avoid "unused parameter" warning */
    _puts("\033[2J\033[H");
    return 1;
}

