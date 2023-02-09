/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 04:53:05 by isbarka           #+#    #+#             */
/*   Updated: 2023/02/03 15:02:57 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**str_count(char **str, const char *s, char c)
{
	int	i ;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			i++;
			s++;
		}
		while (*s && *s != c)
		s++;
		while (*s && *s == c)
		{
			s++;
		}
	}
	str = malloc((i + 1) * sizeof(char *));
	if (!str)
	{
		free(str);
		return (0);
	}
	str[i] = 0;
	return (str);
}

static int	word_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}


void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*my_dest;
	unsigned char	*my_src;
	size_t			i;

	if (n < 0)
		n = ft_strlen(src);
	my_dest = (unsigned char *)dest;
	my_src = (unsigned char *)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		my_dest[i] = my_src[i];
		i++;
	}
	return (dest);
}


static char	*ft_word(const char *s, char c)
{
	char	*str;
	int		len;

	len = word_len(s, c);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
	{
		free(str);
		return (0);
	}
	ft_memcpy(str, s, len);
	str[len] = '\0';
	str = ft_strjoin(str, "/");
	return (str);
}

static char	**ft_free_all(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (0);
}

char	**ft_split(const char *s, char c)
{
	char	**str;
	int		i;

	if (!s)
		return (0);
	str = NULL;
	str = str_count(str, s, c);
	if (!str)
		return (0);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			str[i] = ft_word(s, c);
			if (!str[i])
				return (ft_free_all(str));
			i++;
		}
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	return (str);
}
