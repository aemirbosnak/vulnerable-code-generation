//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Item types
#define FOOD 1
#define DRINK 2
#define DESSERT 3

// Item struct
typedef struct Item {
    int type;
    char *name;
    float price;
} Item;

// Order struct
typedef struct Order {
    int num_items;
    Item **items;
    float total_price;
} Order;

// Function to create a new item
Item *create_item(int type, char *name, float price) {
    Item *item = malloc(sizeof(Item));
    item->type = type;
    item->name = name;
    item->price = price;
    return item;
}

// Function to add an item to an order
void add_item_to_order(Order *order, Item *item) {
    order->items = realloc(order->items, (order->num_items + 1) * sizeof(Item *));
    order->items[order->num_items++] = item;
    order->total_price += item->price;
}

// Function to print an order
void print_order(Order *order) {
    printf("Order:\n");
    for (int i = 0; i < order->num_items; i++) {
        Item *item = order->items[i];
        printf("  - %s: $%.2f\n", item->name, item->price);
    }
    printf("Total: $%.2f\n", order->total_price);
}

// Main function
int main() {
    // Create a new order
    Order *order = malloc(sizeof(Order));
    order->num_items = 0;
    order->items = NULL;
    order->total_price = 0.0;

    // Add some items to the order
    add_item_to_order(order, create_item(FOOD, "Burger", 10.0));
    add_item_to_order(order, create_item(DRINK, "Coke", 2.0));
    add_item_to_order(order, create_item(DESSERT, "Cake", 5.0));

    // Print the order
    print_order(order);

    // Free the order
    for (int i = 0; i < order->num_items; i++) {
        free(order->items[i]);
    }
    free(order->items);
    free(order);

    return 0;
}