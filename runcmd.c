/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runcmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:50:03 by pruenrua          #+#    #+#             */
/*   Updated: 2023/05/26 01:46:34 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_execute(char *cmd)
{
	if (!cmd)
		return (-1);
	return (access(cmd, X_OK));
}

void	run_command(char *cmd, char **envbox, int to_input, char **ev)
{
	char	**cmd_argument;
	char	*cmdpath;

	cmd_argument = NULL;
	cmdpath = NULL;

	cmd_argument = ft_split(cmd, ' ');
	if (cmd_argument != NULL)
		cmdpath = get_cmdpath(cmd_argument[0], envbox);
	dup2(to_input, 0);
	close(to_input);
	if (-1 == execve(cmdpath, cmd_argument, ev))
		put_errorcmd(cmd_argument[0], cmdpath, cmd_argument, errno);
}
