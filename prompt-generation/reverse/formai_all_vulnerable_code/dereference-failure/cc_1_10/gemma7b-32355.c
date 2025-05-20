//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    // Create a baggage cart
    struct baggage_cart {
        int capacity;
        char **items;
    } *cart = malloc(sizeof(struct baggage_cart));

    // Initialize the cart
    cart->capacity = 10;
    cart->items = malloc(cart->capacity * sizeof(char *));

    // Load the baggage
    cart->items[0] = "Laptop";
    cart->items[1] = "Trolley";
    cart->items[2] = "Shoes";
    cart->items[3] = "Clothes";
    cart->items[4] = "Books";

    // Shake the baggage
    int shake_amount = rand() % 5;
    for (int i = 0; i < shake_amount; i++)
    {
        int item_index = rand() % 5;
        char *item = cart->items[item_index];
        printf("%s has been shaken!\n", item);
    }

    // Unload the baggage
    for (int i = 0; i < cart->capacity; i++)
    {
        if (cart->items[i] != NULL)
        {
            printf("%s has been unloaded.\n", cart->items[i]);
            cart->items[i] = NULL;
        }
    }

    // Free the memory
    free(cart->items);
    free(cart);

    return 0;
}