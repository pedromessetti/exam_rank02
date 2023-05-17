/*
Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.
The display will be in the order characters appear in the command line, and
will be followed by a \n.
If the number of arguments is not 2, the program displays \n.
*/

#include <unistd.h>

int check(int c, char *s, int index) {
    int i = -1;
    while(++i < index) {
        if (s[i] == c)  return 0;
    }
    return 1;
}

int main(int ac, char **av) {
    if (ac == 3) {
        int len = -1;
        int j = 0;
        int k = 0;
        while(av[1][++len]);
        while(av[2][j]) {
            av[1][len] = av[2][j];
            len++;
            j++;
        }
        len--;
        while (k <= len) {
            if (check(av[1][k], av[1], k))
                write(1, &av[1][k], 1);
            k++;
        }
    }
    write(1, "\n", 1);
    return 0;
}