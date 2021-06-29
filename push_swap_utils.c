/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 10:06:27 by yer-raki          #+#    #+#             */
/*   Updated: 2021/06/29 17:24:06 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	*ft_strdup_int(const int *s1, int len)
{
	int		i;
	int		l;
	int		*d;

	i = 0;
	l = len;
	if (len < 1)
		return ((int*)s1);
	d = (int *)malloc(sizeof(int) * (l));
	if (!d)
		return (NULL);
	while (l > i)
	{
		d[i] = s1[i];
		i++;
	}
	// d[i] = '\0';
	return (d);
}


int		ft_strlen2(char **w)
{
	int i;

	i = 0;
	if (!w)
		return (0);
	while (w[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	*ft_memcpy_int(void *dst, const void *src, size_t n)
{
	int	*d;
	int	*s;
	size_t	i;

	i = 0;
	d = (int *)dst;
	s = (int *)src;
	if (d == NULL && s == NULL)
		return (NULL);
	while (n > i)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

void	*ft_realloc_int(void *ptr, size_t old_size, size_t new_size)
{
	void	*new;
	
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new = (int*)malloc(new_size * sizeof(int));
	if (!new)
		return (NULL);
	if (ptr != NULL || !old_size)
	{
		if (old_size >= new_size)
			ft_memcpy_int(new, ptr, new_size);
		else
			ft_memcpy_int(new, ptr, old_size);
		free(ptr);
	}
	return (new);
}