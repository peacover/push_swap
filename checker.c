/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:47:27 by yer-raki          #+#    #+#             */
/*   Updated: 2021/07/03 16:34:16 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_op(char *str)
{
	int	i;

	i = 0;
	if (ft_strcmp(str, "sa") && ft_strcmp(str, "sb")
		&&ft_strcmp(str, "ss") && ft_strcmp(str, "pa")
		&& ft_strcmp(str, "pb") && ft_strcmp(str, "ra")
		&& ft_strcmp(str, "rb") && ft_strcmp(str, "rr")
		&& ft_strcmp(str, "rra") && ft_strcmp(str, "rrb")
		&& ft_strcmp(str, "rrr"))
	{
		error_msg();
	}
}

void	menu_operations_2(t_infos *info, char *str)
{
	if (!ft_strcmp(str, "ra"))
		rotate_a(info, 1);
	else if (!ft_strcmp(str, "rb"))
		rotate_b(info, 1);
	else if (!ft_strcmp(str, "rr"))
	{
		rotate_a(info, 1);
		rotate_b(info, 1);
	}
	else if (!ft_strcmp(str, "rra"))
		rev_rotate_a(info, 1);
	else if (!ft_strcmp(str, "rrb"))
		rev_rotate_b(info, 1);
	else if (!ft_strcmp(str, "rrr"))
	{
		rev_rotate_a(info, 1);
		rev_rotate_b(info, 1);
	}
}

void	menu_operations(t_infos *info, char *str)
{
	if (!ft_strcmp(str, "sa"))
		swap_a(info, 1);
	else if (!ft_strcmp(str, "sb"))
		swap_b(info, 1);
	else if (!ft_strcmp(str, "ss"))
	{
		swap_a(info, 1);
		swap_b(info, 1);
	}
	else if (!ft_strcmp(str, "pa"))
		push_a(info, 1);
	else if (!ft_strcmp(str, "pb"))
		push_b(info, 1);
	menu_operations_2(info, str);
}

void	ft_checker(t_infos *info)
{
	char	c;
	char	*str;
	char	*tmp;

	c = '\0';
	str = NULL;
	tmp = NULL;
	while (read(0, &c, 1) > 0)
	{
		if (c == '\n')
		{
			check_op(str);
			menu_operations(info, str);
			free(str);
			str = NULL;
		}
		else
		{
			tmp = str;
			str = ft_strjoin_char(str, c);
			free(tmp);
		}
	}
	free(str);
}

int	main(int argc, char **argv)
{
	t_infos	info;

	if (argc < 2)
		exit(0);
	check_args(argc, argv);
	init_infos(&info);
	fill_stack_a(&info, argc, argv);
	sort_check_double(&info);
	ft_checker(&info);
	if (check_if_sorted(info.s_a, info.l_a) && info.l_b < 1)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	ft_free(&info);
}
// system("leaks checker");
/*int i;
	int	min;
	int pos;
	
	
	i = 0;
	if (check_if_sorted(info->s_a, info->l_a))
		return;
	min = get_min(info->s_a, info->l_a);
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
		if (check_if_sorted(info->s_a, info->l_a))
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
	push_a(info, 0);*/