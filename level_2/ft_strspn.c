/*
Reproduce exactly the behavior of the strspn function 
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s) {
		if (*s == c)   return ((char *)s);
		++s;
	}
	return 0;
}

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t i = -1;

	while (s[++i]) {
		if (ft_strchr(accept, s[i]) == 0)	break;
	}
	return i;
}
