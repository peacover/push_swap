/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_nbs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 15:37:11 by yer-raki          #+#    #+#             */
/*   Updated: 2021/07/03 17:38:03 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five_nb_a_2(t_infos *info)
{
	int	min;
	int	pos;

	if (check_if_sorted(info->s_a, info->l_a))
		return ;
	min = get_min(info->s_a, info->l_a);
	pos = get_pos(info->s_a, min, info->l_a);
	if (pos == 0)
		push_b(info, 0);
	else if (pos == info->l_a - 1)
	{
		rev_rotate_a(info, 0);
		if (check_if_sorted(info->s_a, info->l_a))
			return ;
		push_b(info, 0);
	}
}

void	sort_five_nb_a_3(t_infos *info)
{
	int	min;
	int	pos;

	min = get_min(info->s_a, info->l_a);
	pos = get_pos(info->s_a, min, info->l_a);
	if (!up_or_down(pos, info->l_a))
	{
		while (pos > 0)
		{
			rotate_a(info, 0);
			pos--;
		}
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
}

void	sort_five_nb_a_5(t_infos *info)
{
	int	min;
	int	pos;

	min = get_min(info->s_a, info->l_a);
	pos = get_pos(info->s_a, min, info->l_a);
	if (info->l_a > 3 && !up_or_down(pos, info->l_a))
	{
		while (pos > 0)
		{
			rotate_a(info, 0);
			pos--;
		}
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
}

void	sort_five_nb_a_4(t_infos *info)
{
	int	min;
	int	pos;

	min = get_min(info->s_a, info->l_a);
	pos = get_pos(info->s_a, min, info->l_a);
	if (info->l_a > 3 && pos == 0)
		push_b(info, 0);
	else if (info->l_a > 3 && pos == info->l_a - 1)
	{
		rev_rotate_a(info, 0);
		push_b(info, 0);
	}
}

void	sort_five_nb_a(t_infos *info)
{
	sort_five_nb_a_2(info);
	sort_five_nb_a_3(info);
	sort_five_nb_a_4(info);
	sort_five_nb_a_5(info);
	sort_three_nb_a(info);
	push_a(info, 0);
	push_a(info, 0);
}
