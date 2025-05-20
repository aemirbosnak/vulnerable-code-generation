//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the order
#define MAX_ITEMS 10

// Define the structure of an item in the order
typedef struct item {
    char name[50];
    int quantity;
    float price;
} item;

// Define the structure of the order
typedef struct order {
    int num_items;
    item items[MAX_ITEMS];
    float total_price;
} order;

// Create a new order
order* create_order() {
    order* new_order = malloc(sizeof(order));
    new_order->num_items = 0;
    new_order->total_price = 0.0;
    return new_order;
}

// Add an item to the order
void add_item(order* order, char* name, int quantity, float price) {
    if (order->num_items < MAX_ITEMS) {
        strcpy(order->items[order->num_items].name, name);
        order->items[order->num_items].quantity = quantity;
        order->items[order->num_items].price = price;
        order->num_items++;
        order->total_price += quantity * price;
    } else {
        printf("Error: Order is full. Cannot add more items.\n");
    }
}

// Print the order
void print_order(order* order) {
    printf("Order Summary:\n");
    for (int i = 0; i < order->num_items; i++) {
        printf("%s x %d = %.2f\n", order->items[i].name, order->items[i].quantity, order->items[i].price * order->items[i].quantity);
    }
    printf("Total Price: %.2f\n", order->total_price);
}

// Get the user's input
void get_user_input(order* order) {
    char name[50];
    int quantity;
    float price;

    printf("Enter the item name: ");
    scanf("%s", name);

    printf("Enter the quantity: ");
    scanf("%d", &quantity);

    printf("Enter the price: ");
    scanf("%f", &price);

    add_item(order, name, quantity, price);
}

// Main function
int main() {
    // Create a new order
    order* order = create_order();

    // Get the user's input
    get_user_input(order);

    // Print the order
    print_order(order);

    // Free the order
    free(order);

    return 0;
}