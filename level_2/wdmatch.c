/*
Write a program that takes two strings and checks whether it's possible to
write the first string with characters from the second string, while respecting
the order in which these characters appear in the second string.
If it's possible, the program displays the string, followed by a \n, otherwise
it simply displays a \n.
If the number of arguments is not 2, the program displays a \n.
*/

#include <unistd.h>

void    ft_putstr(char *s) {
    int i = -1;
    while(s[++i])
        write(1, &s[i], 1);
}

int main(int ac, char **av) {
    if(ac == 3) {
        int i = -1;
        int j = 0;
        while (av[2][j]) 
            if(av[2][j++] == av[1][i])
                i++;
        if(!av[1][i])
            ft_putstr(av[1]);
    }
    write(1, "\n", 1);
    return 0;
}
