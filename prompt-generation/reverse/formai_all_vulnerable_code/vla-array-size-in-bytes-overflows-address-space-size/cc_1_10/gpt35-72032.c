//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: future-proof
#include <stdio.h>
#include <string.h>

// Struct for menu items
struct MenuItem {
    int itemId;
    char name[50];
    float price;
};

// Array of menu items
struct MenuItem menuItems[] = {
    {1, "Coffee", 2.50},
    {2, "Tea", 2.00},
    {3, "Sandwich", 4.50},
    {4, "Cake", 3.50},
    {5, "Smoothie", 5.00}
};

// Function to display menu
void displayMenu() {
    printf("Menu:\n");
    printf("ID \t ITEM \t\t\t\tPRICE\n");
    for(int i = 0; i < sizeof(menuItems) / sizeof(menuItems[0]); i++) {
        printf("%d \t %-20s \t $%.2f\n", menuItems[i].itemId, menuItems[i].name, menuItems[i].price);
    }
}

// Function to calculate bill
float calculateBill(int *itemIds, int numItems) {
    float bill = 0;
    for(int i = 0; i < numItems; i++) {
        for(int j = 0; j < sizeof(menuItems) / sizeof(menuItems[0]); j++) {
            if(itemIds[i] == menuItems[j].itemId) {
                bill += menuItems[j].price;
                break;
            }
        }
    }
    return bill;
}

int main() {
    int numItems;
    printf("Welcome to C Cafe!\n\n");
    displayMenu();
    printf("\n");
    printf("Enter the number of items you want to order: ");
    scanf("%d", &numItems);
    int itemIds[numItems];
    printf("Enter the IDs of the items you want to order separated by spaces (e.g. 1 3 5): ");
    for(int i = 0; i < numItems; i++) {
        scanf("%d", &itemIds[i]);
    }
    float bill = calculateBill(itemIds, numItems);
    printf("\nTotal bill: $%.2f\n", bill);
    printf("Thank you for your order!\n");
    return 0;
}