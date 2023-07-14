/*

Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);

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
