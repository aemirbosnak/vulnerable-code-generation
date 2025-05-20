//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
    char name[20];
    int quantity;
    float price;
};

struct warehouse {
    int capacity;
    int inventory_count;
    struct item *inventory;
};

void add_item(struct warehouse *wh, char *name, int quantity, float price) {
    if (wh->capacity - wh->inventory_count <= 1) {
        wh->capacity *= 2;
        wh->inventory = (struct item *)realloc(wh->inventory, wh->capacity * sizeof(struct item));
    }
    struct item new_item;
    strcpy(new_item.name, name);
    new_item.quantity = quantity;
    new_item.price = price;
    wh->inventory[wh->inventory_count++] = new_item;
}

void remove_item(struct warehouse *wh, char *name) {
    int i;
    for (i = 0; i < wh->inventory_count; i++) {
        if (strcmp(wh->inventory[i].name, name) == 0) {
            int j;
            for (j = i; j < wh->inventory_count - 1; j++) {
                wh->inventory[j] = wh->inventory[j + 1];
            }
            wh->inventory_count--;
            break;
        }
    }
}

void print_inventory(struct warehouse *wh) {
    int i;
    printf("\n%-20s%-20s%-20s\n", "Name", "Quantity", "Price");
    for (i = 0; i < wh->inventory_count; i++) {
        printf("%-20s%-20d%-20.2f\n", wh->inventory[i].name, wh->inventory[i].quantity, wh->inventory[i].price);
    }
}

int main() {
    struct warehouse wh;
    wh.capacity = 1;
    wh.inventory_count = 0;
    wh.inventory = (struct item *)malloc(wh.capacity * sizeof(struct item));

    add_item(&wh, "Widget", 10, 1.99);
    add_item(&wh, "Gizmo", 5, 5.99);
    add_item(&wh, "Thingamabob", 20, 0.99);
    print_inventory(&wh);

    remove_item(&wh, "Gizmo");
    print_inventory(&wh);

    return 0;
}