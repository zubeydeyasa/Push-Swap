#include "push_swap.h"

void error()
{
    write(2, "Error\n", 6);
    exit(1);
}

void ft_control(char *str)
{
    int i;
    i = 0;
    if ((str[0] == '-' || str[0] == '+') && str[1] == '\0')
        error();
    while(str[i])
    {
        if(ft_isalpha(str[i]))
            error();
        else if((str[i] == '+' || str[i] == '-') && i != 0)
            error();
        i++;
    }
}

int ft_inline(t_stack a)
{
    int i;
    i = 0;

    while(i < a.size)
    {
        if(a.numbers[i].number > a.numbers[i + 1].number)
            return 0;
        i++;
    }
    return 1;
}

void if_same(t_stack a, int number)
{
    int i;
    i = 0;
    while(i < a.size)
    {
        if(a.numbers[i].number == number)
            error();
        i++;
    }
}