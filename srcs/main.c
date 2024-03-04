/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:45:12 by aaires-b          #+#    #+#             */
/*   Updated: 2024/02/18 12:28:27 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

//dup2() :
// refers to the same open file description as old fd.
//  the new file descriptor  is adjusted so that it now
// env = da-me as environmental variables do meu pc. 

t_cmds	*get_cmds(void)
{
	static t_cmds	cmds;

	return (&cmds);
}

void	child_process(int *fd, char *cmd_name, char **av, char **env)
{
	int	fd_file1;

	fd_file1 = open(av[1], O_RDONLY);
	if (fd_file1 == -1)
	{
		strerror(errno);
		exit(errno);
	}
	close(fd[0]);
	dup2(fd_file1, 0);
	dup2(fd[1], 1);
	close(fd[1]);
	executer(cmd_name, get_cmds()->cmd1, env);
}

void	child_process2(int *fd, char *cmd_name, char **av, char **env)
{
	int	fd_file2;

	fd_file2 = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd_file2 == -1)
	{
		strerror(errno);
		exit(errno);
	}
	close(fd[1]);
	dup2(fd[0], 0);
	dup2(fd_file2, 1);
	close(fd[0]);
	executer(cmd_name, get_cmds()->cmd2, env);
}

int	main(int ac, char **av, char **env)
{
	int	fd[2];
	int	proc_id1;
	int	proc_id2;

	proc_id2 = 0;
	if (ac != 5)
		msg_erro("Wrong number of arguments");
	check_exist(av);
	set_cmds(av);
	if (pipe(fd) == -1)
		msg_erro("Pipe didn't create");
	proc_id1 = fork();
	if (proc_id1 == -1)
		msg_erro("Process didn't create");
	if (proc_id1 == 0)
		child_process(fd, get_cmds()->cmd1[0], av, env);
	if (proc_id1 != 0)
		atoa(proc_id2, fd, av, env);
	close_files(fd);
	waitpid(proc_id1, NULL, 0);
	waitpid(proc_id2, NULL, 0);
	free_all();
	return (0);
}
