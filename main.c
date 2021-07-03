/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 10:06:21 by yer-raki          #+#    #+#             */
/*   Updated: 2021/07/03 10:41:28 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	print_my_int_array(int *s, int len)
{
	int i;

	i = 0;
	printf("\n\n------------------------------------\n\n");
	while (len > i)
    {
		printf("s[%d] : %d\n",i, s[i]);
		i++;
	}
	printf("\n\n------------------------------------");
}

int	get_max(int *s, int len)
{
	int i;
	int ret;

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
	int i;
	int ret;

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
void	sort_three_nb_a(t_infos *info)
{
	int i;
	int	min;
	int max;
	
	i = 0;
	min = get_min(info->s_a, info->l_a);
	max = get_max(info->s_a, info->l_a);
	if (check_if_sorted(info->s_a, info->l_a) == 1)
		return;
	if (info->s_a[0] == max)
		rotate_a(info, 0);
	if (check_if_sorted(info->s_a, info->l_a) == 1)
		return;
	if (info->s_a[2] == min)
		rev_rotate_a(info, 0);
	if (check_if_sorted(info->s_a, info->l_a) == 1)
		return;
	if (info->s_a[1] > info->s_a[2])
		rev_rotate_a(info, 0);
	if (check_if_sorted(info->s_a, info->l_a) == 1)
		return;
	if (info->s_a[0] > info->s_a[1])
		swap_a(info, 0);
}

int	get_pos(int *s, int val, int len)
{
	int i;

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

void	sort_five_nb_a(t_infos *info)
{
	int i;
	int	min;
	int pos;
	
	i = 0;
	min = get_min(info->s_a, info->l_a);
	if (check_if_sorted(info->s_a, info->l_a) == 1)
		return;
	pos = get_pos(info->s_a, min, info->l_a);
	if (pos == 0)
	{
		push_b(info, 0);
		min = get_min(info->s_a, info->l_a);
		pos = get_pos(info->s_a, min, info->l_a);
	}
	else if (pos == info->l_a - 1)
	{
		rev_rotate_a(info, 0);
		if (check_if_sorted(info->s_a, info->l_a) == 1)
			return;
		push_b(info, 0);
		min = get_min(info->s_a, info->l_a);
		pos = get_pos(info->s_a, min, info->l_a);
	}
	if (!up_or_down(pos, info->l_a))
	{
		while (pos > 0)
		{
			rotate_a(info, 0);
			pos--;
		}// return 1 > down | 0 > up
	}
	else
	{
		while (pos < (info->l_a))
		{
			rev_rotate_a(info, 0);
			pos++;
		}
	}
	push_b(info, 0);
	min = get_min(info->s_a, info->l_a);
	pos = get_pos(info->s_a, min, info->l_a);
	if (info->l_a > 3 && pos == 0)
		push_b(info, 0);
	else if (info->l_a > 3 && pos == info->l_a - 1)
	{
		rev_rotate_a(info, 0);
		push_b(info, 0);
	}
	min = get_min(info->s_a, info->l_a);
	pos = get_pos(info->s_a, min, info->l_a);
	if (info->l_a > 3 && !up_or_down(pos, info->l_a))
	{
		while (pos > 0)
		{
			rotate_a(info, 0);
			pos--;
		}// return 1 > down | 0 > up
	}
	else if (info->l_a > 3)
	{
		while (pos < (info->l_a - 1))
		{
			rev_rotate_a(info, 0);
			pos++;
		}
	}
	if (info->l_a > 3)
		push_b(info, 0);
	sort_three_nb_a(info);
	push_a(info, 0);
	push_a(info, 0);
}


void	index_my_array(t_infos *info)
{
	int i;
	int j;

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
				break;
			}
			j++;
		}
		i++;
	}
	
}

void	sort_big_nbs(t_infos *info)
{
	int old_l_a;
	int i;
	int j;

	i = 0;
	j = 0;
	old_l_a = info->l_a;
	index_my_array(info);
	while (!check_if_sorted(info->s_a, info->l_a))
	{
		j = 0;
		while (j < old_l_a)
		{
			if ((info->s_a[0] >> i)&1) // = 1
				rotate_a(info, 0);
			else
				push_b(info, 0);
			j++;
		}
		while (info->l_b != 0)
			push_a(info, 0);
		i++;
	}
}

int main(int argc, char **argv)
{
    t_infos info;
    
    if (argc < 2)
		exit(0);
	init_infos(&info);
    check_args(argc, argv);
    fill_stack_a(&info, argc, argv);
	sort_check_double(&info);
	if (info.l_a <= 3)
		sort_three_nb_a(&info);
	else if (info.l_a <= 5)
		sort_five_nb_a(&info);
	else if (info.l_a > 5)
		sort_big_nbs(&info);
	ft_free(&info);
	// system("leaks push_swap");
}