/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukasaw <nfukasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 19:59:59 by nfukasaw          #+#    #+#             */
/*   Updated: 2022/07/17 19:59:59 by nfukasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;

	un = (unsigned int)n;
	if (n < 0)
	{
		un *= -1;
		ft_putchar_fd('-', fd);
	}
	if (un >= 10)
		ft_putnbr_fd((int)(un / 10), fd);
	ft_putchar_fd((char)(un % 10 + '0'), fd);
}
