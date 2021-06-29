/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 09:56:54 by yer-raki          #+#    #+#             */
/*   Updated: 2021/06/29 12:02:32 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_infos *info)
{
	int tmp;
	int l;
	
	tmp = 0;
	l = ft_strlen_int(info->s_a);
	if (l > 1)
	{
		tmp = info->s_a[0];
		info->s_a[0] = info->s_a[1];
		info->s_a[1] = tmp;
	}
}

void	swap_b(t_infos *info)
{
	int tmp;
	int l;
	
	tmp = 0;
	l = ft_strlen_int(info->s_b);
	if (l > 1)
	{
		tmp = info->s_b[0];
		info->s_b[0] = info->s_b[1];
		info->s_b[1] = tmp;
	}
}

void	push_a(t_infos *info)
{
	int *tmp;
	int l_b;
	int l_a;
	int i;
	
	tmp = 0;
	l_b = ft_strlen_int(info->s_b);
	l_a = ft_strlen_int(info->s_a);
	i = -1;
	if (l_b > 0)
	{
		info->s_a = ft_realloc_int(info->s_a, l_a, l_a + 1);
		while (l_a + 1 > ++i)
		{
			info->s_a[l_a + 1] = info->s_a[l_a];
			l_a--;
		}
		info->s_a[0] = info->s_b[0];
		tmp = ft_strdup_int(info->s_b);
		info->s_b = ft_realloc_int(info->s_b, l_b, l_b - 1);
		i = -1;
		while (tmp[++i])
			info->s_b[i] = tmp[i + 1];
	}
}

void	push_b(t_infos *info)
{
	int *tmp;
	int l_b;
	int l_a;
	int i;
	
	tmp = 0;
	l_b = ft_strlen_int(info->s_b);
	l_a = ft_strlen_int(info->s_a);
	i = -1;
	if (l_a > 0)
	{
		info->s_b = ft_realloc_int(info->s_b, l_b, l_b + 1);
		// while (l_b + 1 > ++i)
		while (++i < l_b)
		{
			info->s_b[l_b + 1] = info->s_b[l_b];
			l_b--;
		}
		info->s_b[0] = info->s_a[0];
		tmp = ft_strdup_int(info->s_a);
		info->s_a = ft_realloc_int(info->s_a, l_a, l_a - 1);
		i = -1;
		while (tmp[++i] && i < l_a - 1)
			info->s_a[i] = tmp[i + 1];
	}
}