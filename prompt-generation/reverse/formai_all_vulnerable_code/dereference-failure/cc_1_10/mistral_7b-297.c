//MISTRAL-7B DATASET v1.0 Category: Cafe Billing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 50
#define MAX_NAME_LEN 20
#define MAX_QUANTITY 10

typedef struct {
    char name[MAX_NAME_LEN];
    int price;
} Item;

Item items[MAX_ITEMS];
int num_items = 0;

void addItem() {
    if (num_items >= MAX_ITEMS) {
        printf("Error: Maximum number of items reached.\n");
        return;
    }

    printf("Enter item name: ");
    scanf("%s", items[num_items].name);

    printf("Enter item price: ");
    scanf("%d", &items[num_items].price);

    num_items++;
}

void displayMenu() {
    printf("\n********** Café Billing System **********\n");
    printf(" Menu:\n");

    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - %d\n", i+1, items[i].name, items[i].price);
    }
}

void placeOrder() {
    int itemNum, quantity;
    char itemName[MAX_NAME_LEN];

    printf("Enter item number: ");
    scanf("%d", &itemNum);
    itemNum--; // index starts from 0

    strcpy(itemName, items[itemNum].name);

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    int totalPrice = items[itemNum].price * quantity;

    printf("%s: %d x %d = %d\n", itemName, quantity, items[itemNum].price, totalPrice);
}

void calculateBill() {
    int total = 0;

    for (int i = 0; i < num_items; i++) {
        total += items[i].price;
    }

    printf("\nTotal bill: %d\n", total);
}

void main() {
    int choice;

    while (1) {
        system("clear"); // for linux/macOS
        //system("cls");   // for windows

        printf("********** Café Billing System **********\n");
        printf("1. Add item\n");
        printf("2. Display menu\n");
        printf("3. Place order\n");
        printf("4. Calculate bill\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addItem(); break;
            case 2: displayMenu(); break;
            case 3: placeOrder(); break;
            case 4: calculateBill(); break;
            case 5: exit(0);
            default: printf("Invalid choice. Try again.\n");
        }

        getchar(); // consume newline character
        getchar(); // consume second newline character
    }
}