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
	char	**av;
	char	**env;
	char	**cmd1;
	char	**cmd2;
	char	*file1;
	char	*file2;
	int		fd[2];
	char	*path_cmd;
	char	**pre_path;
}	t_cmds;

t_cmds	*get_cmds(void);
void	executer(char *cmd_name, char **cmd);
void	check_exist(char **av);
void	free_loop(char **str);
void	free_all(void);
void	msg_erro(char *str);
void	atoa(int proc_id2, int status);
void	set_cmds(char **av, char **env);
void	child_process2(char *cmd_name);
void	child_process(char *cmd_name);
void	close_files(void);
void	help(char *av);
void	help2(int fd1, int fd2);

#endif
