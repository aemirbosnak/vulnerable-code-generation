//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Item structure
typedef struct item {
    char* name;
    float price;
    int quantity;
} item;

// Order structure
typedef struct order {
    item* items;
    int num_items;
    float total_price;
} order;

// Create a new item
item* create_item(char* name, float price, int quantity) {
    item* new_item = malloc(sizeof(item));
    new_item->name = name;
    new_item->price = price;
    new_item->quantity = quantity;
    return new_item;
}

// Create a new order
order* create_order() {
    order* new_order = malloc(sizeof(order));
    new_order->items = NULL;
    new_order->num_items = 0;
    new_order->total_price = 0;
    return new_order;
}

// Add an item to an order
void add_item_to_order(order* order, item* item) {
    order->items = realloc(order->items, (order->num_items + 1) * sizeof(item));
    order->items[order->num_items] = *item;
    order->num_items++;
    order->total_price += item->price * item->quantity;
}

// Print an order
void print_order(order* order) {
    printf("Order Summary:\n");
    for (int i = 0; i < order->num_items; i++) {
        printf("Item: %s, Price: %f, Quantity: %d\n", order->items[i].name, order->items[i].price, order->items[i].quantity);
    }
    printf("Total Price: %f\n", order->total_price);
}

// Free the memory allocated for an order
void free_order(order* order) {
    free(order->items);
    free(order);
}

// Main function
int main() {
    // Create a new order
    order* order = create_order();

    // Add items to the order
    add_item_to_order(order, create_item("Coffee", 2.5, 2));
    add_item_to_order(order, create_item("Tea", 1.5, 1));
    add_item_to_order(order, create_item("Cake", 3.0, 1));

    // Print the order
    print_order(order);

    // Free the memory allocated for the order
    free_order(order);

    return 0;
}