/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:19:43 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/05 19:08:07 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	help(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}

void	help2(int fd1, int fd2)
{
	if (fd1 > 0)
		close(fd1);
	if (fd2 > 0)
		close(fd2);
}

void	set_cmds(char **av, char **env)
{
	(get_cmds())->cmd1 = ft_split(av[2], ' ');
	(get_cmds())->cmd2 = ft_split(av[3], ' ');
	(get_cmds())->av = av;
	(get_cmds())->env = env;
	(get_cmds())->file1 = av[1];
	(get_cmds())->file2 = av[4];
	(get_cmds())->path_cmd = NULL;
	(get_cmds())->pre_path = NULL;
}

void	atoa(int proc_id2, int status)
{
	if (status != 0)
		exit(EXIT_FAILURE);
	proc_id2 = fork();
	if (proc_id2 == -1)
		msg_erro("Error creating process\n");
	else if (proc_id2 == 0)
		child_process2(get_cmds()->cmd2[0]);
}

void	close_files(void)
{
	if (get_cmds()->fd[0] > 0)
		close(get_cmds()->fd[0]);
	if (get_cmds()->fd[1] > 0)
		close(get_cmds()->fd[1]);
}
