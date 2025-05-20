//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the menu items and their prices
typedef struct menu_item {
    char name[20];
    float price;
} menu_item;

menu_item menu[] = {
    {"Coffee", 1.50},
    {"Tea", 1.25},
    {"Soda", 1.75},
    {"Juice", 2.00},
    {"Pastry", 2.50}
};

// Define the order structure
typedef struct order {
    char name[20];
    int quantity;
    float price;
} order;

// Define the billing structure
typedef struct billing {
    char name[20];
    float total;
    order orders[10];
    int num_orders;
} billing;

// Function to create a new order
order* create_order(char* name, int quantity, float price) {
    order* new_order = malloc(sizeof(order));
    strcpy(new_order->name, name);
    new_order->quantity = quantity;
    new_order->price = price;
    return new_order;
}

// Function to add an order to a billing
void add_order(billing* bill, order* new_order) {
    bill->orders[bill->num_orders] = *new_order;
    bill->num_orders++;
    bill->total += new_order->price * new_order->quantity;
}

// Function to print the billing
void print_billing(billing* bill) {
    printf("Customer Name: %s", bill->name);
    printf("Total: %f", bill->total);
    for (int i = 0; i < bill->num_orders; i++) {
        printf("\n\t%s x %d = %f", bill->orders[i].name, bill->orders[i].quantity, bill->orders[i].price * bill->orders[i].quantity);
    }
}

// Main function
int main() {
    // Create a new billing
    billing bill;
    strcpy(bill.name, "John Doe");
    bill.total = 0.0;
    bill.num_orders = 0;

    // Add orders to the billing
    add_order(&bill, create_order("Coffee", 2, 1.50));
    add_order(&bill, create_order("Tea", 1, 1.25));
    add_order(&bill, create_order("Juice", 1, 2.00));

    // Print the billing
    print_billing(&bill);

    return 0;
}