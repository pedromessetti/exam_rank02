/*
Reproduce exactly the behavior of the function strcspn.
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>

size_t  ft_strcspn(const char *s, const char *reject)
{
    int     i = -1;
    int     j;
    while (s[++i]) {
		j = -1;
        while (reject[++j])
            if(s[i] == reject[j]) return i;
    }
    return i;
}
