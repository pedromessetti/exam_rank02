/*

Assignment name  : rotone
Expected files   : rotone.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the next one in alphabetical order.

'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.

The output will be followed by a \n.

If the number of arguments is not 1, the program displays \n.

Example:

$>./rotone "abc"
bcd
$>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
$>./rotone "AkjhZ zLKIJz , 23y " | cat -e
BlkiA aMLJKa , 23z $
$>./rotone | cat -e
$
$>
$>./rotone "" | cat -e
$
$>

*/

#include <unistd.h>

int is_alpha(char c) {
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int main(int ac, char **av) {
	if(ac == 2) {
		int i = -1;
		while(av[1][++i]) {
			if(is_alpha(av[1][i])) {
				char base = (av[1][i] >= 'a' && av[1][i] <= 'z') ? 'a' : 'A';
				av[1][i] = base + (av[1][i] - base + 1) % 26;
			}
			write(1, &av[1][i], 1);
		}
	}
	write(1, "\n", 1);
	return 0;
}