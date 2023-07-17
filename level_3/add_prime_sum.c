/*

Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>

*/

#include <unistd.h>

int ft_atoi(char *s) {
    int i = 0;
    int result = 0;
    while(s[i] >= '0' && s[i] <= '9') {
        result = result * 10 + s[i] - '0';
        i++;
    }
    return result;
}

int is_prime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; ++i) {
        if(n % i == 0)
            return 0;
    }
    return 1;
}

void putnbr(int n) {
    if (n >= 10)
        putnbr(n/10);
    char digit = n % 10 + '0';
    write(1, &digit, 1);
}

int main(int ac, char **av) {
    if (ac == 2) {
        int n = ft_atoi(av[1]);
        if (n <= 0) {
            write(1, "0\n", 2);
            return 0;
        }
        int sum = 0;
        while (n > 0) {
            if (is_prime(n)) {
                sum += n;
                n--;
            }
        }
        putnbr(sum);
    } else write(1, "0", 1);
    write(1, "\n", 1);
    return 0;
}