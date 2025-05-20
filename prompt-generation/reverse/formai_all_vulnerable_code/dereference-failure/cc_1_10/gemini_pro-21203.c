//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: Romeo and Juliet
// A Cafe Billing System in the Style of Romeo and Juliet

#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
struct MenuItem {
    char *name;
    float price;
};

struct MenuItem menuItems[] = {
    {"Espresso", 2.50},
    {"Latte", 3.00},
    {"Cappuccino", 3.50},
    {"Americano", 2.75},
    {"Mocha", 4.00},
    {"Tea", 2.00},
    {"Hot chocolate", 2.50},
    {"Frappuccino", 4.50},
    {"Smoothie", 5.00},
    {"Juice", 3.50}
};

// Define the order struct
struct Order {
    struct MenuItem *item;
    int quantity;
};

// Define the customer struct
struct Customer {
    char *name;
    struct Order *orders;
    int numOrders;
};

// Create a new customer
struct Customer *newCustomer(char *name) {
    struct Customer *customer = malloc(sizeof(struct Customer));
    customer->name = name;
    customer->orders = NULL;
    customer->numOrders = 0;
    return customer;
}

// Add an order to a customer
void addOrder(struct Customer *customer, struct MenuItem *item, int quantity) {
    customer->orders = realloc(customer->orders, (customer->numOrders + 1) * sizeof(struct Order));
    customer->orders[customer->numOrders].item = item;
    customer->orders[customer->numOrders].quantity = quantity;
    customer->numOrders++;
}

// Calculate the total price of an order
float calculateTotalPrice(struct Customer *customer) {
    float totalPrice = 0;
    for (int i = 0; i < customer->numOrders; i++) {
        totalPrice += customer->orders[i].item->price * customer->orders[i].quantity;
    }
    return totalPrice;
}

// Print the bill
void printBill(struct Customer *customer) {
    printf("Romeo and Juliet Cafe\n");
    printf("---------------------\n");
    printf("Customer: %s\n", customer->name);
    printf("---------------------\n");
    for (int i = 0; i < customer->numOrders; i++) {
        printf("%s x%d: $%.2f\n", customer->orders[i].item->name, customer->orders[i].quantity, customer->orders[i].item->price * customer->orders[i].quantity);
    }
    printf("---------------------\n");
    printf("Total: $%.2f\n", calculateTotalPrice(customer));
}

// Main function
int main() {
    // Create a new customer
    struct Customer *customer = newCustomer("Romeo");

    // Add some orders to the customer
    addOrder(customer, &menuItems[0], 2); // 2 espressos
    addOrder(customer, &menuItems[1], 1); // 1 latte
    addOrder(customer, &menuItems[2], 1); // 1 cappuccino

    // Print the bill
    printBill(customer);

    return 0;
}