/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:40:17 by patatoss          #+#    #+#             */
/*   Updated: 2023/11/09 09:18:27 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return ;
}

void	ft_free_all_tabs(char **tab1, char **tab2)
{
	int	i;

	i = 0;
	while (tab1[i])
		free(tab1[i++]);
	free(tab1);
	i = 0;
	while (tab2[i])
		free(tab2[i++]);
	free(tab2);
	return ;
}
