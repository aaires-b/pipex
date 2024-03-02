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

void parse_cmds()
{
	int fd1;
	t_cmds *cmds;
	int i;
	int k;

	k = 0;
	i = 0;
	cmds = get_cmds();
	//printf("ac : %d\n", cmds->ac);
	//printf("av : %s\n", cmds->av[1]);
	//printf("env : %s\n", cmds->env[1]);
	if(cmds->ac != 5)
		exit(1);
	fd1 = open(cmds->file1, O_RDONLY, 0777);
	// fd2 = open(cmds->file2, O_RDONLY);
	if(fd1 == -1)
		exit(1);
	if(fd1 != -1)
		close(fd1);
	while(cmds->env[i])
	{
		if(ft_strncmp("PATH=", cmds->env[i], 4) == 0)
			cmds->path = ft_split(&cmds->env[i][k + 5],':');
		i++;
	}
	i = 0;
	while(cmds->path[i] != NULL)
	{
		char *a = ft_strjoin(cmds->path[i], cmds->cmd1);
		if(access(a, F_OK) == 0)
		{
			cmds->path_cmd1 = a;
			cmds->cmd1_flag = 1;
			break ; 
		}
		free(a);
		i++;
	}
	i = 0;
	while(cmds->path[i] != NULL)
	{
		char *b = ft_strjoin(cmds->path[i], cmds->cmd2);
		if(access(b, F_OK) == 0)
		{
			cmds->cmd2_flag = 1;
			cmds->path_cmd2 = b;
			break ;
		}
		free(b);
		i++;
	}
	if(cmds->cmd1_flag == 0 || cmds->cmd2_flag == 0)
	{
		printf("erro\n");
		exit(1);
		//falta free dos paths
	}


}
// 	i = 0;
// 	while(cmds->path[i])
// 	{
// 		printf(" env cortado : %s", cmds->path[i]);
// 		i++;
// 	}