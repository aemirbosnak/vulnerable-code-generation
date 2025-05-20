//MISTRAL-7B DATASET v1.0 Category: Cafe Billing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#define MAX_ITEMS 10

// Menu structure definition
typedef struct {
    char name[20];
    float price;
} MenuItem;

// Function to initialize menu items
void initMenu(MenuItem menu[]) {
    int i;
    for (i = 0; i < MAX_ITEMS; i++) {
        strcpy(menu[i].name, "Item"); // Set item name
        menu[i].price = i + 1.5; // Set item price based on index
    }
}

// Function to calculate total cost of order
float calculateTotal(MenuItem menu[], int numItems, int items[]) {
    int i;
    float total = 0.0;
    for (i = 0; i < numItems; i++) {
        total += menu[items[i]].price;
    }
    return total;
}

// Function to print menu
void printMenu(MenuItem menu[]) {
    int i;
    printf("\nMENU:\n");
    for (i = 0; i < MAX_ITEMS; i++) {
        printf("%d. %s - %.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

// Function to take user input for items and quantity
void takeOrder(int items[], int numItems) {
    int i, itemNumber;
    for (i = 0; i < numItems; i++) {
        printf("Enter item number %d: ", i + 1);
        scanf("%d", &itemNumber);
        items[i] = itemNumber - 1;
    }
}

// Main function
int main() {
    MenuItem menu[MAX_ITEMS];
    int numItems = 5;
    int items[numItems];

    // Initialize menu
    initMenu(menu);

    // Print menu
    printMenu(menu);

    // Take user input for items and quantity
    takeOrder(items, numItems);

    // Calculate total cost of order
    float total = calculateTotal(menu, numItems, items);

    // Print total cost of order
    printf("\nTotal cost: %.2f\n", total);

    return 0;
}