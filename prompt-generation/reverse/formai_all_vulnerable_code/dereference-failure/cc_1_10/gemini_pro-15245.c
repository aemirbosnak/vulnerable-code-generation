//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// Define the maximum number of items in the order
#define MAX_ITEMS 10

// Define the maximum length of a line in the input file
#define MAX_LINE_LENGTH 100

// Define the menu items and their prices
typedef struct MenuItem {
    char* name;
    float price;
} MenuItem;

const MenuItem menuItems[] = {
    {"Coffee", 2.50},
    {"Tea", 1.50},
    {"Sandwich", 4.00},
    {"Pastry", 2.00},
    {"Soda", 1.00}
};

// Define the order struct
typedef struct Order {
    int numItems;
    MenuItem* items[MAX_ITEMS];
} Order;

// Function to create a new order
Order* createOrder() {
    Order* order = malloc(sizeof(Order));
    if (order == NULL) {
        return NULL;
    }
    order->numItems = 0;
    return order;
}

// Function to add an item to an order
bool addItemToOrder(Order* order, MenuItem* item) {
    if (order->numItems >= MAX_ITEMS) {
        return false;
    }
    order->items[order->numItems++] = item;
    return true;
}

// Function to get the total price of an order
float getTotalPrice(Order* order) {
    float totalPrice = 0.0;
    for (int i = 0; i < order->numItems; i++) {
        totalPrice += order->items[i]->price;
    }
    return totalPrice;
}

// Function to print an order
void printOrder(Order* order) {
    printf("Order:\n");
    for (int i = 0; i < order->numItems; i++) {
        printf("  %s: $%.2f\n", order->items[i]->name, order->items[i]->price);
    }
    printf("Total: $%.2f\n", getTotalPrice(order));
}

// Function to free the memory allocated for an order
void freeOrder(Order* order) {
    for (int i = 0; i < order->numItems; i++) {
        free(order->items[i]);
    }
    free(order);
}

// Function to read orders from a file
void readOrdersFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        // Parse the line and create an order
        Order* order = createOrder();
        char* token = strtok(line, ",");
        while (token != NULL) {
            // Find the menu item corresponding to the token
            MenuItem* item = NULL;
            for (int i = 0; i < sizeof(menuItems) / sizeof(MenuItem); i++) {
                if (strcmp(token, menuItems[i].name) == 0) {
                    item = &menuItems[i];
                    break;
                }
            }

            // If the menu item was not found, print an error message
            if (item == NULL) {
                printf("Error: Invalid menu item: %s\n", token);
            } else {
                // Add the item to the order
                addItemToOrder(order, item);
            }

            // Get the next token
            token = strtok(NULL, ",");
        }

        // Print the order
        printOrder(order);

        // Free the memory allocated for the order
        freeOrder(order);
    }

    fclose(file);
}

int main() {
    // Read orders from the file "orders.txt"
    readOrdersFromFile("orders.txt");

    return 0;
}