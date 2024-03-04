/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 23:20:16 by aaires-b          #+#    #+#             */
/*   Updated: 2024/02/18 12:27:54 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# include <stdarg.h>

typedef struct t_list
{
	int		ac;
	char	**av;
	char	**env;
	char	**cmd1;
	char	**cmd2;
	char	*file1;
	char	*file2;
	int		cmd1_flag;
	int		cmd2_flag;
	int		flag_1;
	int		fd_file1;
	int		fd_file2; 
	char	*path_cmd;
	char	**path2;
}	t_cmds;

t_cmds	*get_cmds(void);
void	executer(char *cmd_name, char **cmd, char **env);
void	check_exist(char **av);
void	free_loop(char **str);
void	free_all(void);
void	msg_erro(char *str);
void	atoa(int proc_id2, int *fd, char **av, char **env);
void	set_cmds(char **av);
void	child_process2(int *fd, char *cmd_name, char **av, char **env);
void	child_process(int *fd, char *cmd_name, char **av, char **env);
void	close_files(int *fd);

#endif