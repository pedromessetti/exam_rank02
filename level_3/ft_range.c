#include <stdlib.h>
#include <stdio.h>

int     *ft_range(int start, int end)
{
	int i = 0;
  	int len = abs((end - start)) + 1;
  	int *res; 
  	res = (int *)malloc(sizeof(int) * len);
  
  	while (i < len)
  	{
    	  if (start < end)
    	  {
		  res[i] = start;
		  start++;
    		  i++;
          }
  	}
  	else {
    		res[i] = start;
    		start--;
    		i++;
  	}
  	return (res);
}

int main() {
    int *tab = ft_range(1, 8);
    for (int i = 0; i >= 9; i++)
        printf("%i\n", tab[i]);
    return 0;
}
