/*

Assignment name  : expand_str
Expected files   : expand_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it with exactly three spaces
between each word, with no spaces or tabs either at the beginning or the end,
followed by a newline.

A word is a section of string delimited either by spaces/tabs, or by the
start/end of the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./expand_str "See? It's easy to print the same thing" | cat -e
See?   It's   easy   to   print   the   same   thing$
$> ./expand_str " this        time it      will     be    more complex  " | cat -e
this   time   it   will   be   more   complex$
$> ./expand_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> 
$
$>

*/

#include <unistd.h>

int ft_is_space(char c) {
    if (c == ' ' || (c >= 9 && c <= 13))
        return 1;
    return 0;
}

int ft_strlen(char *s) {
    int i = -1;
    while (s[++i]);
    return i;
}

int main(int ac, char **av) {
    if (ac == 2) {
        if (!*av[1])
            return write(1, "\n", 1);
        
        while(ft_is_space(*av[1]))
            av[1]++;
        
        int len = ft_strlen(av[1]);

        while (ft_is_space(av[1][len]))
            len--;
        
        int i = -1;
        while (av[1][++i] && i < len + 1) {
            if (!ft_is_space(av[1][i]))
                write(1, &av[1][i], 1);
            while(ft_is_space(av[1][i]) && i < len + 1) {
                if (!ft_is_space(av[1][i+1]) && av[1][i+1]) {
                    write(1, "   ", 3);
                    break ;
                }
                i++;
            }
        }

    }
    write(1, "\n", 1);
    return 0;
}