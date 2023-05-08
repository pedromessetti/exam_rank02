/*
Write a program that takes three strings:
- The first and the third one are representations of base-10 signed integers
  that fit in an int.
- The second one is an arithmetic operator chosen from: + - * / %

The program must display the result of the requested arithmetic operation,
followed by a newline. If the number of parameters is not 3, the program
just displays a newline.

You can assume the string have no mistakes or extraneous characters. Negative
numbers, in input or output, will have one and only one leading '-'. The
result of the operation fits in an int.
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
    if (ac == 4) {
        int n1 = atoi(av[1]);
        int n2 = atoi(av[3]);
        if(av[2][0] == '+')
            printf("%i\n", n1+n2);
        else if(av[2][0] == '-')
            printf("%i\n", n1-n2);
        else if(av[2][0] == '*')
            printf("%i\n", n1*n2);
        else if(av[2][0] == '/')
            printf("%i\n", n1/n2);
        else if(av[2][0] == '%')
            printf("%i\n", n1%n2);
    } else printf("\n");
    return 0;
}