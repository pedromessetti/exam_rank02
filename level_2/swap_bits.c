/*
Write a function that takes a byte, swaps its halves (like the example) and
returns the result.
*/

unsigned char swap_bits(unsigned char octet) {
	return ((octet >> 4) | (octet << 4));
}
