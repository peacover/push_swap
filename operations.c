/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 09:56:54 by yer-raki          #+#    #+#             */
/*   Updated: 2021/06/29 18:27:53 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_infos *info)
{
	int tmp;
	
	tmp = 0;
	if (info->l_a > 1)
	{
		tmp = info->s_a[0];
		info->s_a[0] = info->s_a[1];
		info->s_a[1] = tmp;
	}
}

void	swap_b(t_infos *info)
{
	int tmp;
	
	tmp = 0;
	if (info->l_b > 1)
	{
		tmp = info->s_b[0];
		info->s_b[0] = info->s_b[1];
		info->s_b[1] = tmp;
	}
}

void	push_a(t_infos *info)
{
	int *tmp;
	int i;
	
	tmp = 0;
	i = info->l_a;
	if (info->l_b > 0)
	{
		tmp = ft_strdup_int(info->s_a, info->l_a);
		info->s_a = ft_realloc_int(info->s_a, info->l_a, info->l_a + 1);
		while (i > 0 && info->l_a > 0)
		{
			info->s_a[i] = tmp[i - 1];
			i--;
		}
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
	}
}

void	push_b(t_infos *info)
{
	int *tmp;
	int i;
	
	tmp = 0;
	i = info->l_b;
	if (info->l_a > 0)
	{
		tmp = ft_strdup_int(info->s_b, info->l_b);
		info->s_b = ft_realloc_int(info->s_b, info->l_b, info->l_b + 1);
		while (i > 0 && info->l_b > 0)
		{
			info->s_b[i] = tmp[i - 1];
			i--;
		}
		info->s_b[0] = info->s_a[0];
		free(tmp);
		tmp = ft_strdup_int(info->s_a, info->l_a);
		info->s_a = ft_realloc_int(info->s_a, info->l_a, info->l_a - 1);
		i = -1;
		while (info->l_a - 1> ++i)
			info->s_a[i] = tmp[i + 1];
		info->l_a--;
		info->l_b++;
		free(tmp);
	}
}

void	rotate_a(t_infos *info)
{
	int i;
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
	}
}

void	rotate_b(t_infos *info)
{
	int i;
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
	}
}

void	rev_rotate_a(t_infos *info)
{
	int i;
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
	}
}

void	rev_rotate_b(t_infos *info)
{
	int i;
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
	}
}