/*
Write a program that takes a string and reverses the case of all its letters.
Other characters remain unchanged.

You must display the result followed by a '\n'.

If the number of arguments is not 1, the program displays '\n'.
*/

#include <unistd.h>

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int i = -1;
        while(av[1][++i]) {
            if (av[1][i] >= 'a' && av[1][i] <= 'z')
                av[1][i] -= 32;
            else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
                av[1][i] += 32;
            write(1, &av[1][i], 1);
        }
    }
    write(1, "\n", 1);
    return 0;
}