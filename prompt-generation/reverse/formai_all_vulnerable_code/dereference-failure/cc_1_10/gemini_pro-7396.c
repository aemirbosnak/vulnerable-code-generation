//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the details of an item
struct Item {
    char name[50];
    int quantity;
    double price;
};

// Structure to store the details of an order
struct Order {
    struct Item items[100];
    int num_items;
    double total_price;
};

// Function to create a new order
struct Order *create_order() {
    struct Order *order = (struct Order *)malloc(sizeof(struct Order));
    order->num_items = 0;
    order->total_price = 0.0;
    return order;
}

// Function to add an item to an order
void add_item(struct Order *order, struct Item item) {
    order->items[order->num_items] = item;
    order->num_items++;
    order->total_price += item.price * item.quantity;
}

// Function to print the details of an order
void print_order(struct Order *order) {
    printf("\nOrder Details:\n");
    for (int i = 0; i < order->num_items; i++) {
        printf("%s\t%d\t%lf\n", order->items[i].name, order->items[i].quantity, order->items[i].price);
    }
    printf("Total Price: %lf\n", order->total_price);
}

// Driver code
int main() {
    // Create a new order
    struct Order *order = create_order();

    // Add items to the order
    struct Item item1 = {"Coffee", 2, 2.0};
    add_item(order, item1);
    struct Item item2 = {"Tea", 1, 1.5};
    add_item(order, item2);
    struct Item item3 = {"Sandwich", 1, 4.0};
    add_item(order, item3);

    // Print the details of the order
    print_order(order);

    return 0;
}