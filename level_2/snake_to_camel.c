/*

Assignment name  : snake_to_camel
Expected files   : snake_to_camel.c
Allowed functions: malloc, free, realloc, write
--------------------------------------------------------------------------------

Write a program that takes a single string in snake_case format
and converts it into a string in lowerCamelCase format.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

Examples:
$>./camel_to_snake "here_is_a_snake_case_word"
hereIsASnakeCaseWord
$>./camel_to_snake "hello_world" | cat -e
helloWorld$
$>./camel_to_snake | cat -e
$

*/

#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av) {
    if (ac == 2) {
        if (!*av[1])
            return write(1, "\n", 1);
        int i = -1;
        while (av[1][++i]) {
            if (av[1][i] == '_') {
                i++;
                av[1][i] = av[1][i] - 32;
            }
            write(1, &av[1][i], 1);
        }
    }
    write(1, "\n", 1);
    return 0;
}