/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:47:27 by yer-raki          #+#    #+#             */
/*   Updated: 2021/07/02 20:38:32 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

char	*ft_strjoin_char(char const *s1, char const c)
{
	int		len1;
	char	*s3;
	int		i;

	i = 0;
	len1 = 0;
	while (s1[len1])
		len1++;
	s3 = (char *)malloc((len1 + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	while (*s1)
		s3[i++] = *s1++;
	s3[i++] = c;
	s3[i] = '\0';
	return (s3);
}

void	check_op(char *str)
{
	int i;

	i = 0;
	if (ft_strcmp(str, "sa") || ft_strcmp(str, "sb")
	|| ft_strcmp(str, "ss") || ft_strcmp(str, "pa")
	|| ft_strcmp(str, "pb") || ft_strcmp(str, "ra")
	|| ft_strcmp(str, "rb") || ft_strcmp(str, "rr")
	|| ft_strcmp(str, "rra") || ft_strcmp(str, "rrb")
	|| ft_strcmp(str, "rrr"))
	{
	  error_msg();
	}
}

void	menu_operations(t_infos *info, char *str)
{
	if (!ft_strcmp(str, "sa"))
		swap_a(info);
	else if (!ft_strcmp(str, "sb"))
		swap_b(info);
	else if (!ft_strcmp(str, "ss"))
	{
		swap_a(info);
		swap_b(info);
	}
	else if (!ft_strcmp(str, "pa"))
		push_a(info);
	else if (!ft_strcmp(str, "pb"))
		push_b(info);
	else if (!ft_strcmp(str, "ra"))
		rotate_a(info);
	else if (!ft_strcmp(str, "rb"))
		rotate_b(info);
	else if (!ft_strcmp(str, "rr"))
	{
		rotate_a(info);
		rotate_b(info);
	}
	else if (!ft_strcmp(str, "rra"))
		rev_rotate_a(info);
	else if (!ft_strcmp(str, "rrb"))
		rev_rotate_b(info);
	else if (!ft_strcmp(str, "rrr"))
	{
		rev_rotate_a(info);
		rev_rotate_b(info);
	}
}

void	ft_checker(t_infos *info)
{
	char	c;
	char	*str;
	char	*tmp;

	c = '\0';
	str = NULL;
	while (read(0, &c, 1) > 0)
	{
		if (c == '\n')
		{
			check_op(str);
			menu_operations(info, str);
		}   
		else  
		{
			tmp = str;
			str = ft_strjoin_char(str, c);
			free(tmp);
		}
	}

	if (check_if_sorted(info->s_a, info->l_a))
		ft_putstr("OK");
	else
		ft_putstr("KO");
}

int	main(int argc, char **argv)
{
	t_infos info;
	
	if (argc < 2)
		exit(0);
    check_args(argc, argv);
	init_infos(&info);
	fill_stack_a(&info, argc, argv);
	sort_check_double(&info);
	ft_checker(&info);
}