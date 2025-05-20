//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[50];
    int stock;
    float price;
} Item;

typedef struct {
    int id;
    char description[100];
    Item items[10];
} Shelf;

typedef struct {
    int num_shelves;
    Shelf* shelves;
} Store;

Store* create_store(int num_shelves) {
    Store* store = malloc(sizeof(Store));
    store->num_shelves = num_shelves;
    store->shelves = calloc(num_shelves, sizeof(Shelf));
    return store;
}

void add_item(Shelf* shelf, const char* name, int stock, float price) {
    for (int i = 0; i < 10; i++) {
        if (shelf->items[i].stock == 0) {
            strcpy(shelf->items[i].name, name);
            shelf->items[i].stock = stock;
            shelf->items[i].price = price;
            break;
        }
    }
}

void display_shelf(const Shelf* shelf) {
    printf("\nShelf %d:\n", shelf->id);
    printf("Description: %s\n", shelf->description);
    printf("-------------------\n");
    for (int i = 0; i < 10; i++) {
        if (shelf->items[i].stock > 0) {
            printf("%s: %d @ %0.2f\n", shelf->items[i].name, shelf->items[i].stock, shelf->items[i].price);
        }
    }
}

void manage_store(Store* store) {
    for (int i = 0; i < store->num_shelves; i++) {
        printf("\nShelf %d:\n", store->shelves[i].id);
        printf("Description: %s\n", store->shelves[i].description);
        add_item(&store->shelves[i], "Chrome-coated Bullets", 50, 1.50);
        add_item(&store->shelves[i], "Vibro-knives", 25, 3.99);
        add_item(&store->shelves[i], "Neon Nights Energy Drink", 20, 2.99);
        add_item(&store->shelves[i], "SynthFlesh", 15, 4.50);
        add_item(&store->shelves[i], "Cybernetic Enhancements", 10, 15.99);
        display_shelf(&store->shelves[i]);
    }
}

int main() {
    Store* store = create_store(3);
    manage_store(store);
    free(store->shelves);
    free(store);
    return 0;
}