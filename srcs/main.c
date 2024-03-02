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

void erro(int errno)
{
	strerror(errno);
	exit(1);
}
void child_process(int *fd, char **av, char **env)
{
	int fd_file1;
	
	fd_file1 = open(av[1], O_RDONLY, 0777);
	if(fd_file1 == -1)
		erro(errno);
	dup2(fd_file1, 0); //  the new file descriptor  is adjusted so that it now
							//refers to the same open file description as old fd.
	dup2(fd[1],1);
	close(fd[1]);
	close(fd[0]);
	executer(av[2], env);
	//printf("aqui\n");
}

void child_process2(int *fd, char **av, char **env)
{
	int fd_file2;
	
	fd_file2 = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if(fd_file2 == -1)
		erro(errno);
	dup2(fd[1], 0); //  the new file descriptor  is adjusted so that it now
							//refers to the same open file description as old fd.
	dup2(fd_file2, 1);
	close(fd[1]);
	close(fd[0]);
	executer(av[3], env);
	//printf("aqui\n");
}

int main(int ac,char **av, char **env)  // env = da-me as environmental variables do meu pc. 
{
	if(ac == 5)
	{
		int fd[2];
		int proc_id1;

		if(pipe(fd) == -1)
			erro(errno);
		proc_id1 = fork();
		if(proc_id1 == -1)
			erro(errno);
		if(proc_id1 == 0)
			child_process(fd, av, env);
		int proc_id2 = fork();
		if(proc_id2 == -1)
			erro(errno);
		if(proc_id2 == 0)
			child_process2(fd, av, env);
		waitpid(proc_id1, NULL, 0);
		waitpid(proc_id2, NULL, 0);
	}
	else
	{
		////mensagem de erro
	 	exit(1);
	}
	return (0);
}