//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store item information
typedef struct Item {
    char name[20];
    float price;
    int quantity;
} Item;

// Define a function to calculate total cost
float calculateTotalCost(Item item, int quantity) {
    return item.price * quantity;
}

// Define a function to display menu
void displayMenu(Item items[]) {
    int i = 0;
    for (i = 0; items[i].name[0] != '\0'; i++) {
        printf("%s - %.2f (Qty: %d)\n", items[i].name, items[i].price, items[i].quantity);
    }
}

// Define a function to take order
void takeOrder(Item items[]) {
    char itemName[20];
    int quantity;

    printf("Enter item name:");
    scanf("%s", itemName);

    for (int i = 0; items[i].name[0] != '\0'; i++) {
        if (strcmp(itemName, items[i].name) == 0) {
            printf("Enter quantity:");
            scanf("%d", &quantity);

            items[i].quantity += quantity;
            break;
        }
    }

    if (quantity == 0) {
        printf("Item not found.\n");
    }
}

int main() {
    // Create an array of items
    Item items[] = {
        {"Coffee", 2.50, 10},
        {"Tea", 3.00, 5},
        {"Juice", 2.00, 7},
        {"Water", 1.50, 12}
    };

    // Display the menu
    displayMenu(items);

    // Take an order
    takeOrder(items);

    // Calculate the total cost
    float totalCost = calculateTotalCost(items[0], items[0].quantity);

    // Display the total cost
    printf("Total cost: %.2f\n", totalCost);

    return 0;
}