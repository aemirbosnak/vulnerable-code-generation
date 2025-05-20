//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char* item_name;
    int quantity;
    int price;
} Item;

typedef struct {
    char* warehouse_name;
    Item items[10];
    int item_count;
} Warehouse;

void add_item(Warehouse* w, char* item_name, int quantity, int price) {
    w->item_count++;
    w->items[w->item_count - 1].item_name = malloc(strlen(item_name) + 1);
    strcpy(w->items[w->item_count - 1].item_name, item_name);
    w->items[w->item_count - 1].quantity = quantity;
    w->items[w->item_count - 1].price = price;
}

void print_items(Warehouse* w) {
    printf("Items in Warehouse: %s\n", w->warehouse_name);
    for (int i = 0; i < w->item_count; i++) {
        printf("Item: %s - Quantity: %d - Price: %d\n",
               w->items[i].item_name, w->items[i].quantity, w->items[i].price);
    }
}

int main() {
    Warehouse* w = malloc(sizeof(Warehouse));
    w->item_count = 0;
    w->warehouse_name = malloc(strlen("Default Warehouse") + 1);
    strcpy(w->warehouse_name, "Default Warehouse");
    w->items[0].item_name = malloc(strlen("Item 1") + 1);
    strcpy(w->items[0].item_name, "Item 1");
    w->items[0].quantity = 10;
    w->items[0].price = 5;

    add_item(w, "Item 2", 5, 3);
    add_item(w, "Item 3", 8, 7);

    print_items(w);

    return 0;
}