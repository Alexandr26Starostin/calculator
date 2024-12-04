#include <stdio.h>
#include <assert.h>

#include "const_in_calculate.h"
#include "grammar.h"

calculate_error_t get_g (char* str, size_t* ptr_index, double* ptr_value)
{
	assert (str);
	assert (ptr_index);
	assert (ptr_value);

	double value = 0;

	calculate_error_t status = get_n (str, ptr_index, &value);

	if (status) {return status;}

	if (str[*ptr_index] != '\0')
	{
		printf ("Error in %s:%d\n\n", __FILE__, __LINE__);
		printf ("Error from 'get_g' in str on position: %ld\n\n'get_g' wait: '\\0', but find '%c'\n\n", *ptr_index, str[*ptr_index]);

		return ERROR_IN_GET_G;
	}

	*ptr_value = value;
	(*ptr_index)++;

	return status;
}

calculate_error_t get_n (char* str, size_t* ptr_index, double* ptr_value)
{
	assert (str);
	assert (ptr_index);
	assert (ptr_value);

	double value = 0;

	size_t old_index = *ptr_index;

	if ('0' <= str[*ptr_index] && str[*ptr_index] <= '9')
	{
		value += str[*ptr_index] - '0';

		(*ptr_index)++;
	}

	if (*ptr_index == old_index)
	{
		printf ("Error in %s:%d\n\n", __FILE__, __LINE__);
		printf ("Error from 'get_n' in str on position: %ld\n\n'get_n' wait: ['0' - '9'], but find '%c'\n\n", *ptr_index, str[*ptr_index]);

		return ERROR_IN_GET_N;
	}

	*ptr_value = value;

	return NOT_ERROR;
}
