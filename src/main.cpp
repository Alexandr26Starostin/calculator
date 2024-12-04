#include <stdio.h>

#include "const_in_calculate.h"
#include "grammar.h"

int main ()
{
	printf ("Привет!\n\n");

	char str[MAX_LEN_STR] = "12+42-30";

	size_t index = 0;

	double value = 0;

	calculate_error_t status = get_g (str, &index, &value);

	if (status) {return status;}

	printf ("value = %lg\n", value);

	return status;
}