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

#include "pipex.h"

t_cmds *get_cmds()
{
	static t_cmds cmds;
	return(&cmds);
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
	return (0);
}