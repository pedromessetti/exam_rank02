/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 05:33:46 by pedro             #+#    #+#             */
/*   Updated: 2023/05/07 06:02:55 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <ctype.h>

int	is_lower(char c) {
	return c <= 'a' && c >= 'z';
}

int is_alpha(char c) {
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int main(int ac, char **av) {
	if(ac == 2) {
		int i = -1;
		while(av[1][++i]) {
			char c = av[1][i];
			if(is_alpha(c)) {
				char base = islower(c) ? 'a' : 'A';
				c = base + (c - base + 13) % 26;
			}
			write(1, &c, 1);
		}
	}
	write(1, "\n", 1);
	return 0;
}