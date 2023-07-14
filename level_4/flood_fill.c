/*

Assignment name  : flood_fill
Expected files   : *.c, *.h
Allowed functions: -
--------------------------------------------------------------------------------

Write a function that takes a char ** as a 2-dimensional array of char, a 
t_point as the dimensions of this array and a t_point as the starting point.

Starting from the given 'begin' t_point, this function fills an entire zone 
by replacing characters inside with the character 'F'. A zone is an group of 
the same character delimitated horizontally and vertically by other characters
or the array boundry.

The flood_fill function won't fill diagonally.

The flood_fill function will be prototyped like this:
  void  flood_fill(char **tab, t_point size, t_point begin);

The t_point structure is prototyped like this:

  typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;

Example:

$> cat test.c
#include <stdlib.h>
#include <stdio.h>
#include "flood_fill.h"

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}

$> gcc flood_fill.c test.c -o test; ./test
11111111
10001001
10010001
10110001
11100001

FFFFFFFF
F000F00F
F00F000F
F0FF000F
FFF0000F
$> 

*/

typedef struct  s_point
{
int           x;
int           y;
}               t_point;

void fill(char**tab, t_point size, t_point curr, char to_fill) {
	if (curr.x < 0 || curr.x >= size.x || curr.y < 0 || curr.y >= size.y || tab[curr.y][curr.x] != to_fill)
		return ;
	tab[curr.y][curr.x] = 'F';
	fill(tab, size, (t_point){curr.x, curr.y+1}, to_fill);
	fill(tab, size, (t_point){curr.x, curr.y-1}, to_fill);
	fill(tab, size, (t_point){curr.x+1, curr.y}, to_fill);
	fill(tab, size, (t_point){curr.x-1, curr.y}, to_fill);
}

void  flood_fill(char **tab, t_point size, t_point begin) {
	fill(tab, size, begin, tab[begin.y][begin.x]);
}