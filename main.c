#include "shell.h"

/**
 * main - Implements a simple shell.
 *
 * Return: EXIT_SUCCESS.
 */
int main(void)
{
	char *input;
	char **arguments;
	int status;

	/* Register signal handlers */
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	signal(SIGTSTP, handle_sigstp);

	do {
		input = get_input();
		if (!input || !*input)/* EOF detected, exit the loop */
			break;

		arguments = tokenize_input(input);
		if (!arguments || !*arguments)
		{
			free(input);
			free_tokens(arguments);
			continue;
		}
		status = execute(arguments);
		free(input);
		free_tokens(arguments);

		/* Set status to 1 to continue the loop */
		status = 1;
	} while (status);

	return (EXIT_SUCCESS);
}
