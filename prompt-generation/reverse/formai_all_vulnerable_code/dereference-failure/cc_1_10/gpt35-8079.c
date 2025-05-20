//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for menu items
typedef struct MenuItem {
    char name[50];
    int price;
    struct MenuItem* next;
} MenuItem;

// Struct for order items
typedef struct OrderItem {
    char name[50];
    int price;
    int quantity;
    struct OrderItem* next;
} OrderItem;

// Function to add a new menu item
void addMenuItem(MenuItem** menuHead) {
    // Create new item
    MenuItem* newItem = malloc(sizeof(MenuItem));
    printf("Enter name of item: ");
    scanf("%s", newItem->name);
    printf("Enter price of item: ");
    scanf("%d", &newItem->price);
    newItem->next = NULL;

    // Add new item to end of menu linked list
    if (*menuHead == NULL) {
        *menuHead = newItem;
    } else {
        MenuItem* curr = *menuHead;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newItem;
    }
    printf("Added new menu item.\n");
}

// Function to print the menu
void printMenu(MenuItem* menuHead) {
    printf("MENU:\n");
    MenuItem* curr = menuHead;
    while (curr != NULL) {
        printf("%-30s%-10d\n", curr->name, curr->price);
        curr = curr->next;
    }
}

// Function to place a new order
void placeOrder(MenuItem* menuHead, OrderItem** orderHead) {
    // Create new order item
    OrderItem* newItem = malloc(sizeof(OrderItem));
    printf("Enter name of item: ");
    scanf("%s", newItem->name);

    // Search for item in menu to get price
    MenuItem* curr = menuHead;
    while (curr != NULL) {
        if (strcmp(newItem->name, curr->name) == 0) {
            newItem->price = curr->price;
            break;
        }
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("Item not found in menu.\n");
        free(newItem);
        return;
    }

    printf("Enter quantity of item: ");
    scanf("%d", &newItem->quantity);
    newItem->next = NULL;

    // Add new order item to end of order linked list
    if (*orderHead == NULL) {
        *orderHead = newItem;
    } else {
        OrderItem* curr = *orderHead;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newItem;
    }
    printf("Added item to order.\n");
}

// Function to print the order
void printOrder(OrderItem* orderHead) {
    printf("ORDER:\n");
    printf("%-30s%-10s%-10s\n", "Name", "Price", "Quantity");
    OrderItem* curr = orderHead;
    while (curr != NULL) {
        printf("%-30s%-10d%-10d\n", curr->name, curr->price, curr->quantity);
        curr = curr->next;
    }
}

// Function to calculate and print the total bill
void printBill(OrderItem* orderHead) {
    int total = 0;
    OrderItem* curr = orderHead;
    while (curr != NULL) {
        total += curr->price * curr->quantity;
        curr = curr->next;
    }
    printf("TOTAL BILL: %d\n", total);
}

int main() {
    MenuItem* menuHead = NULL;
    OrderItem* orderHead = NULL;

    // Main menu loop
    while (1) {
        printf("\n");
        printf("1. Add new item to menu\n");
        printf("2. View menu\n");
        printf("3. Place new order\n");
        printf("4. View order\n");
        printf("5. Print bill\n");
        printf("6. Exit\n");

        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMenuItem(&menuHead);
                break;
            case 2:
                printMenu(menuHead);
                break;
            case 3:
                placeOrder(menuHead, &orderHead);
                break;
            case 4:
                printOrder(orderHead);
                break;
            case 5:
                printBill(orderHead);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}