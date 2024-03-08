/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:47:45 by jveirman          #+#    #+#             */
/*   Updated: 2023/10/25 10:47:45 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**clear_memory(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

size_t	words_counts(char const *s, char c)
{
	size_t	i;
	size_t	nb_words;

	if (!s[0])
		return (0);
	i = 0;
	nb_words = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_words++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		nb_words++;
	return (nb_words);
}

static void	next_word_set(char **next_word_ptr, size_t *next_word_len, char c)
{
	size_t	i;

	*next_word_ptr += *next_word_len;
	*next_word_len = 0;
	i = 0;
	while (**next_word_ptr && **next_word_ptr == c)
		(*next_word_ptr)++;
	while ((*next_word_ptr)[i])
	{
		if ((*next_word_ptr)[i] == c)
			return ;
		(*next_word_len)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	char	*next_word_ptr;
	size_t	next_word_len;
	size_t	i;

	if (!s)
		return (NULL);
	array = (char **)malloc(sizeof(char *) * (words_counts(s, c) + 1));
	if (!array)
		return (NULL);
	i = 0;
	next_word_ptr = (char *)s;
	next_word_len = 0;
	while (i < words_counts(s, c))
	{
		next_word_set(&next_word_ptr, &next_word_len, c);
		array[i] = (char *)malloc(sizeof(char) * (next_word_len + 1));
		if (!array[i])
			return (clear_memory(array));
		ft_strlcpy(array[i], next_word_ptr, next_word_len + 1);
		i++;
	}
	array[i] = NULL;
	return (array);
}
