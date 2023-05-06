/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 11:53:35 by pedro             #+#    #+#             */
/*   Updated: 2023/05/06 12:25:55 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define DECIMAL "0123456789"

void	writer(int n)
{
	if (n > 9)
		writer(n / 10);
	write(1, &DECIMAL[n % 10], 1);
}

int	main(void)
{
	int n = 0;
	while (++n <= 100)
	{
		if (n % 15 == 0)
			write(1, "fizzbuzz", 8);
		else if (n % 3 == 0)
			write(1, "fizz", 4);
		else if (n % 5 == 0)
			write(1, "buzz", 4);
		else
			writer(n);
		write(1, "\n", 1);
	}
	return (0);
}