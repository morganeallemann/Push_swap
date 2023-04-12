#include"push_swap.h"


int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_b = NULL;
    stack_a = NULL;
    stack_a = ft_parse(ac, av);
    size_checker(stack_a, stack_b);
    //free
    return (0);
}