/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 10:06:31 by yer-raki          #+#    #+#             */
/*   Updated: 2021/06/30 19:19:11 by yer-raki         ###   ########.fr       */
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
	int		l_a;
	int		l_b;
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
int		*ft_strdup_int(const int *s1, int len);
void	*ft_realloc_int(void *ptr, size_t old_size, size_t new_size);
void	*ft_memcpy_int(void *dst, const void *src, size_t n);
void	print_my_int_array(int *s, int len);
void	swap_a(t_infos *info);
void	swap_b(t_infos *info);
void	push_a(t_infos *info);
void	push_b(t_infos *info);
void	rotate_a(t_infos *info);
void	rotate_b(t_infos *info);
void	rev_rotate_a(t_infos *info);
void	rev_rotate_a(t_infos *info);

#endif
// echo 'alias code="/Applications/Visual\ Studio\ Code.app/Contents/Resources/app/bin/code"' >> ~/.zshrc
// source ~/.zshrc

// echo 'alias py="/Users/yer-raki/.brew/Cellar/python@3.9/3.9.5/bin/python3.9"' >> ~/.zshrc
// source ~/.zshrc