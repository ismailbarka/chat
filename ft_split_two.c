/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 04:53:05 by isbarka           #+#    #+#             */
/*   Updated: 2023/02/03 15:15:15 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**str_count_two(char **str, const char *s, char c)
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

static int	word_len_two(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlen_two(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}


void	*ft_memcpy_two(void *dest, const void *src, size_t n)
{
	unsigned char	*my_dest;
	unsigned char	*my_src;
	size_t			i;

	if (n < 0)
		n = ft_strlen_two(src);
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


static char	*ft_word_two(const char *s, char c)
{
	char	*str;
	int		len;

	len = word_len_two(s, c);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
	{
		free(str);
		return (0);
	}
	ft_memcpy_two(str, s, len);
	str[len] = '\0';
	return (str);
}

static char	**ft_free_all_two(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (0);
}

char	**ft_split_two(const char *s, char c)
{
	char	**str;
	int		i;

	if (!s)
		return (0);
	str = NULL;
	str = str_count_two(str, s, c);
	if (!str)
		return (0);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			str[i] = ft_word_two(s, c);
			if (!str[i])
				return (ft_free_all_two(str));
			i++;
		}
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	return (str);
}