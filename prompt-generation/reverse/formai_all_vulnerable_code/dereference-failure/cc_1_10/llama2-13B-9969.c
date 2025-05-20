//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CUSTOMERS 100
#define MAX_ORDERS 100

// Structure to store customer information
typedef struct {
    char name[50];
    char address[100];
    int phone_number;
} customer_t;

// Structure to store order information
typedef struct {
    char customer_name[50];
    char item_name[50];
    int quantity;
    int total_amount;
} order_t;

// Function to create a new customer
customer_t *create_customer(char *name, char *address, int phone_number) {
    customer_t *new_customer = (customer_t *)malloc(sizeof(customer_t));
    strcpy(new_customer->name, name);
    strcpy(new_customer->address, address);
    new_customer->phone_number = phone_number;
    return new_customer;
}

// Function to create a new order
order_t *create_order(char *customer_name, char *item_name, int quantity, int total_amount) {
    order_t *new_order = (order_t *)malloc(sizeof(order_t));
    strcpy(new_order->customer_name, customer_name);
    strcpy(new_order->item_name, item_name);
    new_order->quantity = quantity;
    new_order->total_amount = total_amount;
    return new_order;
}

// Function to add an item to a customer's order
void add_item_to_order(order_t *order, char *item_name, int quantity) {
    order->quantity += quantity;
    order->total_amount += quantity * atoi(item_name);
}

// Function to print the contents of a customer's order
void print_order(order_t *order) {
    printf("Customer: %s\n", order->customer_name);
    printf("Items: \n");
    for (int i = 0; i < order->quantity; i++) {
        printf("  - %s x %d = %d\n", order->item_name, order->quantity, order->total_amount);
    }
}

int main() {
    // Create a list of customers
    customer_t *customers[MAX_CUSTOMERS];
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        customers[i] = create_customer("Customer", "Address", 123456);
    }

    // Create a list of orders
    order_t *orders[MAX_ORDERS];
    for (int i = 0; i < MAX_ORDERS; i++) {
        orders[i] = create_order("Customer", "Item", 2, 100);
    }

    // Add items to orders
    for (int i = 0; i < MAX_ORDERS; i++) {
        add_item_to_order(orders[i], "Item 1", 3);
        add_item_to_order(orders[i], "Item 2", 2);
    }

    // Print the contents of each order
    for (int i = 0; i < MAX_ORDERS; i++) {
        print_order(orders[i]);
    }

    return 0;
}