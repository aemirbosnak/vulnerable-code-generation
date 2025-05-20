//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 1000
#define MAX_PRICE 100000

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int num_items;
} Store;

Store* create_store() {
    Store* store = malloc(sizeof(Store));
    store->num_items = 0;
    return store;
}

void add_item(Store* store, const char* name, int quantity, float price) {
    if (store->num_items >= MAX_ITEMS) {
        printf("Error: store is full\n");
        return;
    }

    strcpy(store->items[store->num_items].name, name);
    store->items[store->num_items].quantity = quantity;
    store->items[store->num_items].price = price;

    store->num_items++;
}

void remove_item(Store* store, int index) {
    if (index >= 0 && index < store->num_items) {
        store->num_items--;

        for (int i = index; i < store->num_items; i++) {
            strcpy(store->items[i].name, store->items[i + 1].name);
            store->items[i].quantity = store->items[i + 1].quantity;
            store->items[i].price = store->items[i + 1].price;
        }
    } else {
        printf("Error: invalid index\n");
    }
}

void display_items(Store* store) {
    printf("Name\tQuantity\tPrice\n");
    for (int i = 0; i < store->num_items; i++) {
        printf("%s\t%d\t%.2f\n", store->items[i].name, store->items[i].quantity, store->items[i].price);
    }
}

int main() {
    Store* store = create_store();

    add_item(store, "Aspirin", 100, 1.99);
    add_item(store, "Ibuprofen", 200, 2.49);
    add_item(store, "Tylenol", 300, 3.99);

    display_items(store);

    remove_item(store, 1);

    display_items(store);

    return 0;
}