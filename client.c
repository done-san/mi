/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukasaw <nfukasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 02:57:46 by nfukasaw          #+#    #+#             */
/*   Updated: 2023/01/24 02:57:46 by nfukasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	error_proc(int errnum)
{
	if (errnum == USAGE)
		ft_putendl_fd("usage: ./client pid string", 2);
	else if (errnum == ERRPID)
		ft_putendl_fd("error: Process ID is invalid", 2);
	else if (errnum == ERRKILL)
		ft_putendl_fd("error: Failure to send signal", 2);
	exit(EXIT_FAILURE);
}

static void	send_signal(int pid, char c)
{
	size_t	bit;
	int		ret;

	bit = 0;
	while (bit < CHAR_BIT)
	{
		if (c >> bit & 1)
			ret = kill(pid, SIGUSR1);
		else
			ret = kill(pid, SIGUSR2);
		if (ret == -1)
			error_proc(ERRKILL);
		bit++;
		usleep(150);
	}
}

// ((9 <= c && c <= 13) || c == 32)
static int	convert_pid(const char *str)
{
	long long	num;

	while (('\t' <= *str && *str <= '\r') || *str == ' ')
		str++;
	num = 0;
	while (*str != '\0')
	{
		if (ft_isdigit(*str) == 0)
			error_proc(ERRPID);
		else
		{
			num = 10 * num + (*str - '0');
			if (num > INT_MAX / 10)
				error_proc(ERRPID);
		}
		str++;
	}
	if (num == 0)
		error_proc(ERRKILL);
	return ((int)num);
}

int	main(int argc, char **argv)
{
	int		pid;
	size_t	i;
	size_t	len;

	if (argc != 3)
		error_proc(USAGE);
	pid = convert_pid(argv[1]);
	i = 0;
	len = ft_strlen(argv[2]);
	while (i < len)
	{
		send_signal(pid, argv[2][i]);
		i++;
	}
	return (0);
}
