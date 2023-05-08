/*
Write a function that reverses (in-place) a string. It must return its parameter.
*/

#include <stdio.h>

char    *ft_strrev(char *str) {
    char tmp;
    int len = -1;
    int i = -1;
    while(str[++len]);
    while(len/2 > ++i) {
        tmp = str[i];
        str[i] = str[len-1];
        str[len-1] = tmp;
        len--;
    }
    return str;
}
