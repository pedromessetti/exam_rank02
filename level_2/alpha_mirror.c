/*
Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.

'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'

and so on.

Case is not changed.

If the number of arguments is not 1, display only a newline.
*/

#include <unistd.h>

int is_alpha(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'z')) return 1;
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 2) {
        for (int i = 0; av[1][i] ; i++) {
            if (is_alpha(av[1][i])) {
                char oposite = av[1][i] >= 'a' ? 'z' - (av[1][i] - 'a') : 'Z' - (av[1][i] - 'A');
                write(1, &oposite, 1);
            } else write(1, &av[1][i], 1);
        }
    }
    write(1, "\n", 1);
    return 0;
}