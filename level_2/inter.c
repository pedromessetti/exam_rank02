/*
Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.
*/

#include <unistd.h>

int is_double(char *s, char c, int posix) {
    int i = -1;
    while (++i < posix) {
        if (c == s[i])  return 0;
    }
    return 1;
}

int main(int ac, char **av) {
    if (ac == 3) {
        int i = -1;
        int j;
        while(av[1][++i]) {
            j = -1;
            while(av[2][++j]) {
                if(is_double(av[1], av[1][i], i))
                if(av[1][i] == av[2][j]) {
                    write(1, &av[1][i], 1);
                    break;
                }
            }
        }
    }
    write(1, "\n", 1);
    return 0;
}
