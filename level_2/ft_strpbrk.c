/*
Reproduce exactly the behavior of the function strpbrk
*/
#include <stdio.h>
#include <string.h>

char	*ft_strpbrk(const char *s1, const char *s2) {
    int i;
    if (!s1 || !s2) return 0;
    while(*s1) {
        i = -1;
        while(s2[++i]) {
            if(*s1 == s2[i]) return (char *)s1;
        }
        s1++;
    }
    return 0;
}

int main() {
    printf("og: %s\nmy: %s\n", strpbrk("hello", "h"), ft_strpbrk("hello", "h"));
    return 0;
}