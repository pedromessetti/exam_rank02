/*
Reproduce the behavior of the function strdup (man strdup).
*/

#include <stdlib.h>

char *ft_strdup(char *src) {
    char *dup;
    int len = -1;
    int i = -1;
    while (src[++len]);
    if(!(dup = malloc(sizeof(char *)*len+1))) return NULL;
    while (src[++i])
        dup[i] = src[i];
    dup[i] = '\0';
    return dup;
}
