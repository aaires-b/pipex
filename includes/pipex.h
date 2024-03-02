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
#define PIPEX_H
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"

typedef struct t_list
{
	int ac;
	char **av;
	char **env;
	char **path;
	char *cmd1;
	char *cmd2;
	char *file1;
	char *file2;
	int cmd1_flag;
	int cmd2_flag;
} t_cmds;

void parse_cmds();
t_cmds *get_cmds();

#endif

