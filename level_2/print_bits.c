/*
Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.
*/

#include <unistd.h>

void	print_bits(unsigned char octet) { //42
    int maxbits = 8;
    unsigned char bit;
    while (maxbits--) {
        bit = (octet >> maxbits & 1) + '0'; // 42>>6
        write(1, &bit, 1); // 00
    }
}
