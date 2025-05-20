//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SItem {
    char *name;
    int units;
    float price;
};

typedef struct SItem Item;

Item *items;
int numItems;

void addItem(char *name, int units, float price) {
    items = (Item *)realloc(items, (numItems + 1) * sizeof(Item));
    strcpy(items[numItems].name, name);
    items[numItems].units = units;
    items[numItems].price = price;
    numItems++;
}

void printBill() {
    int i;
    float total = 0;

    printf("\n\n\n\n   Post-Apocalyptic Cafe Billing System\n\n");
    printf("---------------------------------------------------------------------------\n");
    printf("Item             Units  Price   Amount\n");
    printf("---------------------------------------------------------------------------\n");
    for (i = 0; i < numItems; i++) {
        printf("%-16s %d  %.2f  %.2f\n", items[i].name, items[i].units, items[i].price, items[i].units * items[i].price);
        total += items[i].units * items[i].price;
    }
    printf("---------------------------------------------------------------------------\n");
    printf("Total:                                    %.2f\n", total);
    printf("---------------------------------------------------------------------------\n");
    printf("\nThank you for your patronage! Come again soon!\n\n\n\n");
}

int main() {
    addItem("Radroach Meat Stew", 2, 10.0);
    addItem("Bottle of Purified Water", 1, 5.0);
    addItem("Stimpack", 1, 20.0);
    addItem("Fusion Core", 1, 50.0);

    printBill();

    free(items);

    return 0;
}