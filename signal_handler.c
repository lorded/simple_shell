#include "shell.h"

/**
 * handle_sigint - Signal handler for SIGINT (Ctrl+C).
 * @sig: Signal number.
 *
 * This function handles the SIGINT signal (Ctrl+C) by printing a newline,
 * and then displaying the shell prompt.
 *
 * Return: Nothing.
 */
void handle_sigint(int sig)
{
    (void)sig;
    _putchar('\n');
    prompt();
}

/**
 * handle_sigquit - Signal handler for SIGQUIT (Ctrl+\).
 * @sig: Signal number.
 *
 * This function handles the SIGQUIT signal (Ctrl+\) by printing an error
 * message and exiting the shell with EXIT_SUCCESS.
 *
 * Return: Nothing.
 */
void handle_sigquit(int sig)
{
    (void)sig;
    _puterror("Quit (core dumped)\n");
    exit(EXIT_SUCCESS);
}

/**
 * handle_sigstp - Signal handler for SIGTSTP (Ctrl+Z).
 * @sig: Signal number.
 *
 * This function handles the SIGTSTP signal (Ctrl+Z) by printing a newline
 * and displaying the shell prompt.
 *
 * Return: Nothing.
 */
void handle_sigstp(int sig)
{
    (void)sig;
    _puts("\n");
    prompt();
}

