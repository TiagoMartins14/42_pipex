/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:19:54 by tiaferna          #+#    #+#             */
/*   Updated: 2023/10/29 10:28:18 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*s_dup;

	i = 0;
	while (s[i])
		i++;
	s_dup = malloc(i - n + 1);
	if (!s_dup)
		return (NULL);
	i = 0;
	while (s[n])
	{
		s_dup[i] = s[n];
		n++;
		i++;
	}
	s_dup[i] = '\0';
	return (s_dup);
}
