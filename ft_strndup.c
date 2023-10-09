/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:52:27 by tiaferna          #+#    #+#             */
/*   Updated: 2023/10/09 17:25:34 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strndup(const char *s, size_t	n)
{
	char	*s_dup;
	int		i;

	s_dup = malloc(n + 1);
	if (!s_dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		s_dup[n] = s[i];
		n++;
		i++;
	}
	s_dup[n] = '\0';
	return (s_dup);
}
