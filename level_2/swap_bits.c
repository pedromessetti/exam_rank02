/*
Write a function that takes a byte, swaps its halves (like the example) and
returns the result.
*/

unsigned char swap_bits(unsigned char octet) { // 8 -- 0000 1000
	return ((octet >> 4) | (octet << 4));
}
