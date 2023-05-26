/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doctype.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:54:38 by pruenrua          #+#    #+#             */
/*   Updated: 2023/05/26 19:51:15 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	do_doctype(char *cutoffstr)
{
	char	*buff;
	int		fd[2];

	if (-1 == pipe(fd))
	{
		putstr_fd("PIPE ERROR", 2);
		exit(1);
	}
	while (1)
	{
		write(1, "heredoc> ", 9);

		buff = get_next_line(0);
		if (str_n_compare(buff, cutoffstr, ft_strlen(cutoffstr)))
			break ;
		write(fd[1], buff, ft_strlen(buff));
	}
	close(fd[1]);
	return (fd[0]);
}
/*
int main(int ac, char **av, char **ev)
{
	int fd;
	char *str[] = {"cat", "-e", (char*)0};

	if (str_n_compare(av[1],"doc_type", 7) && av[2])
		 fd = do_doctype(av[2]);
	else 
		dprintf(2,"error");
	dup2(fd, 0);
	execve("/bin/cat", str,ev);
	dprintf(2,"error [%s]", strerror(errno) );
}
*/


