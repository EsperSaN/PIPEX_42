/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:23:57 by pruenrua          #+#    #+#             */
/*   Updated: 2023/05/26 18:01:35 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_st(t_p *var)
{
	int	i;

	i = 0;
	if (!var)
		return ;
	if (var->pipe[0] > 0)
		close(var->pipe[0]);
	if (var->pipe[1] > 1)
		close(var->pipe[1]);
	free2d(var->envbox);
	if (var->in_file > 0)
		close(var->in_file);
	if (var->process_pid)
		free(var->process_pid);
}

void	free2d(char	**ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return ;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}
