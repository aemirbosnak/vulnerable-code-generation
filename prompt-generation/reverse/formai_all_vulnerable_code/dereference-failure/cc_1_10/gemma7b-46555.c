//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item {
    char name[20];
    float price;
    int quantity;
} Item;

void displayMenu(Item items[]) {
    printf("Items:\n");
    for (int i = 0; items[i].name[0] != '\0'; i++) {
        printf("%s - %.2f (Q: %d)\n", items[i].name, items[i].price, items[i].quantity);
    }
}

void calculateTotal(Item items[], int numItems, float *total) {
    *total = 0;
    for (int i = 0; items[i].name[0] != '\0'; i++) {
        *total += items[i].price * items[i].quantity;
    }
}

int main() {
    Item items[] = {
        {"Coffee", 5.0, 10},
        {"Tea", 3.0, 5},
        {"Juice", 2.0, 20},
        {"Biscuits", 1.5, 15}
    };

    displayMenu(items);

    int orderQuantity[20];
    char orderName[20];

    printf("Enter item name:");
    scanf("%s", orderName);

    printf("Enter order quantity:");
    scanf("%d", &orderQuantity);

    float total = 0;
    calculateTotal(items, 4, &total);

    printf("Total: %.2f", total);

    return 0;
}