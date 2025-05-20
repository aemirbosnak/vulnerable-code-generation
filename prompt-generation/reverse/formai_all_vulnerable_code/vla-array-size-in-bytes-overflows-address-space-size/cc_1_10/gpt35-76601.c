//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char item_name[20];
    int quantity;
    float price_per_unit;
    float total_price;
} Item;

float calculate_total_price(Item *items, int num_items) {
    float total_price = 0;

    for (int i = 0; i < num_items; i++) {
        total_price += items[i].total_price;
    }

    return total_price;
}

void generate_bill(Item *items, int num_items) {
    float total_price = calculate_total_price(items, num_items);

    printf("\n----------------------\n");
    printf("Item\tQty\tPrice\tTotal\n");
    printf("----------------------\n");

    for (int i = 0; i < num_items; i++) {
        printf("%s\t%d\t%.2f\t%.2f\n", 
               items[i].item_name, items[i].quantity,
               items[i].price_per_unit, items[i].total_price);
    }

    printf("----------------------\n");
    printf("Total Price: %.2f\n", total_price);
    printf("----------------------\n");
}

int main() {
    char name[20];
    int quantity;
    float price_per_unit;

    printf("Welcome to Cafe Billing System!\n");

    printf("Enter the number of items: ");
    int num_items;
    scanf("%d", &num_items);

    Item items[num_items];

    for (int i = 0; i < num_items; i++) {
        printf("Enter item name: ");
        scanf("%s", &name);

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        printf("Enter price per unit: ");
        scanf("%f", &price_per_unit);

        items[i].quantity = quantity;
        items[i].price_per_unit = price_per_unit;
        items[i].total_price = quantity * price_per_unit;
        strcpy(items[i].item_name, name);
    }

    generate_bill(items, num_items);

    return 0;
}