/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 14:35:27 by yer-raki          #+#    #+#             */
/*   Updated: 2021/07/03 17:30:37 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(int *s, int len)
{
	int	i;
	int	ret;

	i = 0;
	ret = s[0];
	while (len > i)
	{
		if (s[i] > ret)
			ret = s[i];
		i++;
	}
	return (ret);
}

int	get_min(int *s, int len)
{
	int	i;
	int	ret;

	i = 0;
	ret = s[0];
	while (len > i)
	{
		if (s[i] < ret)
			ret = s[i];
		i++;
	}
	return (ret);
}

int	get_pos(int *s, int val, int len)
{
	int	i;

	i = 0;
	while (len > i)
	{
		if (s[i] == val)
			return (i);
		i++;
	}
	return (0);
}

int	up_or_down(int pos, int len)
{
	if (len / 2 > pos + 1)
		return (1);
	return (0);
}

void	index_my_array(t_infos *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (info->l_a > i)
	{
		j = 0;
		while (info->l_a > j)
		{
			if (info->s_a[i] == info->sorted_a[j])
			{
				info->s_a[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}
