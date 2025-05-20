//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the structure of the items in the warehouse
struct item {
    char name[50];
    int quantity;
    float price;
};

// Define the structure of the orders
struct order {
    char customer[50];
    struct item *items;
    int num_items;
    float total_price;
};

// Function to print the details of an order
void print_order(struct order *order) {
    printf("Customer: %s\n", order->customer);
    printf("Items:\n");
    for (int i = 0; i < order->num_items; i++) {
        printf("\t%s - %d units - $%.2f\n", order->items[i].name, order->items[i].quantity, order->items[i].price);
    }
    printf("Total Price: $%.2f\n", order->total_price);
}

// Function to generate a new order
struct order *generate_order(int num_items) {
    struct order *order = (struct order *)malloc(sizeof(struct order));
    order->num_items = num_items;
    order->items = (struct item *)malloc(num_items * sizeof(struct item));

    // Generate random items for the order
    for (int i = 0; i < num_items; i++) {
        order->items[i].name[0] = 'A' + rand() % 26;
        for (int j = 1; j < 50; j++) {
            order->items[i].name[j] = 'a' + rand() % 26;
        }
        order->items[i].quantity = rand() % 100 + 1;
        order->items[i].price = rand() % 1000 / 100.0;
    }

    return order;
}

// Function to process an order
void process_order(struct order *order) {
    for (int i = 0; i < order->num_items; i++) {
        printf("Processing item %s...\n", order->items[i].name);
        sleep(1);
    }
    printf("Order processed successfully!\n");
}

// Main function
int main() {
    srand(time(NULL));

    // Generate a new order
    struct order *order = generate_order(5);

    // Print the details of the order
    printf("New Order:\n");
    print_order(order);

    // Process the order
    process_order(order);

    // Print the details of the order again
    printf("Order processed:\n");
    print_order(order);

    return 0;
}