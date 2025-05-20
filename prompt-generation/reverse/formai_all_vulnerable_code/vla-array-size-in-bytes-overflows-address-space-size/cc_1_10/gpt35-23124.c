//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: light-weight
#include <stdio.h>

struct Item {
    char itemName[30];
    int qty;
    float price;
};

void displayMenu() {
    printf("**********************\n");
    printf("** C CAFE BILLING SYSTEM **\n");
    printf("**********************\n\n");

    printf("Menu:\n");
    printf("1. Tea                  10.00\n");
    printf("2. Coffee               20.00\n");
    printf("3. Sandwich             50.00\n");
    printf("4. Burger               80.00\n");
    printf("5. Pizza               120.00\n");
}

void placeOrder(struct Item arr[], int n) {
    printf("Enter your order:\n");

    for (int i = 0; i < n; i++) {
        printf("%d. Item name:", i+1);
        scanf("%s", arr[i].itemName);
        printf("%d. Quantity:", i+1);
        scanf("%d", &arr[i].qty);
        printf("%d. Price:", i+1);
        scanf("%f", &arr[i].price);
    }
}

void printBill(struct Item arr[], int n) {
    float total = 0;

    printf("\n\n");
    printf("********** C CAFE ***********\n\n");
    printf("Item Name\tQty\tPrice\n");
    printf("---------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%-20s%-10d%.2f\n", arr[i].itemName, arr[i].qty, arr[i].price);
        total += arr[i].qty * arr[i].price;
    }

    printf("---------------------------------------\n");
    printf("Total\t\t\t\t%.2f\n\n", total);
}

int main() {
    displayMenu();

    int n;
    printf("Enter number of items:");
    scanf("%d", &n);

    struct Item items[n];

    placeOrder(items, n);

    printBill(items, n);

    return 0;
}