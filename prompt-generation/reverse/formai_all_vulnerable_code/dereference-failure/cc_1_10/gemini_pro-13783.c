//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the menu items and their prices
struct MenuItem {
    char *name;
    float price;
};

struct MenuItem menu[] = {
    {"Coffee", 2.50},
    {"Tea", 1.50},
    {"Cake", 3.00},
    {"Cookie", 1.00}
};

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the customer's order
struct Order {
    struct MenuItem *items[MAX_ITEMS];
    int num_items;
    float total_price;
};

// Create a new order
struct Order *new_order() {
    struct Order *order = malloc(sizeof(struct Order));
    order->num_items = 0;
    order->total_price = 0.0;
    return order;
}

// Add an item to the order
void add_item(struct Order *order, struct MenuItem *item) {
    if (order->num_items < MAX_ITEMS) {
        order->items[order->num_items++] = item;
        order->total_price += item->price;
    } else {
        printf("Error: Order is full\n");
    }
}

// Print the order
void print_order(struct Order *order) {
    printf("Order:\n");
    for (int i = 0; i < order->num_items; i++) {
        printf(" - %s: $%.2f\n", order->items[i]->name, order->items[i]->price);
    }
    printf("Total: $%.2f\n", order->total_price);
}

// Free the memory allocated for the order
void free_order(struct Order *order) {
    free(order);
}

// Get the user's input
char *get_input(char *prompt) {
    char *input = malloc(100);
    printf("%s", prompt);
    scanf("%s", input);
    return input;
}

// Main function
int main() {
    // Create a new order
    struct Order *order = new_order();

    // Get the user's input
    char *input = get_input("Enter an item (or 'q' to quit): ");

    // Loop until the user quits
    while (strcmp(input, "q") != 0) {
        // Find the menu item
        struct MenuItem *item = NULL;
        for (int i = 0; i < sizeof(menu) / sizeof(struct MenuItem); i++) {
            if (strcmp(input, menu[i].name) == 0) {
                item = &menu[i];
                break;
            }
        }

        // If the item was found, add it to the order
        if (item) {
            add_item(order, item);
        } else {
            printf("Error: Item not found\n");
        }

        // Get the next item
        input = get_input("Enter an item (or 'q' to quit): ");
    }

    // Print the order
    print_order(order);

    // Free the memory allocated for the order
    free_order(order);

    return 0;
}