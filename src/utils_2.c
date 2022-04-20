/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukhart <aoukhart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:37:35 by aoukhart          #+#    #+#             */
/*   Updated: 2022/02/23 00:13:33 by aoukhart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Pipex.h"

void	execute_1(int pipe[], int fd, char **cmd, char **envp)
{
	char	*path;

	close(pipe[0]);
	dup2(pipe[1], STDOUT_FILENO);
	dup2(fd, STDIN_FILENO);
	path = get_path(cmd[0], envp);
	execve(path, cmd, envp);
	perror("SOMETHING WENT WRONG !!");
	exit(127);
}

void	execute_2(int pipe[], int fd, char **cmd, char **envp)
{
	char	*path;

	close(pipe[1]);
	dup2(pipe[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	path = get_path(cmd[0], envp);
	execve(path, cmd, envp);
	perror("SOMETHING WRONG !!");
	exit(127);
}

char	*check_path(char *cmd, char **path)
{
	int		i;
	char	*new_cmd;
	char	*new_path;

	i = 0;
	while (path[i++])
	{
		new_cmd = ft_strjoin("/", cmd);
		new_path = ft_strjoin(path[i], new_cmd);
		free(new_cmd);
		if (access(new_path, F_OK) == 0)
		{
			ft_free(path);
			return (new_path);
		}
		free(new_path);
	}
	free(path);
	perror("ERROR (CMD)");
	exit(127);
	return (NULL);
}

void	free_all(char **str1, char *str2)
{
	int	i;

	i = -1;
	while (str1[++i])
		free(str1[i]);
	free(str1);
	free(str2);
}
