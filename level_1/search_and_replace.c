/*
Write a program called search_and_replace that takes 3 arguments, the first
arguments is a string in which to replace a letter (2nd argument) by
another one (3rd argument).

If the number of arguments is not 3, just display a newline.

If the second argument is not contained in the first one (the string)
then the program simply rewrites the string followed by a newline.
*/

#include <unistd.h>

int main(int ac, char **av)
{
    if (ac == 4 && !av[2][1] && !av[3][1]) {
		int i = -1;
		while(av[1][++i]) {
			if(av[1][i] == av[2][0])
				av[1][i] = av[3][0];
			write(1, &av[1][i], 1);
		}
    }
    write(1, "\n", 1);
    return 0;    
}
