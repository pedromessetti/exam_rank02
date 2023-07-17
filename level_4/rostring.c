/*

Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>

*/

#include <unistd.h>
#include <stdlib.h>

int is_space(char c) {
    return (c == ' ' || c == '\t');
}

int main(int ac, char **av) {
    if (ac > 1) {

        if (!*av[1])
            return write(1, "\n", 1);

        int  i = 0;
        while (is_space(av[1][i]))
            i++;

        int start = i;
        while (av[1][i] && !is_space(av[1][i]))
            i++;

        int end = i;
        while(is_space(av[1][i]))
            i++;
            
        int flag = 0;
        while (av[1][i]) {
            while (is_space(av[1][i]) && is_space(av[1][i+1]))
                i++;
            if (is_space(av[1][i]))
                flag = 1;
            write(1, &av[1][i], 1);
            i++;
        }
        if (flag)
            write(1, " ", 1);
        while (start++ < end)
            write(1, &av[1][start], 1);
    }
    else
        write(1, "\n", 1);
    return 0;
}