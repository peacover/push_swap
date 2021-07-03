/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 10:06:27 by yer-raki          #+#    #+#             */
/*   Updated: 2021/07/03 11:10:23 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int		ft_strcmp_char(char c1, char c2)
{
	return (c1 - c2);
}

int	*ft_strdup_int(const int *s1, int len)
{
	int		i;
	int		l;
	int		*d;

	i = 0;
	l = len;
	if (len < 1)
		return ((int*)s1);
	d = (int *)malloc(sizeof(int) * (l));
	if (!d)
		return (NULL);
	while (l > i)
	{
		d[i] = s1[i];
		i++;
	}
	return (d);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	*ft_memcpy_int(void *dst, const void *src, size_t n)
{
	int	*d;
	int	*s;
	size_t	i;

	i = 0;
	d = (int *)dst;
	s = (int *)src;
	if (d == NULL && s == NULL)
		return (NULL);
	while (n > i)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

void	*ft_realloc_int(void *ptr, size_t old_size, size_t new_size)
{
	void	*new;
	
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new = (int*)malloc(new_size * sizeof(int));
	if (!new)
		return (NULL);
	if (ptr != NULL || !old_size)
	{
		if (old_size >= new_size)
			ft_memcpy_int(new, ptr, new_size);
		else
			ft_memcpy_int(new, ptr, old_size);
		free(ptr);
	}
	return (new);
}

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

void    error_msg()
{
    ft_putstr_fd("Error\n", 1);
    exit(0);
}
int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;

	if (!s1)
		return (s2[i]);
	else if (!s2)
		return (s1[i]);
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
void	ft_free(t_infos *info)
{
	free(info->sorted_a);
	free(info->s_a);
	free(info->s_b);
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
    // while (argc > i)
    // {
    //     l = ft_strlen(argv[i]);
    //     if (l > 11 || (l > 10 && argv[i][0] != '-'))
    //         error_msg();
    //     else if (l == 10 || (l == 11 && argv[i][0] == '-'))
    //     {
    //         j = 0;
    //         while (argv[i][j])
    //         {
    //             if (l == 10 && ft_strcmp_char(argv[i][j], max_v[j]) > 0)
    //                 error_msg();
    //             else if (l == 11 && argv[i][0] != '-' && ft_strcmp_char(argv[i][j], min_v[j]) < 0)
    //                 error_msg();
	// 			else if (argv[i][j] == max_v[j])
    //             	j++;
	// 			else
	// 				break;
    //         }
    //     }
    //     i++;
    // }
	while (argc > i)
	{
		l = ft_atoi(argv[i]);
		if (ft_strcmp(argv[i], ft_itoa(l)))
			error_msg();
		i++;
	}
	free(min_v);
	free(max_v);
}