/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 09:55:34 by pedro             #+#    #+#             */
/*   Updated: 2023/05/07 22:13:39 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_printable(char c)  {
	if ((c > 32 && c < 127))
		return (1);
	return (0);
}

int	is_space_tab(char c) {
	if (c == 32 || c == 9)
		return (1);
	return (0);
}

int	main(int ac, char **av) {
	if (ac == 2) {
		int i = -1;
		while (av[1][++i]) {
			while (is_space_tab(av[1][i]))
				i++;
			if (is_printable(av[1][i])) {
				write(1, &av[1][i], 1);
				if (!is_printable(av[1][i + 1]))
					return (write(1, "\n", 1));
			} else break ;
		}
	}
	write(1, "\n", 1);
	return (0);
}
