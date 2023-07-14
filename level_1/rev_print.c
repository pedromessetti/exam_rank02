/*

Assignment name  : rev_print
Expected files   : rev_print.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays the string in reverse
followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./rev_print "zaz" | cat -e
zaz$
$> ./rev_print "dub0 a POIL" | cat -e
LIOP a 0bud$
$> ./rev_print | cat -e
$

*/

#include <unistd.h>

int ft_strlen(char *s)
{
	int i = -1;
	while(s[++i]);
	return i;
}

int main(int ac, char**av) {
	if (ac == 2) {
		int i = ft_strlen(av[1]);
		while (av[1][--i])
			write(1, &av[1][i], 1);
	}
	write(1, "\n", 1);
	return 0;
}