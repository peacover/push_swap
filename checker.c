/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:47:27 by yer-raki          #+#    #+#             */
/*   Updated: 2021/07/02 20:02:51 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_checker(t_infos *info)
{
	char c;
	char *str;

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
			str = ft_strjoin_char(str, c);
	}
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