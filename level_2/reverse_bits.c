/*
Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.
*/

#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int		i = 8;
	unsigned char	res = 0;

	while (--i >= 0) {
		res |= (octet >> i);
		res <<= 1;
	}
	return (res);
}

unsigned char	reverse_bits_2(unsigned char octet)
{
	int		i = 8;
	unsigned char	res = 0;

	while (i > 0)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		i--;
	}
	return (res);
}

int main() {
	printf("%d\n", reverse_bits(2));
	printf("%d\n", reverse_bits_2(2));
}