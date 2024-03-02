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

char  *path( char **env)
{
	int i;
	int k;

	k = 0;
	i = 0;
	char *path;
	while(env[i])
	{
		if(ft_strncmp("PATH=", env[i], 4) == 0)
		{
			path = ft_split(env[i][k + 5],':');
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
			return(path2);
		}
		free(path2);
		i++;
	}
	free(a);
	return(NULL);
}



void executer(char *cmd, char **env)
{
	char *path;
	path = path2(find_path(env), cmd);
	execve(path, cmd, env);
}
