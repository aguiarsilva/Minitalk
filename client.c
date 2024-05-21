/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 21:55:01 by baguiar-          #+#    #+#             */
/*   Updated: 2024/05/21 21:55:01 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void		exit_err(void)
{
	ft_printf("\nError\n\n");
	exit(1);
}

static void		validate_pid(char *pid)
{
	int		i;

	i = 0;
	while (pid[i])
	{
		if (!ft_isdigit(pid[i]))
		{
			ft_printf("\nInvalid PID.\n\nOnly digits are accepted!\n\n");
			exit(1);
		}
		i++;
	}
}

void	signals_send(char c, int pid)
{
	int		bit;
	int		i;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if (bit == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit_err();
		}
		else 
		{
			if (kill(pid, SIGUSR2) == -1)
				exit_err();
		}
		usleep(100);
		i--;
	}
}

int		main(int argc, char **argv)
{
	int		i;
	int		pid;

	if (argc != 3)
	{
		ft_printf("\nError on amount of arguments!\n\n");
		ft_printf("Usage: ./client <PID> <MESSAGE>");
		return (1);
	}
	i = 0;
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("\nInvalid PID! Use only positive numbers!\n");
		return (1);
	}
	validate_pid(argv[1]);
	while (argv[2][i])
	{
		signals_send(argv[2][i], pid);
		i++;
	}
	signals_send((char)4, pid);
	return (0);
}