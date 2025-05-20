//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of items in a cafe order
#define MAX_ITEMS 10

// Define the structure of a cafe item
typedef struct {
    char name[50];
    int price;
    int quantity;
} CafeItem;

// Define the structure of a cafe order
typedef struct {
    CafeItem items[MAX_ITEMS];
    int num_items;
    int total_price;
} CafeOrder;

// Function to create a new cafe order
CafeOrder* create_order() {
    CafeOrder* order = malloc(sizeof(CafeOrder));
    order->num_items = 0;
    order->total_price = 0;
    return order;
}

// Function to add an item to a cafe order
void add_item(CafeOrder* order, CafeItem item) {
    if (order->num_items < MAX_ITEMS) {
        order->items[order->num_items] = item;
        order->num_items++;
        order->total_price += item.price * item.quantity;
    } else {
        printf("Error: Order is full.\n");
    }
}

// Function to print a cafe order
void print_order(CafeOrder* order) {
    printf("Order:\n");
    for (int i = 0; i < order->num_items; i++) {
        printf("%s x%d  $%d\n", order->items[i].name, order->items[i].quantity, order->items[i].price);
    }
    printf("Total: $%d\n", order->total_price);
}

// Main function
int main() {
    // Create a new cafe order
    CafeOrder* order = create_order();

    // Add some items to the order
    CafeItem item1 = {"Latte", 3, 1};
    add_item(order, item1);
    CafeItem item2 = {"Cappuccino", 4, 2};
    add_item(order, item2);
    CafeItem item3 = {"Espresso", 2, 3};
    add_item(order, item3);

    // Print the order
    print_order(order);

    // Free the memory used by the order
    free(order);

    return 0;
}