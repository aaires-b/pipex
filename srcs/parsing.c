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

void	check_exist(char **av)
{
	int	fd_file1;
	int	fd_file2;

	fd_file1 = open(av[1], O_RDONLY);
	fd_file2 = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd_file1 == -1 && fd_file2 == -1)
	{
		ft_putstr_fd("No such file or directory: ", 2);
		help(av[4]);
		exit(127);
	}
	if (av[2][0] == '\0' || av[3][0] == '\0')
	{
		ft_putstr_fd("Command not found: ", 2);
		help(av[2]);
		help(av[3]);
		help2(fd_file1, fd_file2);
		exit(127);
	}
	help2(fd_file1, fd_file2);
}

char	**find_path(void)
{
	int		i;
	int		k;
	char	**path;

	k = 0;
	i = 0;
	while (get_cmds()->env[i])
	{
		if (ft_strncmp("PATH=", get_cmds()->env[i], 4) == 0)
		{
			path = ft_split(&get_cmds()->env[i][k + 5], ':');
			return (path);
		}
		i++;
	}
	return (NULL);
}

int	check_path(char **path, char *cmd)
{
	int	i;

	i = 0;
	while (path[i])
	{
		if (!access(cmd, F_OK))
			return (1);
		i++;
	}
	return (0);
}

char	*path2(char **path, char *cmd)
{
	int		i;
	char	*a;
	char	*path2;

	i = 0;
	if (check_path(path, cmd) == 1)
		return (cmd);
	a = ft_strjoin("/", cmd);
	while (path[i] != NULL)
	{
		path2 = ft_strjoin(path[i], a);
		if (access(path2, F_OK) == 0)
		{
			free(a);
			return (path2);
		}
		free(path2);
		i++;
	}
	free(a);
	return (NULL);
}

void	executer(char *cmd_name, char **cmd)
{
	int	i;

	i = 0;
	(get_cmds())->pre_path = find_path();
	(get_cmds())->path_cmd = path2(get_cmds()->pre_path, cmd_name);
	if (!(get_cmds()->path_cmd) || access(get_cmds()->path_cmd, F_OK) != 0)
	{
		ft_putstr_fd("Command not found: ", 2);
		help(cmd_name);
		free_loop(get_cmds()->pre_path);
		free_loop(get_cmds()->cmd1);
		free_loop(get_cmds()->cmd2);
		exit(127);
	}
	i = 0;
	while (get_cmds()->pre_path[i])
	{
		free(get_cmds()->pre_path[i]);
		i++;
	}
	execve(get_cmds()->path_cmd, cmd, get_cmds()->env);
}
