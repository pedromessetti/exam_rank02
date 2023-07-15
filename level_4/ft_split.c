/*

Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);

*/

#include <stdlib.h>

int is_space(char c) {
    if (c == ' ' || (c >= 9 && c <= 13))
        return 1;
    return 0;
}

int mem(char *s) {
    int i = 0;
    int j = 0;
    while (*s) {
        if (!is_space(*s) && !j) {
            j = 1;
            i++;
        }
        else if (is_space(*s))
            j = 0;
        s++;
    }
}

char *word(char *s, char *new_s) {
    int i = 0;
    while (s[i] && !is_space(s[i]))
        i++;
    new_s = (char *)malloc((i+1)*sizeof(char));
    if (!new_s)
        return NULL;
    i = -1;
    while (s[++i] && !is_space(s[i]))
        new_s[i] = s[i];
    new_s[i] = '\0';
    return new_s;
}

char **ft_split(char *str) {
    if (!*str)
        return NULL;
    char **new_s = (char **)malloc((mem(str)+1)*sizeof(char *));
    if (!new_s)
        return NULL;
    int i = 0;
    int j = 0;
    while (str[i]) {
        if (is_space(str[i]))
            i++;
        else {
            new_s[j] = word((char *)str+i, new_s[j]);
            j++;
            while (str[i] && !is_space(str[i]))
                i++;
        }
    }
    new_s[j] = NULL;
    return new_s;
}