/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukhart <aoukhart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 02:00:17 by aoukhart          #+#    #+#             */
/*   Updated: 2022/02/22 23:27:30 by aoukhart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Pipex.h"

static int	ft_word_size(char const *s, char c)
{	
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (s[i] && s[i] != c)
	{
		y++;
		i++;
	}
	return (y);
}

static int	ft_word_count(char const *s, char c)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			y++;
			i += ft_word_size(&s[i], c);
		}
		else
			i++;
	}
	return (y);
}

static char	*ft_word_copy(char const *src, char *dest, char c)
{
	int	i;

	i = 0;
	while (src[i] != c && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		n;
	int		i;

	if (!s)
		return (NULL);
	str = ft_calloc((ft_word_count(s, c) + 1), sizeof(char *));
	if (!str)
		return (NULL);
	n = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			str[n] = malloc((ft_word_size(&s[i], c) + 1) * sizeof(char));
			if (!str)
				return (ft_free(str));
			ft_word_copy(&s[i], str[n++], c);
			i += ft_word_size(&s[i], c);
		}
		else
			i++;
	}
	return (str);
}
