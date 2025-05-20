//Gemma-7B DATASET v1.0 Category: Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIZZA_SIZE 20

typedef struct Pizza
{
    char *name;
    int size;
    float price;
    struct Pizza *next;
} Pizza;

Pizza *createPizza(char *name, int size, float price)
{
    Pizza *newPizza = malloc(sizeof(Pizza));
    newPizza->name = strdup(name);
    newPizza->size = size;
    newPizza->price = price;
    newPizza->next = NULL;

    return newPizza;
}

void addPizza(Pizza *head, char *name, int size, float price)
{
    Pizza *newPizza = createPizza(name, size, price);
    if (head == NULL)
    {
        head = newPizza;
    }
    else
    {
        newPizza->next = head;
        head = newPizza;
    }
}

void printPizza(Pizza *head)
{
    while (head)
    {
        printf("Name: %s\n", head->name);
        printf("Size: %d\n", head->size);
        printf("Price: %.2f\n", head->price);
        printf("\n");
        head = head->next;
    }
}

int main()
{
    Pizza *pizzaHead = NULL;

    addPizza(pizzaHead, "Margherita", 12, 10.00);
    addPizza(pizzaHead, "Pepperoni", 14, 12.00);
    addPizza(pizzaHead, "Hawaiian", 16, 14.00);

    printPizza(pizzaHead);

    return 0;
}