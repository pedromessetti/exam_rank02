/*

Assignment name  : first_word
Expected files   : first_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its first word, followed by a
newline.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./first_word "FOR PONY" | cat -e
FOR$
$> ./first_word "this        ...       is sparta, then again, maybe    not" | cat -e
this$
$> ./first_word "   " | cat -e
$
$> ./first_word "a" "b" | cat -e
$
$> ./first_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>

*/


#include <unistd.h>

int	is_printable(char c)  {
	if ((c > 32 && c < 127)) return 1;
	return 0;
}

int	is_space_tab(char c) {
	if (c == 32 || c == 9) return 1;
	return 0;
}

int	main(int ac, char **av) {
	if (ac == 2) {
		int i = -1;
		while (av[1][++i]) {
			while (is_space_tab(av[1][i]))
				i++;
			if (is_printable(av[1][i])) {
				write(1, &av[1][i], 1);
				if (!is_printable(av[1][i + 1]))
					return (write(1, "\n", 1));
			} else break ;
		}
	}
	write(1, "\n", 1);
	return 0;
}
