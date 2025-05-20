//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the menu items
typedef struct {
    char name[50];
    float price;
} MenuItem;

MenuItem menuItems[] = {
    {"Cappuccino", 3.50},
    {"Espresso", 2.50},
    {"Latte", 3.00},
    {"Mocha", 3.75},
    {"Tea", 2.00},
    {"Hot Chocolate", 2.75},
    {"Muffin", 1.50},
    {"Scone", 2.00},
    {"Cookie", 1.00},
    {"Brownie", 2.50}
};

// Define the table numbers
int tableNumbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

// Define the order struct
typedef struct {
    int tableNumber;
    MenuItem items[10];
    int itemCount;
    float total;
} Order;

// Get the user's choice
int getChoice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Get the table number
int getTableNumber() {
    int tableNumber;
    printf("Enter the table number: ");
    scanf("%d", &tableNumber);
    return tableNumber;
}

// Add an item to the order
void addItem(Order *order) {
    int itemNumber;
    printf("Enter the item number: ");
    scanf("%d", &itemNumber);
    order->items[order->itemCount++] = menuItems[itemNumber - 1];
}

// Remove an item from the order
void removeItem(Order *order) {
    int itemNumber;
    printf("Enter the item number: ");
    scanf("%d", &itemNumber);
    for (int i = itemNumber - 1; i < order->itemCount; i++) {
        order->items[i] = order->items[i + 1];
    }
    order->itemCount--;
}

// Calculate the total price of the order
void calculateTotal(Order *order) {
    order->total = 0;
    for (int i = 0; i < order->itemCount; i++) {
        order->total += order->items[i].price;
    }
}

// Print the order
void printOrder(Order *order) {
    printf("Table number: %d\n", order->tableNumber);
    printf("Items:\n");
    for (int i = 0; i < order->itemCount; i++) {
        printf("\t%s $%.2f\n", order->items[i].name, order->items[i].price);
    }
    printf("Total: $%.2f\n", order->total);
}

// Main function
int main() {
    // Initialize the order
    Order order;
    order.tableNumber = getTableNumber();
    order.itemCount = 0;
    order.total = 0;

    // Get the user's choice
    int choice;
    while ((choice = getChoice()) != 0) {
        switch (choice) {
            case 1:
                addItem(&order);
                break;
            case 2:
                removeItem(&order);
                break;
            case 3:
                calculateTotal(&order);
                printOrder(&order);
                break;
        }
    }

    return 0;
}