#include"push_swap.h"

int check_nb(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if(!(str[i] >= '0' && str[i] <= '9') && !(str[i] == '+' || str[i] == '-'))
            return (1);
        i++;
    }
    return (0);
}

int check_sign(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '+' || str[i] == '-')
        {
            if (str[i + 1] == '+' || str[i + 1] == '-')
                return (1);
            if (str[i + 1] == '\0' || str[i] == '\0')
                return (1);
        }
        i++;
    }
    return (0);
}
int valid_input(char *str)
{
    if (check_nb(str) != 0)
        return (1);
    if (check_sign(str) != 0)
        return (1);
    return (0);
}

void    ft_init(char **array, int element_nb)
{
    int i;
    int *list_nb;

    i = 0;
    while (array[i])
    {
        if (valid_input(array[i]) != 0)
            printf("ERROR\n");
        i++;
    }
    i = 0;
    list_nb = malloc(sizeof(int) * element_nb);
    while (array[i])
    {
        list_nb[i] = ft_atoi(array[i]);
        ft_printf("%d\n", list_nb[i]);
        i++;
    }
}
int main(int ac, char **av)
{
    int     i;
    char    **array;

    i = 0;
    if (ac == 2)
    {
        array = ft_split(av[1], ' ');
        while (array[i])
            i++;
        ft_init(array, i);
    }
}