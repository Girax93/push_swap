/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrawe <agrawe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 23:29:49 by agrawe            #+#    #+#             */
/*   Updated: 2023/08/29 18:44:23 by agrawe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Bool: is input a number?
// Also removes leading 0's.
int	num_check(char *av)
{
	int i;

	i = 0;
	remove_leading_zeros(av);
	if (ft_issign(av[i]))
		i++;
	while (av[i] && ft_isdigit(av[i]))
		i++;
	return (av[i] == '\0');
}


// Bool: does the input (1 arg) consist of only 0's?
int	zero_check(char *av)
{
	int i;

	i = 0;
	if (ft_issign(av[i]))
		i++;
	while (av[i] == '0')
		i++;
	return (av[i] == '\0');
}


// Bool: are there duplicate numbers in the args?
// Uses num_str_cmp to test 2 strigns at a time.
// av[i] tracks which arg is being tested against the av[j] arg.
int	duplicate_check(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j] && ((i == j) || (num_str_cmp(av[i], av[j]) != 0)))
			j++;
		if (av[j])
			return (1);
		i++;
	}
	return (0);
}

// Bool: is the input correct?
// Checks if the input has more than one 0 value,
// Checks if the input has anything else than numbers in it
// Checks if the input has duplicates.
int	is_correct_input(char **av)
{
	int	i;
	int	zeros_bool;

	zeros_bool = 0;
	i = 1;
	while (av[i])
	{
		if (!num_check(av[i]) || (zeros_bool += zero_check(av[i])) > 1)
			return (0);
		i++;
	}
	if (duplicate_check(av))
		return (0);
	return (1);
}
