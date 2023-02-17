/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukasaw <nfukasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:36:36 by nfukasaw          #+#    #+#             */
/*   Updated: 2022/09/04 23:16:20 by nfukasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*constr;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	constr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!constr)
		return (NULL);
	ft_strlcpy(constr, s1, s1_len + 1);
	ft_strlcat(constr, s2, s1_len + s2_len + 1);
	return (constr);
}
