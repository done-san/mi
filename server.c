/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukasaw <nfukasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 02:57:52 by nfukasaw          #+#    #+#             */
/*   Updated: 2023/01/24 02:57:52 by nfukasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_receive_signal;

void	signal_handler(int signum)
{
	g_receive_signal = signum;
}

static void	print_char(void)
{
	static int	bit = 0;
	static int	ret = 0;

	if (g_receive_signal == SIGUSR1)
		ret += (0b0000001 << bit);
	if (bit == 7)
	{
		ft_putchar_fd(ret, 1);
		bit = 0;
		ret = 0;
		return ;
	}
	bit++;
}

int	main(void)
{
	ft_putstr_fd("PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	if (signal(SIGUSR1, signal_handler) == SIG_ERR)
		exit(EXIT_FAILURE);
	if (signal(SIGUSR2, signal_handler) == SIG_ERR)
		exit(EXIT_FAILURE);
	while (1)
	{
		pause();
		print_char();
	}
	return (0);
}
