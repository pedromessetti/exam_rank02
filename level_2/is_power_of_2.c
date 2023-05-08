/*
Write a function that determines if a given number is a power of 2.
This function returns 1 if the given number is a power of 2, otherwise it returns 0.
*/

int is_power_of_2(unsigned int n) {
    int num = 1;
    while (num <= n) {
        if(num == n)    return 1;
        num *= 2;
    }
    return 0;
}
