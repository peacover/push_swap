/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 10:06:31 by yer-raki          #+#    #+#             */
/*   Updated: 2021/06/28 18:57:00 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "Libft/libft.h"

typedef struct	s_infos
{
	int		*s_a;
	int		*s_b;
	int		*sorted_a;
	int		*sorted_b;
	int		mid_a;
	int		mid_b;
	int		min_a;
	int		min_b;
	int		max_a;
	int		max_b;
}				t_infos;

int		ft_strlen2(char **w);
void	ft_putchar(char c);
void	ft_putstr(char *s);
int		ft_strlen_int(int *s);
int		*ft_strdup_int(const int *s1);

#endif

// echo 'alias code="/Applications/Visual\ Studio\ Code.app/Contents/Resources/app/bin/code"' >> ~/.zshrc
// source ~/.zshrc

// echo 'alias py="/Users/yer-raki/.brew/Cellar/python@3.9/3.9.5/bin/python3.9"' >> ~/.zshrc
// source ~/.zshrc