/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukhart <aoukhart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:08:45 by aoukhart          #+#    #+#             */
/*   Updated: 2022/02/22 23:27:35 by aoukhart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Pipex.h"

size_t	ft_strlen(const char *s)
{
	unsigned long	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	cat = malloc (((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (!cat)
		return (NULL);
	while (j < ft_strlen(s1))
		cat[i++] = s1[j++];
	j = 0;
	while (j < ft_strlen(s2))
		cat[i++] = s2[j++];
	cat[i] = '\0';
	return (cat);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;
	size_t	i;

	i = 0;
	str = malloc(count * size);
	if (!str)
		return (NULL);
	while (i < count * size)
	{
		*(unsigned char *)(str + i) = 0;
		i++;
	}
	return (str);
}

char	*get_path(char *cmd, char *envp[])
{
	int		i;
	char	**path;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4) != 0)
		i++;
	path = ft_split(envp[i] + 5, ':');
	i = 0;
	return (check_path(cmd, path));
}
