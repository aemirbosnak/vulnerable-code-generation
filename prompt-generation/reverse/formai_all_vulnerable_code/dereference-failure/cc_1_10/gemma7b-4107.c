//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pizza
{
    char crust_type;
    char sauce_type;
    char cheese_type;
    int num_toppings;
    struct Pizza* next;
} Pizza;

Pizza* insert_pizza(Pizza* head, char crust_type, char sauce_type, char cheese_type, int num_toppings)
{
    Pizza* new_pizza = malloc(sizeof(Pizza));
    new_pizza->crust_type = crust_type;
    new_pizza->sauce_type = sauce_type;
    new_pizza->cheese_type = cheese_type;
    new_pizza->num_toppings = num_toppings;
    new_pizza->next = NULL;

    if (head == NULL)
    {
        head = new_pizza;
    }
    else
    {
        head->next = new_pizza;
    }

    return head;
}

void print_pizzas(Pizza* head)
{
    while (head)
    {
        printf("Crust: %c, Sauce: %c, Cheese: %c, Toppings: %d\n", head->crust_type, head->sauce_type, head->cheese_type, head->num_toppings);
        head = head->next;
    }
}

int main()
{
    Pizza* head = NULL;

    insert_pizza(head, 'F', 'S', 'M', 5);
    insert_pizza(head, 'C', 'T', 'A', 2);
    insert_pizza(head, 'G', 'R', 'P', 8);

    print_pizzas(head);

    return 0;
}