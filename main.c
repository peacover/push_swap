/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 10:06:21 by yer-raki          #+#    #+#             */
/*   Updated: 2021/06/29 12:04:06 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    error_msg()
{
    ft_putstr_fd("Error\n", 1);
    exit(0);
}
void	print_my_int_array(int *s)
{
	int i;

	i = 0;
	printf("\n\n------------------------------------\n\n");
	printf("\n\n ft_strlen int = |%d|\n\n", ft_strlen_int(s));
	while (i < 3 && s && s[i] != 0)
    {
		printf("s[%d] : %d\n",i, s[i]);
		i++;
	}
	printf("\n\n------------------------------------\n\n");
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
	info->s_a = (int*)malloc((argc + 1) * sizeof(int));
    while (argc - 1 > i)
    {
		info->s_a[i] = ft_atoi(argv[i + 1]);
		i++;
    }
	info->s_a[i] = 0;
	// i = 0;
	// while (info->s_a[i])
    // {
	// 	printf("s[%d] : %d\n",i, info->s_a[i]);
	// 	i++;
	// }
}

int		*ft_sort(int *s)
{
	int i;
	int j;
	int	*ret;
	int	tmp;
	
	i = 0;
	j = 0;
	ret = ft_strdup_int(s);
	while (ret[i])
	{
		j = i + 1;
		while (ret[j])
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
	info->sorted_a = ft_sort(info->s_a);
	info->mid_a = ft_strlen_int(info->s_a) / 2;
	while (info->s_a[i])
	{
		j = i + 1;
		while (info->s_a[j])
		{
			if (info->s_a[i] == info->s_a[j])
				error_msg();
			j++;
		}
		i++;
	}
	
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
	push_b(&info);
	print_my_int_array(info.s_a);
	// print_my_int_array(info.s_b);
	// push_b(&info);
	// print_my_int_array(info.s_a);
	// print_my_int_array(info.s_b);
	// push_b(&info);
	// print_my_int_array(info.s_a);
	// print_my_int_array(info.s_b);
	// push_a(&info);
	// print_my_int_array(info.s_a);
	// print_my_int_array(info.s_b);
	// push_a(&info);
	// print_my_int_array(info.s_a);
	// print_my_int_array(info.s_b);
	// swap_a(&info);
	// print_my_int_array(info.s_a);
	// print_my_int_array(info.s_b);
	// swap_b(&info);
	// print_my_int_array(info.s_a);
	// print_my_int_array(info.s_b);
    // printf("hello");
	// system("leaks push_swap");
}