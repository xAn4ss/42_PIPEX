/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukhart <aoukhart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:00:07 by aoukhart          #+#    #+#             */
/*   Updated: 2022/02/23 00:42:44 by aoukhart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Pipex.h" 

void	exec_cmd1(int fd[], char **argv, char **envp)
{
	int		input_fd;
	char	**cmd;
	char	*path;
	int		i;

	i = -1;
	input_fd = open(argv[1], O_RDONLY, 0644);
	if (input_fd == -1)
	{
		perror("infile");
		exit(1);
	}
	cmd = ft_split(argv[2], ' ');
	path = get_path(cmd[0], envp);
	if (!path)
		ft_free(cmd);
	i = fork();
	if (i == -1)
	{
		perror("SOMETHING WENT WRONG !!");
		exit(127);
	}
	if (i == 0)
		execute_1(fd, input_fd, cmd, envp);
	free_all(cmd, path);
}

void	exec_cmd2(int fd[], char **argv, char **envp)
{
	int		output_fd;
	char	**cmd;
	char	*path;
	int		i;

	i = -1;
	output_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_fd == -1)
	{
		perror("SOMETHING WENT WRONG !!");
		exit(1);
	}
	cmd = ft_split(argv[3], ' ');
	path = get_path(cmd[0], envp);
	if (!path)
		ft_free(cmd);
	i = fork();
	if (i == -1)
	{
		perror("SOMWTHING WENT WRONG !!");
		exit(127);
	}
	if (i == 0)
		execute_2(fd, output_fd, cmd, envp);
	free_all(cmd, path);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];

	if (argc == 5)
	{
		if (pipe(fd) != 0)
		{
			perror("SOMETHING WENT WRONG !!");
			exit(EXIT_FAILURE);
		}
		exec_cmd1(fd, argv, envp);
		exec_cmd2(fd, argv, envp);
		close (fd[0]);
		close (fd[1]);
	}
	else
	{
		write(2, "CHECK NUMBER OF ARGUMENTS !!", 28);
		exit(EXIT_FAILURE);
	}
	return (0);
}
