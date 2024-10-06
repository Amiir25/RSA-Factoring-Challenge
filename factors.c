#include <stdio.h>
#include <stdlib.h>

/**
 * factorize - Factorizes a number into a product of two smaller numbers
 * @num: The number to be factorized
 *
 * Return: Nothing
 */

void factorize(long int num)
{
	long int i;

	for (i = 2; i <= num / 2; i++)
	{
		if (num % i == 0)
		{
			printf("%ld=%ld*%ld\n", num, i, num / 2);
			return;
		}
	}

	printf("%ld=1*%ld\n", num, num);
}

/**
 * main - Entry
 * @ac: The number of arguements
 * @av: Array of arguements
 *
 * Return: Always 0
 */

int main(int ac, char *av[])
{
	FILE *file;
	long int num;

	if (ac != 2)
	{
		printf("Usage: %s <file>\n", av[0]);
		return (1);
	}

	file = fopen(av[1], "r");
	if (file == NULL)
	{
		perror("Error opening file");
		return (1);
	}

	while (fscanf(file, "%ld", &num) != EOF)
		factorize(num);

	fclose(file);
	return (0);
}
