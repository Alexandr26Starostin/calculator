#include <stdio.h>
#include <stdlib.h>

const char* s = "25*10*(3*(25-10*2)-15)+1$";
int         p = 0;
int     error = 0;

int get_g ();
int get_n ();
int get_e ();
int get_t ();
int get_p ();

// int main ()
// {
// 	printf ("result: %d\n", get_g ());

// 	return 0;
// }

//--------------------------------------------------------------------


int get_g ()
{
	int val = get_e ();

	if (s[p] != '$')
		exit (0);

	p++;

	return val;
}

int get_n ()
{
	int val = 0;
	int old_p = p;

	while ('0' <= s[p] && s[p] <= '9')
	{
		val = val * 10 + (s[p] - '0');

		p++;
	}

	if (p == old_p)
		exit (0);

	return val;
}

int get_e ()
{
	int val = get_t ();

	while (s[p] == '+' || s[p] == '-')
	{
		int old_p = p;

		p++;

		int val2 = get_t ();

		if (s[old_p] == '+')
			val += val2;
		else
			val -= val2;
	}

	return val;
}

int get_t ()
{
	int val = get_p ();

	while (s[p] == '*' || s[p] == '/')
	{
		int old_p = p;

		p++;

		int val2 = get_p ();

		if (s[old_p] == '*')
			val *= val2;
		else
			val /= val2;
	}

	return val;
}

int get_p ()
{
	if (s[p] == '(')
	{
		p++;
		int val = get_e ();

		if (s[p] != ')')
			exit (0);

		p++;

		return val;
	}

	else
	{
		return get_n ();
	}
}