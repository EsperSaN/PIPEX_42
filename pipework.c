/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipework.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:42:49 by pruenrua          #+#    #+#             */
/*   Updated: 2023/05/26 19:42:35 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	dup_write_pipe_to_out(int *pipe)
{
	close(pipe[0]);
	dup2(pipe[1], 1);
	close(pipe[1]);
}

int	open_in_file(char	**argv, t_p *var)
{
	int	fd;

	if (str_n_compare(argv[1], "doc_type", 7) && argv[2])
	{
		fd = do_doctype(argv[2]);
		var->count = 3;
	}
	else
		fd = open(argv[1], O_RDONLY);
	if (-1 == fd)
		p_error2_butexit1(errno, var);
	return (fd);
}

void	open_outfile_to_pipe(char *out_path, int *pipe, t_p *var)
{
	int	fd;

	fd = open(out_path, O_RDWR | O_CREAT | O_TRUNC, 0664);
	if (-1 == fd)
		p_error2_butexit1(errno, var);
	dup2(fd, 1);
	close(fd);
	close(pipe[0]);
	close(pipe[1]);
}

void	create_pipe(t_p *var)
{
	if (-1 == pipe(var->pipe))
		put_error("PIPE", errno, var);
}
