//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Menu items and prices
struct MenuItem {
    char name[30];
    float price;
};

struct MenuItem menuItems[] = {
    {"Coffee", 2.50},
    {"Tea", 1.50},
    {"Juice", 2.00},
    {"Sandwich", 4.00},
    {"Pastry", 3.00}
};

// Get the number of menu items
int numMenuItems = sizeof(menuItems) / sizeof(struct MenuItem);

// Get the user's order
void getOrder(int *order, int numItems) {
    for (int i = 0; i < numItems; i++) {
        printf("Enter the quantity of %s: ", menuItems[i].name);
        scanf("%d", &order[i]);
    }
}

// Calculate the total bill
float calculateBill(int *order, int numItems) {
    float total = 0.0;
    for (int i = 0; i < numItems; i++) {
        total += order[i] * menuItems[i].price;
    }
    return total;
}

// Print the receipt
void printReceipt(int *order, int numItems, float total) {
    printf("==================================================\n");
    printf("                            Cafe Billing System\n");
    printf("==================================================\n");
    for (int i = 0; i < numItems; i++) {
        if (order[i] > 0) {
            printf("%-20s %3d x %5.2f = %5.2f\n",
                   menuItems[i].name, order[i], menuItems[i].price,
                   order[i] * menuItems[i].price);
        }
    }
    printf("--------------------------------------------------\n");
    printf("Total: %5.2f\n", total);
    printf("==================================================\n");
}

// Main function
int main() {
    // Get the number of items ordered
    int numItems;
    printf("Enter the number of items ordered: ");
    scanf("%d", &numItems);

    // Get the user's order
    int order[numItems];
    getOrder(order, numItems);

    // Calculate the total bill
    float total = calculateBill(order, numItems);

    // Print the receipt
    printReceipt(order, numItems, total);

    return 0;
}