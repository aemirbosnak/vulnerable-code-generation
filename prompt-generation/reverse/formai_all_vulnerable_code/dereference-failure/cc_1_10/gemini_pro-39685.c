//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
struct MenuItem {
    char name[50];
    float price;
};

struct MenuItem menuItems[] = {
    {"Coffee", 2.50},
    {"Tea", 1.50},
    {"Cake", 3.00},
    {"Sandwich", 4.00},
    {"Salad", 5.00}
};

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the order structure
struct Order {
    int itemCount;
    struct MenuItem items[MAX_ITEMS];
};

// Create a new order
struct Order* createOrder() {
    struct Order* order = malloc(sizeof(struct Order));
    order->itemCount = 0;
    return order;
}

// Get the total price of an order
float getTotalPrice(struct Order* order) {
    float totalPrice = 0;
    for (int i = 0; i < order->itemCount; i++) {
        totalPrice += order->items[i].price;
    }
    return totalPrice;
}

// Print the order
void printOrder(struct Order* order) {
    printf("Order:\n");
    for (int i = 0; i < order->itemCount; i++) {
        printf("%s: $%.2f\n", order->items[i].name, order->items[i].price);
    }
    printf("Total: $%.2f\n", getTotalPrice(order));
}

// Main function
int main() {
    // Create a new order
    struct Order* order = createOrder();

    // Get the user's input
    int choice;
    do {
        // Display the menu
        printf("Menu:\n");
        for (int i = 0; i < sizeof(menuItems) / sizeof(struct MenuItem); i++) {
            printf("%d. %s: $%.2f\n", i + 1, menuItems[i].name, menuItems[i].price);
        }
        printf("0. Exit\n");

        // Get the user's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Add the item to the order
        if (choice > 0 && choice <= sizeof(menuItems) / sizeof(struct MenuItem)) {
            order->items[order->itemCount++] = menuItems[choice - 1];
        }
    } while (choice != 0);

    // Print the order
    printOrder(order);

    // Free the allocated memory
    free(order);

    return 0;
}