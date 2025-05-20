//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

struct Item {
    char name[50];
    float price;
    int quantity;
};

void displayMenu(struct Item items[]) {
    for (int i = 0; items[i].name[0] != '\0'; i++) {
        printf("%s - %.2f (Qty: %d)\n", items[i].name, items[i].price, items[i].quantity);
    }
}

int calculateTotal(struct Item items[], int numItems) {
    int total = 0;
    for (int i = 0; items[i].name[0] != '\0'; i++) {
        total += items[i].price * items[i].quantity;
    }
    return total;
}

int main() {
    struct Item items[] = {
        {"Coffee", 50.0, 10},
        {"Tea", 30.0, 5},
        {"Juice", 20.0, 7},
        {"Soda", 15.0, 2}
    };

    displayMenu(items);

    int numItems = 0;
    char itemName[50];
    float itemPrice;
    int itemQuantity;

    printf("Enter item name: ");
    scanf("%s", itemName);

    for (int i = 0; items[i].name[0] != '\0'; i++) {
        if (strcmp(itemName, items[i].name) == 0) {
            numItems++;
            itemPrice = items[i].price;
            itemQuantity = items[i].quantity;
        }
    }

    if (numItems == 0) {
        printf("Item not found.\n");
    } else {
        printf("Item found. Price: %.2f, Quantity: %d\n", itemPrice, itemQuantity);
        float totalAmount = itemPrice * itemQuantity;
        printf("Total amount: %.2f\n", totalAmount);
    }

    return 0;
}