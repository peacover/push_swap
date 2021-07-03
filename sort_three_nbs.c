/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_nbs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 16:12:06 by yer-raki          #+#    #+#             */
/*   Updated: 2021/07/03 17:38:15 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_nb_a(t_infos *info)
{
	int	i;
	int	min;
	int	max;

	i = 0;
	min = get_min(info->s_a, info->l_a);
	max = get_max(info->s_a, info->l_a);
	if (check_if_sorted(info->s_a, info->l_a) == 1)
		return ;
	if (info->s_a[0] == max)
		rotate_a(info, 0);
	if (check_if_sorted(info->s_a, info->l_a) == 1)
		return ;
	if (info->s_a[2] == min)
		rev_rotate_a(info, 0);
	if (check_if_sorted(info->s_a, info->l_a) == 1)
		return ;
	if (info->s_a[1] > info->s_a[2])
		rev_rotate_a(info, 0);
	if (check_if_sorted(info->s_a, info->l_a) == 1)
		return ;
	if (info->s_a[0] > info->s_a[1])
		swap_a(info, 0);
}
