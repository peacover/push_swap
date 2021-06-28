/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 10:06:27 by yer-raki          #+#    #+#             */
/*   Updated: 2021/06/28 18:39:31 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen_int(int *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	*ft_strdup_int(const int *s1)
{
	int		i;
	int		l;
	int		*d;

	i = 0;
	l = ft_strlen_int((int*)s1);
	d = (int *)malloc(sizeof(int) * (l + 1));
	if (!d)
		return (NULL);
	while (l > i)
	{
		d[i] = s1[i];
		i++;
	}
	d[i] = '\0';
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