/*
The first parameter is an array of int, the second is the number of elements in
the array.
The function returns the largest number found in the array.
If the array is empty, the function returns 0.
*/

#include <stdio.h>

int max(int *tab, unsigned int len) {
    unsigned int i = -1;
    int current = tab[0];
    while (++i <= len) {
        if (tab[i] > current)
            current = tab[i];
    }
    return current;
}
