#include "push_swap.h"

void swap(t_stack *stack, char *print)
{
    if (stack->size < 2)
        return ;
    int temp;
    temp = stack->numbers[1].index;
    stack->numbers[1].index = stack->numbers[0].index;
    stack->numbers[0].index = temp;
    if (print)
        write(1, print, 3);
}

void rotate(t_stack *stack, char *print)
{
    if (stack->size < 2)
        return ;
    int i;
    i  = 0;
    int temp;
    temp = stack->numbers[0].index;
    while(i < stack->size - 1)
    {
        stack->numbers[i].index = stack->numbers[i + 1].index;
        i++;
    }
    stack->numbers[stack->size - 1].index = temp;
    if (print)
        write(1, print, 3);
}


void reverserotate(t_stack *stack, char *print)
{
    if (stack->size < 2)
        return ;
    
    int temp;
    int size;
    temp =  stack->numbers[stack->size - 1].index;
    size = stack->size;
    while(size - 1 > 0)
    {
        stack->numbers[size - 1].index = stack->numbers[size - 2].index;
        size--;
    }
    stack->numbers[0].index = temp;
    if (print)
        write(1, print, 4);
}

void push(t_stack *sender, t_stack *receiver, char *print)
{
    if (sender->size < 1)
        return ;
    int i;
    int size;
    size = receiver->size;
    i = 0;
    int first;
    first = sender->numbers[0].index;
    while (i < sender->size - 1)
    {
        sender->numbers[i].index = sender->numbers[i + 1].index;
        i++; 
    }
    while(size - 1 >= 0)
    {
        receiver->numbers[size].index = receiver->numbers[size - 1].index;
        size--;
    }
    receiver->numbers[0].index = first;
    sender->size--;
    receiver->size++;
    write(1, print, 3);
}