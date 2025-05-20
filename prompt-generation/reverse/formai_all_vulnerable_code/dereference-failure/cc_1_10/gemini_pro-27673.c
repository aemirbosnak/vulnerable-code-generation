//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the menu items
struct menu_item {
    char name[50];
    float price;
};

// Define the order struct
struct order {
    struct menu_item item;
    int quantity;
};

// Define the billing system
struct billing_system {
    struct order *orders;
    int num_orders;
    float total_bill;
};

// Function to create a new menu item
struct menu_item *create_menu_item(char *name, float price) {
    struct menu_item *item = malloc(sizeof(struct menu_item));
    strcpy(item->name, name);
    item->price = price;
    return item;
}

// Function to create a new order
struct order *create_order(struct menu_item *item, int quantity) {
    struct order *order = malloc(sizeof(struct order));
    order->item = *item;
    order->quantity = quantity;
    return order;
}

// Function to create a new billing system
struct billing_system *create_billing_system() {
    struct billing_system *system = malloc(sizeof(struct billing_system));
    system->orders = NULL;
    system->num_orders = 0;
    system->total_bill = 0.0;
    return system;
}

// Function to add a new order to the billing system
void add_order(struct billing_system *system, struct order *order) {
    system->orders = realloc(system->orders, (system->num_orders + 1) * sizeof(struct order));
    system->orders[system->num_orders] = *order;
    system->num_orders++;
    system->total_bill += order->item.price * order->quantity;
}

// Function to print the billing system
void print_billing_system(struct billing_system *system) {
    printf("Your order: \n");
    for (int i = 0; i < system->num_orders; i++) {
        printf("%s x %d: $%.2f\n", 
            system->orders[i].item.name, 
            system->orders[i].quantity, 
            system->orders[i].item.price * system->orders[i].quantity);
    }
    printf("Total bill: $%.2f\n", system->total_bill);
}

// Function to free the memory allocated by the billing system
void free_billing_system(struct billing_system *system) {
    free(system->orders);
    free(system);
}

int main() {
    // Create a new billing system
    struct billing_system *system = create_billing_system();

    // Create a menu of items
    struct menu_item *coffee = create_menu_item("Coffee", 2.50);
    struct menu_item *tea = create_menu_item("Tea", 1.50);
    struct menu_item *cake = create_menu_item("Cake", 3.00);

    // Create an order
    struct order *order1 = create_order(coffee, 2);
    struct order *order2 = create_order(tea, 1);
    struct order *order3 = create_order(cake, 1);

    // Add the orders to the billing system
    add_order(system, order1);
    add_order(system, order2);
    add_order(system, order3);

    // Print the billing system
    print_billing_system(system);

    // Free the memory allocated by the billing system
    free_billing_system(system);

    return 0;
}