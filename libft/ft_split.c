/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukasaw <nfukasaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:20:17 by nfukasaw          #+#    #+#             */
/*   Updated: 2022/09/11 18:36:33 by nfukasaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static size_t	count_strs(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] && s[i] != c)
				i++;
			count++;
		}
	}
	return (count);
}

static void	free_all(char **ptr, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(ptr[j]);
		j++;
	}
	free(ptr);
}

static char	**split_strs(char const *s, char c, char **ptr, size_t count)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (i < count)
	{
		while (*s && *s == c)
			s++;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		ptr[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!ptr[i])
		{
			free_all(ptr, i);
			return (NULL);
		}
		ft_strlcpy(ptr[i], s, len + 1);
		s += len;
		i++;
	}
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	count;

	if (!s)
		return (NULL);
	count = count_strs(s, c);
	ptr = (char **)malloc(sizeof(char *) * (count + 1));
	if (!ptr)
		return (NULL);
	ptr = split_strs(s, c, ptr, count);
	if (!ptr)
		return (NULL);
	ptr[count] = NULL;
	return (ptr);
}
