/*

Assignment name  : str_capitalizer
Expected files   : str_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or several strings and, for each argument,
capitalizes the first character of each word (If it's a letter, obviously),
puts the rest in lowercase, and displays the result on the standard output,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string. If a word only has one letter, it must be
capitalized.

If there are no arguments, the progam must display \n.

Example:

$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A First Little Test$
$> ./str_capitalizer "__SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
__second Test A Little Bit   Moar Complex$
   But... This Is Not That Complex$
     Okay, This Is The Last 1239809147801 But Not    The Least    T$
$>

*/

#include <unistd.h>

int is_space(char c) {
  if (c == ' ' || (c >= '\t' && c <= '\r'))
    return 1;
  return 0;
}

int is_upper(char c) {
  if (c >='A' && c <= 'Z')
    return 1;
  return 0;
}

int is_alpha(char c) {
  if (c >='a' && c <= 'z')
    return 1;
  return 0;
}

char *to_lower(char *s) {
  int i = -1;
  while (s[++i]) {
    if (is_upper(s[i]))
      s[i] += 32;
  }
  return s;
}

int main(int ac, char **av) {
    if (ac > 1) {
      int i = 0;
      while (av[++i]) {
        av[i] = to_lower(av[i]);
        int j = -1;
        while (av[i][++j]) {
          if ((is_space(av[i][j - 1]) && is_alpha(av[i][j])) || is_alpha(av[i][0]))
            av[i][j] -= 32;
          write(1, &av[i][j], 1);
        }
      write(1, "\n", 1);
      }
    }
    else
      write(1, "\n", 1);
    return 0;
}