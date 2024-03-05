/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:00:34 by aaires-b          #+#    #+#             */
/*   Updated: 2024/03/05 14:57:26 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_loop(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_all(void)
{
	free(get_cmds()->pre_path);
	free(get_cmds()->path_cmd);
	free_loop(get_cmds()->cmd1);
	free_loop(get_cmds()->cmd2);
}

void	msg_erro(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}
