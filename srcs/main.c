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

void	child_process(char *cmd_name)
{
	int	fd_file1;

	fd_file1 = open(get_cmds()->av[1], O_RDONLY);
	if (fd_file1 == -1)
	{
		free_loop(get_cmds()->cmd1);
		free_loop(get_cmds()->cmd2);
		ft_putstr_fd("No such file or directory: ", 2);
		help(get_cmds()->av[1]);
		close_files();
		exit(127);
	}
	close(get_cmds()->fd[0]);
	dup2(fd_file1, 0);
	dup2(get_cmds()->fd[1], 1);
	close(get_cmds()->fd[1]);
	close(fd_file1);
	executer(cmd_name, get_cmds()->cmd1);
}

void	child_process2(char *cmd_name)
{
	int	fd_file2;

	fd_file2 = open(get_cmds()->av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd_file2 == -1)
	{
		free_loop(get_cmds()->cmd1);
		free_loop(get_cmds()->cmd2);
		ft_putstr_fd("No such file or directory: ", 2);
		close_files();
		help(get_cmds()->av[4]);
		exit(127);
	}
	close(get_cmds()->fd[1]);
	dup2(get_cmds()->fd[0], 0);
	dup2(fd_file2, 1);
	close(fd_file2);
	close(get_cmds()->fd[0]);
	executer(cmd_name, get_cmds()->cmd2);
}

int	main(int ac, char **av, char **env)
{
	int	proc_id1;
	int	proc_id2;
	int	stat;

	stat = 0;
	proc_id2 = 0;
	if (ac != 5)
		msg_erro("Wrong number of arguments\n");
	check_exist(av);
	if (pipe(get_cmds()->fd) == -1)
		msg_erro("Error creating pipe\n");
	proc_id1 = fork();
	if (proc_id1 == -1)
		msg_erro("Error creating process\n");
	set_cmds(av, env);
	if (proc_id1 == 0)
		child_process(get_cmds()->cmd1[0]);
	if (proc_id1 != 0)
		atoa(proc_id2, stat);
	close_files();
	waitpid(proc_id1, &stat, 0);
	waitpid(proc_id2, &stat, 0);
	stat = WEXITSTATUS(stat);
	free_all();
	return (stat);
}
