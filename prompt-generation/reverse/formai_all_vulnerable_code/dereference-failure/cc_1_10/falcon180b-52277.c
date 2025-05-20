//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_PRICE_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char price[MAX_PRICE_LENGTH];
    int quantity;
    double total_price;
} item_t;

void print_item(item_t* item) {
    printf("%s $%s x %d = $%.2f\n", item->name, item->price, item->quantity, item->total_price);
}

int main() {
    int num_items;
    printf("Enter the number of items you want to track: ");
    scanf("%d", &num_items);

    item_t* items = malloc(num_items * sizeof(item_t));

    int i;
    for (i = 0; i < num_items; i++) {
        printf("Enter item %d:\n", i+1);
        printf("Name: ");
        scanf("%s", items[i].name);

        printf("Price: ");
        scanf("%s", items[i].price);

        printf("Quantity: ");
        scanf("%d", &items[i].quantity);

        items[i].total_price = atof(items[i].price) * items[i].quantity;
    }

    printf("\n");
    printf("Item\tPrice\tQuantity\tTotal Price\n");
    for (i = 0; i < num_items; i++) {
        print_item(&items[i]);
    }

    free(items);
    return 0;
}