/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 05:20:13 by pedro             #+#    #+#             */
/*   Updated: 2023/05/07 22:05:35 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *s)
{
	int i = -1;
	while(s[++i]);
	return i;
}

int main(int ac, char**av) { //  ./a.out "dub0 a POIL" ----> $ LIOP a 0bud
	if (ac == 2) {
		int i = ft_strlen(av[1]);
		while (av[1][--i])
			write(1, &av[1][i], 1);
	}
	write(1, "\n", 1);
	return 0;
}