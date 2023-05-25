#include "push_swap.h"

static void three(t_stack *a)
{
    if (a->numbers[0].index == 2)
    {
        rotate(a, "ra\n");
        if (a->numbers[0].index == 1)
            swap(a, "sa\n");
    }
    else if (a->numbers[0].index == 1)
    {
        if (a->numbers[1].index == 0)
            swap(a, "sa\n");
        else
            reverserotate(a, "rra\n");
    }
    else if (a->numbers[0].index == 0)
    {
        reverserotate(a, "rra\n");
        swap(a, "sa\n");
    }
}

void mini_sort(t_stack *a, t_stack *b)
{
    if(a->size == 2)
        swap(a, "sa\n");
    else if(a->size == 3)
        three(a);
    else
    {
        while (a->size > 3)
        {
            if (a->numbers[0].index == 3 || a->numbers[0].index == 4)
                push(a, b, "pb\n");
            else
                rotate(a, "ra\n");
        }
        three(a);
        if (b->numbers[0].index == 4 && b->size == 2)
            swap(b, "sb\n");
        while (b->size > 0)
        {
            push(b, a, "pa\n");
            rotate(a, "ra\n");
        }
    }
}

