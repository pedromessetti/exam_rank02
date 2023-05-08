/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 05:33:46 by pedro             #+#    #+#             */
/*   Updated: 2023/05/08 10:23:21 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_lower(char c) {
	return c >= 'a' && c <= 'z';
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
				char base = is_lower(av[1][i]) ? 'a' : 'A';
				av[1][i] = base + (av[1][i] - base + 13) % 26;
			}
			write(1, &av[1][i], 1);
		}
	}
	write(1, "\n", 1);
	return 0;
}
