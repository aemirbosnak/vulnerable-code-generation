//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the menu items and their prices
typedef struct {
    char *name;
    float price;
} MenuItem;

MenuItem menuItems[] = {
    {"Coffee", 2.50},
    {"Tea", 1.50},
    {"Soda", 1.75},
    {"Water", 1.00},
    {"Muffin", 2.00},
    {"Scone", 2.25},
    {"Cookie", 1.50}
};

const int NUM_MENU_ITEMS = sizeof(menuItems) / sizeof(MenuItem);

// Function to print the menu
void printMenu(MenuItem menuItems[], int numMenuItems) {
    printf("Menu:\n");
    for (int i = 0; i < numMenuItems; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menuItems[i].name, menuItems[i].price);
    }
}

// Function to get the user's order
void getOrder(MenuItem menuItems[], int numMenuItems, int *order, int *numItems) {
    // Get the number of items the user wants to order
    printf("How many items would you like to order? ");
    scanf("%d", numItems);

    // Get the items the user wants to order
    for (int i = 0; i < *numItems; i++) {
        printf("Enter the number of the item you want to order: ");
        scanf("%d", &order[i]);
    }
}

// Function to calculate the total cost of the order
float calculateTotal(MenuItem menuItems[], int numMenuItems, int order[], int numItems) {
    float total = 0.0;

    for (int i = 0; i < numItems; i++) {
        total += menuItems[order[i] - 1].price;
    }

    return total;
}

// Function to print the receipt
void printReceipt(MenuItem menuItems[], int numMenuItems, int order[], int numItems, float total) {
    printf("Receipt:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s - $%.2f\n", menuItems[order[i] - 1].name, menuItems[order[i] - 1].price);
    }
    printf("Total: $%.2f\n", total);
}

// Function to run the cafe billing system
void runCafeBillingSystem() {
    // Print the menu
    printMenu(menuItems, NUM_MENU_ITEMS);

    // Get the user's order
    int order[100];
    int numItems;
    getOrder(menuItems, NUM_MENU_ITEMS, order, &numItems);

    // Calculate the total cost of the order
    float total = calculateTotal(menuItems, NUM_MENU_ITEMS, order, numItems);

    // Print the receipt
    printReceipt(menuItems, NUM_MENU_ITEMS, order, numItems, total);
}

// Main function
int main() {
    // Run the cafe billing system
    runCafeBillingSystem();

    return 0;
}