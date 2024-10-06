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
	long int factor1;
	long int factor2;
	int i;

	factor1 = factor2 = 0;
	for (i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
		{
			factor1 = i;
			factor2 = num / i;
			break;
		}
	}

	if (factor1 != 0)
		printf("%ld=%ld*%ld\n", num, factor1, factor2);

	else
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

	return (0);
}
