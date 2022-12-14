/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcochin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 20:15:42 by mcochin           #+#    #+#             */
/*   Updated: 2022/08/31 15:26:30 by mcochin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (*s1 != *s2++)
			return (*(unsigned char *)s1 - *(unsigned char *)--s2);
		if (!*s1++)
			return (0);
		i++;
	}
	return (0);
}
