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

t_cmds *get_cmds()
{
	static t_cmds cmds;
	return(&cmds);
}

void free_loop(char **str)
{
	int i;

	i = 0;
	while(str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void free_all()
{
	free(get_cmds()->path2);
	free(get_cmds()->path_cmd);
	free_loop(get_cmds()->cmd1);
	free_loop(get_cmds()->cmd2);
}

void child_process(int *fd, char *cmd_name, char **av, char **env)
{
	int fd_file1;
	
	fd_file1 = open(av[1], O_RDONLY);
	if(fd_file1 == -1)
	{
		strerror(errno);
		exit(errno);
	}
	close(fd[0]);
	dup2(fd_file1, 0); //  the new file descriptor  is adjusted so that it now
							//refers to the same open file description as old fd.
	dup2(fd[1],1);
	close(fd[1]);
	executer(cmd_name, get_cmds()->cmd1, env);
}

void child_process2(int *fd, char *cmd_name, char **av, char **env)
{
	int fd_file2;
	
	(void)fd;
	fd_file2 = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if(fd_file2 == -1)
	{
		strerror(errno);
		exit(errno);
	}
	close(fd[1]);
	dup2(fd[0], 0); //  the new file descriptor  is adjusted so that it now
							//refers to the same open file description as old fd.
	dup2(fd_file2, 1);
	close(fd[0]);
	executer(cmd_name, get_cmds()->cmd2, env);
}

int main(int ac, char **av, char **env)  // env = da-me as environmental variables do meu pc. 
{
	if(ac == 5)
	{
		check_exist(av);
		get_cmds()->cmd1 = ft_split(av[2], ' ');
		get_cmds()->cmd2 = ft_split(av[3], ' ');
		int fd[2];
		int proc_id1;
		int proc_id2;

		proc_id2 = 0;
		if(pipe(fd) == -1)
		{
			strerror(errno);
			exit(errno);
		}
		proc_id1 = fork();
		if(proc_id1 == -1)
		{
			strerror(errno);
			exit(errno);
		}
		if(proc_id1 == 0)
		{
			child_process(fd, get_cmds()->cmd1[0], av, env);
		}
		if(proc_id1 != 0)
		{
			proc_id2 = fork();
			if(proc_id2 == -1)
			{
				strerror(errno);
				exit(errno);
			}
			if(proc_id2 == 0)
			{
				child_process2(fd,get_cmds()->cmd2[0], av, env);
			}
		}
		close(fd[0]);
		close(fd[1]);
		waitpid(proc_id1, NULL, 0);
		waitpid(proc_id2, NULL, 0);
		free_all();
	}
	else
	{
		ft_putstr_fd("Wrong number of arguments", 2);
		exit(0);
	}
	return (0);
}