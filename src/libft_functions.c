/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekechedz <ekechedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:33:55 by ekechedz          #+#    #+#             */
/*   Updated: 2024/09/17 14:57:03 by ekechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
		*((unsigned char *)s + i++) = c;
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;
	int		memsize;

	memsize = nmemb * size;
	if (nmemb != 0 && memsize / nmemb != size)
		return (NULL);
	result = malloc(memsize);
	if (result != NULL)
		ft_memset(result, '\0', memsize);
	return (result);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i++] != '\0')
		;
	return (i - 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	while (*s != '\0')
		write(fd, s++, 1);
	write(fd, "\n", 1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
