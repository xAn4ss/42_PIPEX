/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukhart <aoukhart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:00:39 by aoukhart          #+#    #+#             */
/*   Updated: 2022/02/22 22:16:48 by aoukhart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char		*get_path(char *cmd, char *envp[]);
void		exec_cmd1(int fd[], char **argv, char **envp);
void		exec_cmd2(int fd[], char **argv, char **envp);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		**ft_split(char const *s, char c);
void		*ft_calloc(size_t count, size_t size);
char		**ft_free(char **str);
char		*check_path(char *cmd, char **path);
void		execute_1(int pipe[], int fd, char **cmd, char **envp);
void		execute_2(int pipe[], int fd, char **cmd, char **envp);
void		free_all(char **str1, char *str2);

#endif