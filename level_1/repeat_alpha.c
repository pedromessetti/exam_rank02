/*

Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>

*/

#include <unistd.h>

char	ft_lower(char c) {
	if (c <= 'Z' && c >= 'A')
		c += 32;
	return c ;
}

int is_alpha(char c) {
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return 1;
	return 0;
}

int main(int ac, char **av) {
	if(ac == 2) {
		int i = -1;
		while(av[1][++i]) {
			if(is_alpha(av[1][i])) {
				int posix = ft_lower(av[1][i]) - 'a' + 1;
				for (int j = 0; j < posix; j++)
					write(1, &av[1][i], 1);
			} else 
				write(1, &av[1][i], 1);
		}
	}
	write(1, "\n", 1);
	return 0;
}
