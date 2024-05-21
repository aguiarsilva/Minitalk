/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 22:40:29 by baguiar-          #+#    #+#             */
/*   Updated: 2024/05/21 22:40:29 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void		signal_handler(int signum)
{
	static unsigned char	ch;
	static int				bit;

	if (signum == SIGUSR1)
		ch |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		if (ch == 4)
		{
			ch = 0;
			bit = 0;
			return ;
		}
		write(1, &ch, 1);
		ch = 0;
		bit = 0;
	}
}

static void		signal_reception(void)
{
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
}

int		main(void)
{
	ft_printf("Welcome to baguiar-'s server\n");
	ft_printf("Server's PID: %d\n", getpid());
	while (1)
		signal_reception();
	return (0);
}