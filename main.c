#include "push_swap.h"
#include <stdio.h>

int number_count(char **av)
{
    int capacity;
    capacity = 0;
    int i;
    i = 1;
    int j;
    char **strs;
    while(av[i])
    {
        j = 0;
        strs = ft_split(av[i], ' ');
        while (strs[j])
        {
            capacity++;
            j++;
        }
        i++;
    }
    return(capacity);
}

void add_numbers(t_stack *a, char **av)
{
    int i;
    int j;
    int k;
    int curr;
    char **strs;

    k = 0;
    i = 1;
    while(av[i])
    {
        strs = ft_split(av[i], ' ');
        j = 0;
        while (strs[j])
        {
            ft_control(strs[j]);
            curr = ft_atoi(strs[j]);
            if_same(*a, curr);
            a->numbers[k].number = curr;
            a->numbers[k].index = -1;
            a->size++;
            k++;
            j++;
        }
        i++;
    }
}

void init_stacks(t_stack *a, t_stack *b, char **av)
{
    a->capacity = number_count(av);
    b->capacity = a->capacity;
    a->numbers = malloc(sizeof(t_number) * a->capacity);
    b->numbers = malloc(sizeof(t_number) * a->capacity);
    a->size = 0;
    b->size = 0;
    add_numbers(a, av);
}
int main(int ac, char **av)
{
    t_stack a;
    t_stack b;
    if(ac > 2)
    {
        init_stacks(&a, &b, av);
        if (ft_inline(a))
           exit(0);
        index_numbers(&a);
        if (a.size < 6)
            mini_sort(&a, &b);
        else
            radix(&a, &b);
        for (int i = 0; i < a.size; i++)
        {
            printf("%d\n", a.numbers[i].index);
        }
    }
}
