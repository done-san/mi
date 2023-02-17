/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukasaw <nfukasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:01:02 by nfukasaw          #+#    #+#             */
/*   Updated: 2022/09/17 16:24:46 by nfukasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_over(int sign)
{
	if (sign == 1)
		return ((int)LONG_MAX);
	else
		return ((int)LONG_MIN);
}

int	ft_isspace(char c)
{
	return (('\t' <= c && c <= '\r') || c == ' ');
}

int	ft_atoi(const char *str)
{
	int			sign;
	long long	num;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	num = 0;
	while (ft_isdigit(*str))
	{
		if (num > LONG_MAX / 10)
			return (check_over(sign));
		if (num == LONG_MAX / 10 && LONG_MAX % 10 < (*str - '0'))
			return (check_over(sign));
		num = 10 * num + (*str - '0');
		str++;
	}
	return ((int)(num * sign));
}

// ((9 <= c && c <= 13) || c == 32)