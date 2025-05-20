//MISTRAL-7B DATASET v1.0 Category: Cafe Billing System ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

void addItem(Item **items, int *numItems, const char *name, int qty, float price) {
    Item *newItem = (Item *)malloc(sizeof(Item));
    strcpy(newItem->name, name);
    newItem->quantity = qty;
    newItem->price = price;

    if (*numItems == 0) {
        *items = newItem;
    } else {
        Item *lastItem = (*items + (*numItems - 1));
        lastItem->quantity += qty;
    }

    (*numItems)++;
}

void printBill(Item *items, int numItems) {
    printf("-----------------------------------------\n");
    printf("| Item            | Quantity | Price  |\n");
    printf("-----------------------------------------\n");

    float total = 0.0f;
    for (int i = 0; i < numItems; ++i) {
        printf("| %-15s | %-10d | %.2f |\n", items[i].name, items[i].quantity, items[i].price);
        total += items[i].quantity * items[i].price;
    }

    printf("-----------------------------------------\n");
    printf("| Total            | %-10d | %.2f |\n", numItems, total);
}

int main() {
    Item *items = NULL;
    int numItems = 0;

    addItem(&items, &numItems, "Cappuccino", 3, 2.5f);
    addItem(&items, &numItems, "Latte", 2, 3.0f);
    addItem(&items, &numItems, "Americano", 1, 1.8f);

    printBill(items, numItems);

    for (int i = 0; i < numItems; ++i) {
        free(items + i);
    }
    free(items);

    return 0;
}