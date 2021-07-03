/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 10:06:27 by yer-raki          #+#    #+#             */
/*   Updated: 2021/07/03 20:37:34 by yer-raki         ###   ########.fr       */
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
		return ((int *)s1);
	d = (int *)malloc(sizeof(int) * (l));
	if (!d)
		return (NULL);
	while (l > i)
	{
		d[i] = s1[i];
		i++;
	}
	return (d);
}

void	*ft_memcpy_int(void *dst, const void *src, size_t n)
{
	int		*d;
	int		*s;
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
	new = (int *)malloc(new_size * sizeof(int));
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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1)
		return (s2[i]);
	else if (!s2)
		return (s1[i]);
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	check_args(int argc, char **argv)
{
	int		i;
	int		j;
	char	*tmp;
	char	*tmp2;

	i = 1;
	j = 0;
	tmp = NULL;
	tmp2 = NULL;
	while (argc > i)
	{
		j = 0;
		while (ft_strlen(argv[i]) > 1 && argv[i][j] == '0')
			j++;
		tmp = ft_substr(argv[i], j, ft_strlen((argv[i]) - j));
		tmp2 = ft_itoa(ft_atoi(tmp));
		if (ft_strcmp(tmp, tmp2) || (j != 0 && argv[i][j] == '-'))
			error_msg();
		i++;
		free(tmp);
		free(tmp2);
		tmp = NULL;
		tmp2 = NULL;
	}
}
