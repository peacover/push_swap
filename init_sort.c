/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 17:13:08 by yer-raki          #+#    #+#             */
/*   Updated: 2021/07/03 17:24:03 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_infos(t_infos *info)
{
	info->s_a = NULL;
	info->s_b = NULL;
	info->sorted_a = NULL;
	info->l_a = 0;
	info->l_b = 0;
}

int	check_if_sorted(int *s, int len)
{
	int	i;

	i = 0;
	if (len == 0 || len == 1)
		return (1);
	while (len > i)
	{
		if (i == len - 1)
			return (1);
		if (s[i] > s[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	*ft_sort(int *s, int len)
{
	int	i;
	int	j;
	int	*ret;
	int	tmp;

	i = 0;
	j = 0;
	ret = ft_strdup_int(s, len);
	while (len > i)
	{
		j = i + 1;
		while (len > j)
		{
			if (ret[i] > ret[j])
			{
				tmp = ret[i];
				ret[i] = ret[j];
				ret[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (ret);
}

void	sort_check_double(t_infos *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	info->sorted_a = ft_sort(info->s_a, info->l_a);
	while (info->l_a > i)
	{
		j = i + 1;
		while (info->l_a > j)
		{
			if (info->s_a[i] == info->s_a[j])
				error_msg();
			j++;
		}
		i++;
	}
}

void	fill_stack_a(t_infos *info, int argc, char **argv)
{
	int	i;

	i = 0;
	info->s_a = (int *)malloc((argc) * sizeof(int));
	info->l_a = argc - 1;
	while (argc - 1 > i)
	{
		info->s_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
}
