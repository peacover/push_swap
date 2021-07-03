/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 09:56:54 by yer-raki          #+#    #+#             */
/*   Updated: 2021/07/03 17:27:02 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_infos *info, int t)
{
	int	tmp;

	tmp = 0;
	if (info->l_a > 1)
	{
		tmp = info->s_a[0];
		info->s_a[0] = info->s_a[1];
		info->s_a[1] = tmp;
		if (!t)
			ft_putstr("sa\n");
	}
}

void	swap_b(t_infos *info, int t)
{
	int	tmp;

	tmp = 0;
	if (info->l_b > 1)
	{
		tmp = info->s_b[0];
		info->s_b[0] = info->s_b[1];
		info->s_b[1] = tmp;
		if (!t)
			ft_putstr("sb\n");
	}
}

void	push_a(t_infos *info, int t)
{
	int	*tmp;
	int	i;

	tmp = 0;
	i = info->l_a + 1;
	if (info->l_b > 0)
	{
		tmp = ft_strdup_int(info->s_a, info->l_a);
		info->s_a = ft_realloc_int(info->s_a, info->l_a, info->l_a + 1);
		while (--i > 0 && info->l_a > 0)
			info->s_a[i] = tmp[i - 1];
		info->s_a[0] = info->s_b[0];
		free(tmp);
		tmp = ft_strdup_int(info->s_b, info->l_b);
		info->s_b = ft_realloc_int(info->s_b, info->l_b, info->l_b - 1);
		i = -1;
		while (info->l_b - 1 > ++i)
			info->s_b[i] = tmp[i + 1];
		info->l_a++;
		info->l_b--;
		free(tmp);
		if (!t)
			ft_putstr("pa\n");
	}
}

void	push_b(t_infos *info, int t)
{
	int	*tmp;
	int	i;

	tmp = 0;
	i = info->l_b + 1;
	if (info->l_a > 0)
	{
		tmp = ft_strdup_int(info->s_b, info->l_b);
		info->s_b = ft_realloc_int(info->s_b, info->l_b, info->l_b + 1);
		while (--i > 0 && info->l_b > 0)
			info->s_b[i] = tmp[i - 1];
		info->s_b[0] = info->s_a[0];
		free(tmp);
		tmp = ft_strdup_int(info->s_a, info->l_a);
		info->s_a = ft_realloc_int(info->s_a, info->l_a, info->l_a - 1);
		i = -1;
		while (info->l_a - 1 > ++i)
			info->s_a[i] = tmp[i + 1];
		info->l_a--;
		info->l_b++;
		free(tmp);
		if (!t)
			ft_putstr("pb\n");
	}
}
