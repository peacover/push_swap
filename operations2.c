/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 13:49:05 by yer-raki          #+#    #+#             */
/*   Updated: 2021/07/03 17:27:54 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_infos *info, int t)
{
	int	i;
	int	tmp;

	i = 0;
	if (info->l_a > 1)
	{
		tmp = info->s_a[0];
		while (info->l_a - 1 > i)
		{
			info->s_a[i] = info->s_a[i + 1];
			i++;
		}
		info->s_a[i] = tmp;
		if (!t)
			ft_putstr("ra\n");
	}
}

void	rotate_b(t_infos *info, int t)
{
	int	i;
	int	tmp;

	i = 0;
	if (info->l_b > 1)
	{
		tmp = info->s_b[0];
		while (info->l_b - 1 > i)
		{
			info->s_b[i] = info->s_b[i + 1];
			i++;
		}
		info->s_b[i] = tmp;
		if (!t)
			ft_putstr("rb\n");
	}
}

void	rev_rotate_a(t_infos *info, int t)
{
	int	i;
	int	tmp;

	i = info->l_a - 1;
	if (info->l_a > 1)
	{
		tmp = info->s_a[i];
		while (i > 0)
		{
			info->s_a[i] = info->s_a[i - 1];
			i--;
		}
		info->s_a[i] = tmp;
		if (!t)
			ft_putstr("rra\n");
	}
}

void	rev_rotate_b(t_infos *info, int t)
{
	int	i;
	int	tmp;

	i = info->l_b - 1;
	if (info->l_b > 1)
	{
		tmp = info->s_b[i];
		while (i > 0)
		{
			info->s_b[i] = info->s_b[i - 1];
			i--;
		}
		info->s_b[i] = tmp;
		if (!t)
			ft_putstr("rrb\n");
	}
}
