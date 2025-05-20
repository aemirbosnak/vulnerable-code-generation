//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the menu items and their prices
struct MenuItem {
    char *name;
    double price;
};

struct MenuItem menuItems[] = {
    {"Coffee", 2.50},
    {"Tea", 2.00},
    {"Soda", 1.50},
    {"Water", 1.00},
    {"Muffin", 3.00},
    {"Croissant", 3.50},
    {"Bagel", 2.00},
    {"Yogurt", 2.50},
    {"Fruit cup", 3.00}
};

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the structure of the order
struct Order {
    struct MenuItem *items[MAX_ITEMS];
    int numItems;
    double total;
};

// Create a new order
struct Order *createOrder() {
    struct Order *order = malloc(sizeof(struct Order));
    order->numItems = 0;
    order->total = 0.0;
    return order;
}

// Add an item to the order
void addItemToOrder(struct Order *order, struct MenuItem *item) {
    order->items[order->numItems] = item;
    order->numItems++;
    order->total += item->price;
}

// Print the order
void printOrder(struct Order *order) {
    printf("Order:\n");
    for (int i = 0; i < order->numItems; i++) {
        printf("  %s: $%.2f\n", order->items[i]->name, order->items[i]->price);
    }
    printf("Total: $%.2f\n", order->total);
}

// Get the user's input
char *getInput(char *prompt) {
    char *input = malloc(100);
    printf("%s", prompt);
    scanf("%s", input);
    return input;
}

// Main function
int main() {
    // Create a new order
    struct Order *order = createOrder();

    // Get the user's input
    char *input = getInput("What would you like to order? (type 'done' to finish) ");

    // While the user has not entered 'done', add items to the order
    while (strcmp(input, "done") != 0) {
        // Find the menu item that matches the user's input
        struct MenuItem *item = NULL;
        for (int i = 0; i < sizeof(menuItems) / sizeof(struct MenuItem); i++) {
            if (strcmp(input, menuItems[i].name) == 0) {
                item = &menuItems[i];
                break;
            }
        }

        // If the menu item was found, add it to the order
        if (item != NULL) {
            addItemToOrder(order, item);
        } else {
            printf("Invalid item. Please try again.\n");
        }

        // Get the user's next input
        input = getInput("What would you like to order next? (type 'done' to finish) ");
    }

    // Print the order
    printOrder(order);

    // Free the memory allocated for the order
    free(order);

    return 0;
}