/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 23:19:39 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/01 18:07:01 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void check_exist(char **av)
{
	int fd_file1;
	
	fd_file1 = open(av[1], O_RDONLY);
	if(fd_file1 == -1)
	{
		strerror(errno);
		exit(errno);
	}
	if(av[2][0] == '\0' || av[3][0] == '\0')
	{
		ft_putstr_fd("Command not found", 2);
		exit(127);
	}
}

char  **find_path( char **env)
{
	int i;
	int k;

	k = 0;
	i = 0;
	char **path;
	while(env[i])
	{
		if(ft_strncmp("PATH=", env[i], 4) == 0)
		{
			path = ft_split(&env[i][k + 5],':');
			return(path);
		}
		i++;
	}
	return (NULL);
}

char *path2(char **path, char *cmd)
{
	int i = 0;
	char *a;
	char *path2;

	i = 0;
	a = ft_strjoin("/", cmd);
	while(path[i] != NULL)
	{
		path2 = ft_strjoin(path[i], a);
		if(access(path2, F_OK) == 0)
		{
			free(a);
			return(path2);
		}
		free(path2);
		i++;
	}
	free(a);
	return(NULL);
}



void executer(char *cmd_name, char **cmd, char **env)
{
	int i;
	get_cmds()->path2 = find_path(env);
	get_cmds()->path_cmd = path2(get_cmds()->path2, cmd_name);
	if(access(get_cmds()->path_cmd, F_OK) != 0)
	{
		free_loop(get_cmds()->path2);
		free_loop(get_cmds()->cmd1);
		free_loop(get_cmds()->cmd2);
		ft_putstr_fd(strerror(errno), 2);
		exit(errno);
	}
	i = 0;
	while(get_cmds()->path2[i])
	{

		free(get_cmds()->path2[i]);
		i++;
	}
	execve(get_cmds()->path_cmd, cmd, env);
	//printf("EXEC NOT RUN");
}
