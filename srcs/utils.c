/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:19:43 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/04 20:34:41 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	set_cmds(char **av)
{
	(get_cmds())->cmd1 = ft_split(av[2], ' ');
	(get_cmds())->cmd2 = ft_split(av[3], ' ');
}

void	atoa(int proc_id2, int *fd, char **av, char **env)
{
	proc_id2 = fork();
	if (proc_id2 == -1)
	{
		strerror(errno);
		exit(errno);
	}
	else if (proc_id2 == 0)
		child_process2(fd, get_cmds()->cmd2[0], av, env);
}

void	close_files(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}
