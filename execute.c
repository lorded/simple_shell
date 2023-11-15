#include "shell.h"

/**
 * execute - Execute a command with arguments.
 * @args: An array of strings containing the command and its arguments.
 *
 * Return: The exit status of the executed command.
 */
int execute(char **args)
{
    pid_t process_id;
    int status = 0;
    char *command_path, *environment[2];

    if (args == NULL || *args == NULL)
        return status;

    if (check_for_builtin(args))
        return status;

    process_id = fork();

    if (process_id == -1)
    {
        perror("fork");
        return 1;
    }

    if (process_id == 0) /* Child Process */
    {
        environment[0] = get_path();
        environment[1] = NULL;
        command_path = NULL;

        if (args[0][0] != '/')
            command_path = find_in_path(args[0]);

        if (command_path == NULL)
            command_path = args[0];

        if (execve(command_path, args, environment) == -1)
        {
            perror(args[0]);
            exit(EXIT_FAILURE);
        }
    }
    else /* Parent Process */
    {
        do
        {
            waitpid(process_id, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return status;
}

