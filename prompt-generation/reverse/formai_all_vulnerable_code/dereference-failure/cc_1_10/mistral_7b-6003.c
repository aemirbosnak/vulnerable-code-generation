//MISTRAL-7B DATASET v1.0 Category: Cafe Billing System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MENU_ITEMS 50
#define MAX_ORDER_ITEMS 10
#define MAX_ORDER_NAME_LENGTH 20

typedef struct {
    char name[MAX_ORDER_NAME_LENGTH];
    int quantity;
} OrderItem;

typedef struct {
    char name[20];
    float price;
} MenuItem;

MenuItem menu[MAX_MENU_ITEMS];
int menuSize = 0;

void addMenuItem(char* name, float price) {
    if (menuSize >= MAX_MENU_ITEMS) {
        printf("Error: Maximum menu items reached!\n");
        return;
    }

    strcpy(menu[menuSize].name, name);
    menu[menuSize].price = price;
    menuSize++;
}

void displayMenu() {
    if (menuSize == 0) {
        printf("Error: No menu items added!\n");
        return;
    }

    printf("\n--- MENU ---\n");
    for (int i = 0; i < menuSize; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

OrderItem orders[MAX_ORDER_ITEMS];
int orderSize = 0;

void placeOrder(int menuItemId, int quantity) {
    if (menuSize == 0) {
        printf("Error: No menu items added!\n");
        return;
    }

    if (orderSize >= MAX_ORDER_ITEMS) {
        printf("Error: Maximum orders reached!\n");
        return;
    }

    strcpy(orders[orderSize].name, menu[menuItemId - 1].name);
    orders[orderSize].quantity = quantity;
    orderSize++;
}

void calculateTotalBill() {
    float totalBill = 0.0;

    for (int i = 0; i < orderSize; i++) {
        totalBill += orders[i].quantity * menu[i].price;
    }

    printf("\n--- RECEIPT ---\n");
    printf("Total Bill: $%.2f\n", totalBill);
}

int main() {
    addMenuItem("Cappuccino", 3.5);
    addMenuItem("Latte", 3.0);
    addMenuItem("Espresso", 2.5);
    addMenuItem("Americano", 2.8);
    addMenuItem("Mocha", 3.8);

    displayMenu();

    int menuItemId, quantity;

    while (1) {
        printf("\nEnter menu item ID and quantity (or 0 to exit): ");
        scanf("%d%d", &menuItemId, &quantity);

        if (menuItemId == 0) {
            break;
        }

        placeOrder(menuItemId, quantity);
    }

    calculateTotalBill();

    return 0;
}