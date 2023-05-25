#include "push_swap.h"

void ss(t_stack *a, t_stack *b)
{
    swap(a, NULL);
    swap(b, NULL);
    write(1, "ss\n", 3);
}

void rr(t_stack *a, t_stack *b)
{
    rotate(a, NULL);
    rotate(b, NULL);
    write(1, "rr\n", 3);
}

void rrr(t_stack *a, t_stack *b)
{
    reverserotate(a, NULL);
    reverserotate(b, NULL);
}