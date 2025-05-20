//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WAREHOUSE_SIZE 1000
#define MAX_ITEM_SIZE 100

typedef struct {
    char name[MAX_ITEM_SIZE];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_WAREHOUSE_SIZE];
    int num_items;
} Warehouse;

Warehouse *create_warehouse() {
    Warehouse *w = (Warehouse *) malloc(sizeof(Warehouse));
    w->num_items = 0;
    return w;
}

void destroy_warehouse(Warehouse *w) {
    free(w);
}

void add_item(Warehouse *w, char *name, int quantity, float price) {
    if (w->num_items >= MAX_WAREHOUSE_SIZE) {
        printf("Warehouse is full.\n");
        return;
    }

    Item *i = &w->items[w->num_items];
    strcpy(i->name, name);
    i->quantity = quantity;
    i->price = price;

    w->num_items++;
}

void remove_item(Warehouse *w, char *name) {
    int i;
    for (i = 0; i < w->num_items; i++) {
        if (strcmp(w->items[i].name, name) == 0) {
            w->num_items--;
            break;
        }
    }
}

void print_warehouse(Warehouse *w) {
    int i;
    for (i = 0; i < w->num_items; i++) {
        printf("%s - %d units - $%.2f\n", w->items[i].name, w->items[i].quantity, w->items[i].price);
    }
}

int main() {
    Warehouse *w = create_warehouse();

    add_item(w, "Apples", 100, 0.50);
    add_item(w, "Oranges", 50, 0.75);
    add_item(w, "Bananas", 200, 0.25);

    print_warehouse(w);

    remove_item(w, "Apples");

    print_warehouse(w);

    destroy_warehouse(w);

    return 0;
}