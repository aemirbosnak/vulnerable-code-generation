//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store item information
typedef struct Item {
    char name[50];
    float price;
    int quantity;
} Item;

// Function to calculate the total cost of an item
float calculateTotalCost(Item item) {
    return item.price * item.quantity;
}

// Function to display the menu
void displayMenu(Item items[]) {
    printf("----------------------------------------\n");
    printf("   MENU\n");
    printf("----------------------------------------\n");
    for (int i = 0; items[i].name[0] != '\0'; i++) {
        printf("%s - %.2f (Qty: %d)\n", items[i].name, items[i].price, items[i].quantity);
    }
    printf("----------------------------------------\n");
}

// Function to take an order
void takeOrder(Item items[]) {
    char itemName[50];
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

// Function to generate the bill
void generateBill(Item items[]) {
    printf("----------------------------------------\n");
    printf("BILL\n");
    printf("----------------------------------------\n");
    for (int i = 0; items[i].name[0] != '\0'; i++) {
        printf("%s - %.2f (Qty: %d)\n", items[i].name, items[i].price, items[i].quantity);
    }
    printf("----------------------------------------\n");
    printf("Total Cost: %.2f\n", calculateTotalCost(items[0]));
    printf("Thank you for your order.\n");
}

int main() {
    Item items[] = {
        {"Coffee", 2.50, 10},
        {"Tea", 3.00, 5},
        {"Juice", 2.00, 7},
        {"Water", 1.50, 12}
    };

    displayMenu(items);
    takeOrder(items);
    generateBill(items);

    return 0;
}