/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 17:15:06 by yer-raki          #+#    #+#             */
/*   Updated: 2021/07/03 17:31:52 by yer-raki         ###   ########.fr       */
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
	while (s1 && s1[len1])
		len1++;
	s3 = (char *)malloc((len1 + 2) * sizeof(char));
	if (!s3)
		return (NULL);
	while (s1 && *s1)
		s3[i++] = *s1++;
	s3[i++] = c;
	s3[i] = '\0';
	return (s3);
}

void	ft_free(t_infos *info)
{
	free(info->sorted_a);
	free(info->s_a);
	free(info->s_b);
}

void	error_msg(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}
