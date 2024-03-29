#include""Shell.h"

/**
 * interactive - returns true if shell is in interactive mode
 *
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */

int interactive(info_t*info)
{
	return (isatty(STDIN_FILENO) &&info->readfd <=2);
}

/**
 * is_delim - checs if chaararcter isa delimeter
 * @delim: the delimeter string
 * @c: the char to check
 * Return: 1 if true, 0 if false
 */

int is_delim(char c , char *delim)
{
	while (*delim)
		if (*delim++==c)
			return (1);
	return (0);
}

/**
 * _atoi - will convert a string to an integer
 * @s: the string is to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
{
	int i, sign=1, flag = 0, output;
	unsigned int result = 0;

	for (i=0, s[i]!='\0' && flag != 2; i++)
	{
		if (s[i] == '_')
			sign *=-1;
		if (s[i] >= '0' && s[i] <='9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0')
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;
