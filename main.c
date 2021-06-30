/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 10:06:21 by yer-raki          #+#    #+#             */
/*   Updated: 2021/06/30 20:37:31 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    error_msg()
{
    ft_putstr_fd("Error\n", 1);
    exit(0);
}
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
void    check_args(int argc, char **argv)
{
    int i;
    int j;
    int l;
    char *min_v;
    char *max_v;
    
    i = 1;
    l = 0;
    j = 0;
    min_v = ft_strdup("-2147483648");
    max_v = ft_strdup("2147483647");
    while (argc > i)
    {
        l = ft_strlen(argv[i]);
        if (l > 11 || (l > 10 && argv[i][0] != '-'))
            error_msg();
        else if (l == 10 || (l == 11 && argv[i][0] == '-'))
        {
            j = 0;
            while (argv[i][j])
            {
                if (l == 10 && argv[i][j] > max_v[j])
                    error_msg();
                else if (l == 11 && argv[i][j] > min_v[j])
                    error_msg();
                j++;
            }
        }
        i++;
    }
	free(min_v);
	free(max_v);
}

void    fill_stack_a(t_infos *info, int argc, char **argv)
{
    int i;
    
    i = 0;
	info->s_a = (int*)malloc((argc)  * sizeof(int));
	info->l_a = argc - 1;
    while (argc - 1 > i)
    {
		info->s_a[i] = ft_atoi(argv[i + 1]);
		i++;
    }
}

int		*ft_sort(int *s, int len)
{
	int i;
	int j;
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
	int i;
	int j;

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

int	check_if_sorted(int *s, int len)
{
	int i;

	i = 0;
	// print_my_int_array(s, len);
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
	min = get_min(info->s_a, 3);
	max = get_max(info->s_a, 3);
	if (check_if_sorted(info->s_a, 3) == 1)
		return;
	if (info->s_a[0] == max)
		rotate_a(info);
	if (check_if_sorted(info->s_a, 3) == 1)
		return;
	if (info->s_a[2] == min)
		rev_rotate_a(info);
	if (check_if_sorted(info->s_a, 3) == 1)
		return;
	if (info->s_a[0] > info->s_a[1])
		swap_a(info);
	// if (check_if_sorted(info->s_a, 3) == 1)
	// 	return;
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
	if (len / 2 > pos)
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
		push_b(info);
		min = get_min(info->s_a, info->l_a);
		pos = get_pos(info->s_a, min, info->l_a);
	}
	else if (pos == info->l_a - 1)
	{
		rev_rotate_a(info);
		push_b(info);
		min = get_min(info->s_a, info->l_a);
		pos = get_pos(info->s_a, min, info->l_a);
	}
	if (!up_or_down(pos, info->l_a))
	{
		while (pos > 0)
		{
			rotate_a(info);
			pos--;
		}// return 1 > down | 0 > up
	}
	else
	{
		while (pos < (info->l_a))
		{
			rev_rotate_a(info);
			pos++;
		}
	}
	push_b(info);
	min = get_min(info->s_a, info->l_a);
	pos = get_pos(info->s_a, min, info->l_a);
	if (info->l_a > 3 && pos == 0)
		push_b(info);
	else if (info->l_a > 3 && pos == info->l_a - 1)
	{
		rev_rotate_a(info);
		push_b(info);
	}
	min = get_min(info->s_a, info->l_a);
	pos = get_pos(info->s_a, min, info->l_a);
	if (info->l_a > 3 && !up_or_down(pos, info->l_a))
	{
		while (pos > 0)
		{
			rotate_a(info);
			pos--;
		}// return 1 > down | 0 > up
	}
	else if (info->l_a > 3)
	{
		while (pos < (info->l_a - 1))
		{
			rev_rotate_a(info);
			pos++;
		}
	}
	if (info->l_a > 3)
		push_b(info);
	sort_three_nb_a(info);
	push_a(info);
	push_a(info);
}

void	init_infos(t_infos *info)
{
	info->s_a = NULL;
	info->s_b = NULL;
	info->sorted_a = NULL;
	info->sorted_b = NULL;
	info->mid_a = 0;
	info->mid_b = 0;
	info->min_a = 0;
	info->min_b = 0;
	info->max_a = 0;
	info->max_b = 0;
	info->l_a = 0;
	info->l_b = 0;
}

int main(int argc, char **argv)
{
    t_infos info;
    
    if (argc < 2)
		exit(0);
    check_args(argc, argv);
	init_infos(&info);
    fill_stack_a(&info, argc, argv);
	sort_check_double(&info);
	// print_my_int_array(info.s_a, info.l_a);
	// print_my_int_array(info.s_b, info.l_b);
	// sort_three_nb_a(&info);
	sort_five_nb_a(&info);
	// rotate_a(&info);
	// print_my_int_array(info.s_a, info.l_a);
	// print_my_int_array(info.s_b, info.l_b);
	// rev_rotate_a(&info);
	// print_my_int_array(info.s_a, info.l_a);
	// print_my_int_array(info.s_b, info.l_b);
	// push_b(&info);
	// print_my_int_array(info.s_a, info.l_a);
	// print_my_int_array(info.s_b, info.l_b);
	// push_b(&info);
	// print_my_int_array(info.s_a, info.l_a);
	// print_my_int_array(info.s_b, info.l_b);
	// rotate_b(&info);
	// print_my_int_array(info.s_a, info.l_a);
	// print_my_int_array(info.s_b, info.l_b);
    // printf("hello");
	// system("leaks push_swap");
}