/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrawe <agrawe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 23:28:48 by agrawe            #+#    #+#             */
/*   Updated: 2023/08/20 23:28:49 by agrawe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/push_swap.h"

// Checks if input is correct
// Declares an empty stack_b, and fills our argv's into stack_a
// Push_swap's (hehe)
// Frees.
int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack *check_a;
	t_stack *check_b;

	if (ac < 2)
		return (0);
	if (!is_correct_input(av))
		write_error();
	stack_b = NULL;
	stack_a = fill_stack_a(ac, av);
	push_swap(&stack_a, &stack_b);
	check_a = stack_a;
	check_b = stack_b;
	write(1, "\n", 1);
	write(1, "stack_a\n", 8);
	while (check_a)
	{
		printf("%d\n", check_a->val);
		check_a = check_a->next;
	}
	write(1, "\n", 1);
	write(1, "stack_b\n", 8);
	while (check_b)
	{
		printf("%d\n", check_b->val);
		check_b = check_b->next;
	}
	if (!sorted_check(stack_a))
		write_error();
	free_list(&stack_a);
	return (0);
}
