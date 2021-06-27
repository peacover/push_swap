/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 10:06:21 by yer-raki          #+#    #+#             */
/*   Updated: 2021/06/27 10:48:28 by yer-raki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    error_msg()
{
    ft_putstr_fd("Error\n", 1);
    exit(0);
}

// void    check_args(int argc, char **argv)
// {
//     int i;
    
// }

int main(int argc, char **argv)
{
    (void)argv;
    if (argc < 2)
        exit(0);
    // check_args(argc, argv);
    printf("hello");
}