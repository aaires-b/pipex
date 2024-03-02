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

void child_process(int *fd)
{
	t_cmds *cmds = get_cmds();

	cmds->fd_file1 = open(cmds->file1, O_RDONLY, 0777);
	if(cmds->fd_file1 == -1)
	{
		strerror(errno);
		exit(1);
	}
	dup2(cmds->fd_file1, 0); //  the new file descriptor  is adjusted so that it now
       						//refers to the same open file description as old fd.
	dup2(fd[1], 1);
	close(fd[0]);
	execve(cmds->path_cmd1, &cmds->av[2], cmds->env);
}
void parent_process(int *fd)
{
	t_cmds *cmds = get_cmds();

	cmds->fd_file2 = open(cmds->file2, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if(cmds->fd_file2 == -1)
	{
		strerror(errno);
		exit(1);
	}
	dup2(fd[0], 0); //  the new file descriptor  is adjusted so that it now
							//refers to the same open file description as old fd.
	dup2(cmds->fd_file2, 1);
	close(fd[1]);
	execve(cmds->path_cmd2, &cmds->av[3], cmds->env);
	//printf("aqui\n");
}

void start()
{
	// t_cmds *cmds = get_cmds();

	// cmds->n1_stdin = open(cmds->file1, O_RDONLY, 007);
	// cmds->n2_stdout = open(cmds->file2, O_CREATE)
	int fd[2];
	pid_t proc_id; // signed integer , represent a process ID.
	
	//Pipes provide a way for one process to send data to another process. 
	//create a unidirectional communication channel. returns -1 for error fd[1] = writes , fd[0] = reads
	//returns two file descriptors: one for the read end of the pipe and one for the write end.
	if(pipe(fd) == -1)
	{
		strerror(errno);//perror : print an error message to stderr based on the error state stored in errno
		//errno is a global variable indicating the error occurred during any function call
		// strerror : returns a pointer to the textual representation of the current errno value.
		exit(1);
	}
	// create new process(cpy of parent). The child process inherits the file descriptors of the parent process, including those of the pipe.
	proc_id = fork();
	if(proc_id == -1)
	{
		strerror(errno);
		exit(1);
	}
	if(proc_id == 0) // im in the new process (child) 
	{
		child_process(fd);
	}
	waitpid(proc_id, NULL, 0);
	parent_process(fd);
	
 	// If pid is equal to zero, waitpid() waits for termination of any child whose process group ID is equal to that of the caller.
	// makes the parent process wait for the child process to be terminated by default
	// The status_ptr pointer NULL =  waitpid() ignores the child's return status.
	// options 0 = Specifies additional information for waitpid() , 0 means to block and wait until the specified child process terminates. 
}

void set_cmds(int ac,char **av, char **env)
{
	t_cmds *cmds = get_cmds();
	cmds->ac = ac;
	cmds->av = av;
	cmds->cmd1_flag = 0;
	cmds->cmd2_flag = 0;
	cmds->env = env;
	cmds->file1 = av[1];
	cmds->file2 = av[4];
	cmds->cmd1 = ft_strjoin("/", av[2]);
	cmds->cmd2 = ft_strjoin("/", av[3]);
	
}

int main(int ac,char **av, char **env)  // env = da-me as environmental variables do meu pc. 
{
	set_cmds(ac, av, env);
	parse_cmds();
	start();

	return (0);
}