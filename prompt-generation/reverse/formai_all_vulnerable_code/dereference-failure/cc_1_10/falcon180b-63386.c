//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_SIZE];
    int size;
} Warehouse;

Warehouse* createWarehouse() {
    Warehouse* w = (Warehouse*)malloc(sizeof(Warehouse));
    w->size = 0;
    return w;
}

void addItem(Warehouse* w, char* name, int quantity, float price) {
    if (w->size >= MAX_SIZE) {
        printf("Warehouse is full.\n");
        return;
    }

    strcpy(w->items[w->size].name, name);
    w->items[w->size].quantity = quantity;
    w->items[w->size].price = price;

    w->size++;
}

void removeItem(Warehouse* w, char* name) {
    int i;

    for (i = 0; i < w->size; i++) {
        if (strcmp(w->items[i].name, name) == 0) {
            w->size--;

            for (int j = i; j < w->size; j++) {
                w->items[j] = w->items[j + 1];
            }

            break;
        }
    }
}

void displayItems(Warehouse* w) {
    printf("Items in the warehouse:\n");

    for (int i = 0; i < w->size; i++) {
        printf("Name: %s\n", w->items[i].name);
        printf("Quantity: %d\n", w->items[i].quantity);
        printf("Price: $%.2f\n\n", w->items[i].price);
    }
}

int main() {
    Warehouse* w = createWarehouse();

    addItem(w, "Apples", 100, 0.50);
    addItem(w, "Oranges", 50, 0.75);
    addItem(w, "Bananas", 25, 0.25);

    displayItems(w);

    removeItem(w, "Apples");

    displayItems(w);

    return 0;
}