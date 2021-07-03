/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 10:06:21 by yer-raki          #+#    #+#             */
/*   Updated: 2021/07/03 17:25:47 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	print_my_int_array(int *s, int len)
// {
// 	int i;

// 	i = 0;
// 	printf("\n\n------------------------------------\n\n");
// 	while (len > i)
//     {
// 		printf("s[%d] : %d\n",i, s[i]);
// 		i++;
// 	}
// 	printf("\n\n------------------------------------");
// }

void	sort_big_nbs(t_infos *info)
{
	int	old_l_a;
	int	i;
	int	j;

	i = 0;
	j = 0;
	old_l_a = info->l_a;
	index_my_array(info);
	while (!check_if_sorted(info->s_a, info->l_a))
	{
		j = 0;
		while (j < old_l_a)
		{
			if ((info->s_a[0] >> i) & 1)
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

int	main(int argc, char **argv)
{
	t_infos	info;

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
}
