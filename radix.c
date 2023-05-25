#include "push_swap.h"
#include <stdio.h>
//ilk gelen indeksleri bitlere çevirmem gerekiyor
//sonra sondaki bit 0 sa bye göndericem
//sonra hepsini a ya göndericem, 2.bitlere bakıcam

static int find_max_bit(t_stack a)
{
    int max;

    max = 0;
    a.size--;
    while (a.size > 0)
    {
        a.size /= 2;
        max++;
    }
    return (max);
}

void radix(t_stack *a, t_stack *b)
{
    int i;
    int j;
    int max;

    j = 0;
    max = find_max_bit(*a);
    while (j < max)
    {
        i = 0;
        while (i < a->capacity)
        {
            if((a->numbers[0].index >> j & 1))
                rotate(a, "ra\n");
            else
                push(a, b, "pb\n");
            i++;
        }
        while (b->size > 0)
            push(b, a, "pa\n");
        j++;
    }
}
    