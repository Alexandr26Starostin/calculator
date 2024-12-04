#ifndef CONST_IN_CALCULATE_H
#define CONST_IN_CALCULATE_H

enum calculate_error_t
{
	NOT_ERROR      = 0,
	ERROR_IN_GET_G = 1,
	ERROR_IN_GET_N = 2,
	ERROR_IN_GET_P = 3
};

const size_t MAX_LEN_STR = 100;

#endif