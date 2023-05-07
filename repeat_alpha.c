/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:16:59 by pedro             #+#    #+#             */
/*   Updated: 2023/05/07 22:06:41 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	ft_tolower(char c) {
		if (c <= 'Z' && c >= 'A')
			c = c + 32;
	return c;
}

int is_alpha(char c) {
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return 1;
	return 0;
}

int main(int ac, char **av) {
	if(ac == 2) {
		int i = -1;
		while(av[1][++i]) {
			if(is_alpha(av[1][i])) {
				int posix = ft_tolower(av[1][i]) - 'a' + 1;
				for (int j = 0; j < posix; j++)
					write(1, &av[1][i], 1);
			} else 
				write(1, &av[1][i], 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
