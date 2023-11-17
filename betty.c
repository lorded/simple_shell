#include "shell.h"
#include <stdio.h>
/**
 * main - entry point
 * Return: output
 */
int main(void)
{
	int number, square;

	printf("Enter a number: ");
	scanf("%d", &number);

	square = calculate_square(number);
	printf("The square of %d is: %d\n", number, square);

	return (0);
}

