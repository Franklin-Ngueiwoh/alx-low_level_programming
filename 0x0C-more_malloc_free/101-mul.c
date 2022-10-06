#include "main.h"

/**
 * error_message - print an error message and exit with status 98
 * Return: Nothing
 */
void error_message(void)
{
	char error_msg[] = "Error";
	int i = 0;

	while (error_msg[i] != '\0')
	{
		_putchar(error_msg[i]);
		i++;
	}

	_putchar('\n');

	exit(98);
}

/**
 * main - multiply 2 long numbers
 * usage <> ./mul num1 num2
 * @ac: number of arguments
 * @av: list of arguments
 * Return: 0 on success, another number otherwise
 */
int main(int ac, char **av)
{
	char *a = NULL, *b =  NULL;
	int i = 0, len_a = 0, len_b = 0, is_a = 1, is_b = 1, len_r = 0;
	add_t *result = NULL;

	if (ac != 3)
		error_message();

	for (i = 0, a = av[1], b = av[2]; is_a == 1 || is_b == 1; i++)
	{
		if (is_a == 1 && a[i] == '\0')
			is_a = 0, len_a = i;
		if (is_b == 1 && b[i] == '\0')
			is_b = 0, len_b = i;
		if ((is_a == 1 && (a[i] < '0' || a[i] > '9')) ||
				(is_b == 1 && (b[i] < '0' || b[i] > '9')))
			error_message();
	}

	if (len_a == 0 || len_b == 0)
		error_message();

	len_r = len_a + len_b;
	if (len_a > len_b)
		a = av[2], b = av[1], len_a = len_b, len_b = len_r - len_b;

	result = adding_all_mul(a, len_a, b, len_b);

	print_free_result(result);

	return (0);
}
