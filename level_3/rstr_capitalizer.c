/*

Assignment name  : rstr_capitalizer
Expected files   : rstr_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or more strings and, for each argument, puts 
the last character that is a letter of each word in uppercase and the rest
in lowercase, then displays the result followed by a \n.

A word is a section of string delimited by spaces/tabs or the start/end of the
string. If a word has a single letter, it must be capitalized.

A letter is a character in the set [a-zA-Z]

If there are no parameters, display \n.

Examples:

$> ./rstr_capitalizer | cat -e
$
$> ./rstr_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A firsT littlE tesT$
$> ./rstr_capitalizer "SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
seconD tesT A littlE biT   moaR compleX$
   but... thiS iS noT thaT compleX$
     okay, thiS iS thE lasT 1239809147801 buT noT    thE leasT    T$
$>

*/

#include <unistd.h>

int is_space(char c) {
  if (c == ' ' || (c >= '\t' && c <= '\r'))
    return 1;
  return 0;
}

int is_alpha(char c) {
  if (c >= 'a' && c <= 'z')
    return 1;
  return 0;
}

int is_upper(char c) {
  if (c >= 'A' && c <= 'Z')
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
      while(av[i][++j]) {
        if ((is_space(av[i][j + 1]) && is_alpha(av[i][j])) || (!av[i][j + 1] && is_alpha(av[i][j])))
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