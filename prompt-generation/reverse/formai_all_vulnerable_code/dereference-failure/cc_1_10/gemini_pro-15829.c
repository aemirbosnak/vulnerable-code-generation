//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the menu items and their prices
char menu[][20] = {"Coffee", "Tea", "Soda", "Water", "Juice"};
double prices[] = {1.50, 1.25, 1.00, 0.50, 1.25};

// Define the data structure for an order item
typedef struct {
    char name[20];
    double price;
    int quantity;
} order_item;

// Define the data structure for an order
typedef struct {
    order_item items[10];
    int num_items;
    double total_price;
} order;

// Function to print the menu
void print_menu() {
    printf("Menu:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i], prices[i]);
    }
}

// Function to get the user's order
void get_order(order *o) {
    int num_items;
    printf("How many items would you like to order? ");
    scanf("%d", &num_items);

    o->num_items = num_items;

    for (int i = 0; i < num_items; i++) {
        int item_number;
        int quantity;

        printf("Enter the item number: ");
        scanf("%d", &item_number);

        printf("Enter the quantity: ");
        scanf("%d", &quantity);

        strcpy(o->items[i].name, menu[item_number - 1]);
        o->items[i].price = prices[item_number - 1];
        o->items[i].quantity = quantity;
    }
}

// Function to calculate the total price of an order
double calculate_total_price(order *o) {
    double total_price = 0;
    for (int i = 0; i < o->num_items; i++) {
        total_price += o->items[i].price * o->items[i].quantity;
    }
    return total_price;
}

// Function to print an order
void print_order(order *o) {
    printf("Order:\n");
    for (int i = 0; i < o->num_items; i++) {
        printf("%s x %d - $%.2f\n", o->items[i].name, o->items[i].quantity, o->items[i].price * o->items[i].quantity);
    }
    printf("Total: $%.2f\n", o->total_price);
}

// Main function
int main() {
    // Create an order
    order o;

    // Get the user's order
    get_order(&o);

    // Calculate the total price of the order
    o.total_price = calculate_total_price(&o);

    // Print the order
    print_order(&o);

    return 0;
}