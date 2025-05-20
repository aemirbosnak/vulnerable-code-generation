//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
struct MenuItem {
    char *name;
    float price;
};

struct MenuItem menu[] = {
    {"Coffee", 2.50},
    {"Tea", 2.00},
    {"Cake", 3.00},
    {"Cookie", 1.50}
};

// Define the order struct
struct Order {
    int quantity;
    struct MenuItem *item;
};

// Define the customer struct
struct Customer {
    char *name;
    struct Order *orders;
    int num_orders;
};

// Function to create a new customer
struct Customer *create_customer(char *name) {
    struct Customer *customer = (struct Customer *)malloc(sizeof(struct Customer));
    customer->name = name;
    customer->orders = NULL;
    customer->num_orders = 0;
    return customer;
}

// Function to add an order to a customer
void add_order(struct Customer *customer, struct MenuItem *item, int quantity) {
    struct Order *new_order = (struct Order *)malloc(sizeof(struct Order));
    new_order->item = item;
    new_order->quantity = quantity;

    // Reallocate memory for the orders array if necessary
    if (customer->num_orders == 0) {
        customer->orders = (struct Order *)malloc(sizeof(struct Order));
    } else {
        customer->orders = (struct Order *)realloc(customer->orders, (customer->num_orders + 1) * sizeof(struct Order));
    }

    // Add the new order to the array
    customer->orders[customer->num_orders] = *new_order;
    customer->num_orders++;
}

// Function to calculate the total bill for a customer
float calculate_bill(struct Customer *customer) {
    float total = 0.0;
    for (int i = 0; i < customer->num_orders; i++) {
        total += customer->orders[i].item->price * customer->orders[i].quantity;
    }
    return total;
}

// Function to print the bill for a customer
void print_bill(struct Customer *customer) {
    printf("Bill for %s:\n", customer->name);
    for (int i = 0; i < customer->num_orders; i++) {
        printf("%d %s: $%.2f\n", customer->orders[i].quantity, customer->orders[i].item->name, customer->orders[i].item->price * customer->orders[i].quantity);
    }
    printf("Total: $%.2f\n", calculate_bill(customer));
}

// Main function
int main() {
    // Create a new customer
    struct Customer *customer = create_customer("John Doe");

    // Add some orders to the customer
    add_order(customer, &menu[0], 2);
    add_order(customer, &menu[1], 1);
    add_order(customer, &menu[2], 1);

    // Print the bill for the customer
    print_bill(customer);

    return 0;
}