#ifndef PUSH_SWAP
#define PUSH_SWAP

#include "Libft/libft.h"

typedef struct s_number
{
    int number;
    int index;
} t_number;

typedef struct s_stack
{
    t_number    *numbers;
    int     size;
    int     capacity;
} t_stack;


void ft_control(char *str);
int ft_inline(t_stack a);
void swap(t_stack *stack, char *print);
void rotate(t_stack *stack, char *print);
void reverserotate(t_stack *stack, char *print);
void push(t_stack *sender, t_stack *receiver, char *print);
void ss(t_stack *a, t_stack *b);
void rr(t_stack *a, t_stack *b);
void rrr(t_stack *a, t_stack *b);
void index_numbers(t_stack *stack);
void if_same(t_stack a, int number);
void radix(t_stack *a, t_stack *b);
void mini_sort(t_stack *a, t_stack *b);
#endif