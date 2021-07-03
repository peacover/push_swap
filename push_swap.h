/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 10:06:31 by yer-raki          #+#    #+#             */
/*   Updated: 2021/07/03 10:50:03 by yer-raki         ###   ########.fr       */
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
}				t_infos;

void	ft_putchar(char c);
void	ft_putstr(char *s);
int		*ft_strdup_int(const int *s1, int len);
void	*ft_realloc_int(void *ptr, size_t old_size, size_t new_size);
void	*ft_memcpy_int(void *dst, const void *src, size_t n);
void	print_my_int_array(int *s, int len);
void	swap_a(t_infos *info, int t);
void	swap_b(t_infos *info, int t);
void	push_a(t_infos *info, int t);
void	push_b(t_infos *info, int t);
void	rotate_a(t_infos *info, int t);
void	rotate_b(t_infos *info, int t);
void	rev_rotate_a(t_infos *info, int t);
void	rev_rotate_b(t_infos *info, int t);
void    check_args(int argc, char **argv);
void    error_msg();
void	sort_check_double(t_infos *info);
int		check_if_sorted(int *s, int len);
void	init_infos(t_infos *info);
void    fill_stack_a(t_infos *info, int argc, char **argv);
void	ft_free(t_infos *info);
int		ft_strcmp(char *s1, char *s2);

#endif
// echo 'alias code="/Applications/Visual\ Studio\ Code.app/Contents/Resources/app/bin/code"' >> ~/.zshrc
// source ~/.zshrc

// echo 'alias py="/Users/yer-raki/.brew/Cellar/python@3.9/3.9.5/bin/python3.9"' >> ~/.zshrc
// source ~/.zshrc
