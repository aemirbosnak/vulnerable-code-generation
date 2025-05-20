//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100

typedef struct Item {
    char name[50];
    int quantity;
    float price;
    struct Item* next;
} Item;

typedef struct Warehouse {
    Item* head;
    int items_count;
} Warehouse;

void insert_item(Warehouse* w, char* name, int quantity, float price) {
    Item* new_item = (Item*)malloc(sizeof(Item));
    strcpy(new_item->name, name);
    new_item->quantity = quantity;
    new_item->price = price;
    new_item->next = NULL;

    if (w->head == NULL) {
        w->head = new_item;
    } else {
        w->head->next = new_item;
    }

    w->items_count++;
}

void search_item(Warehouse* w, char* name) {
    Item* current_item = w->head;

    while (current_item) {
        if (strcmp(current_item->name, name) == 0) {
            printf("Item name: %s\n", current_item->name);
            printf("Quantity: %d\n", current_item->quantity);
            printf("Price: %.2f\n", current_item->price);
            return;
        }

        current_item = current_item->next;
    }

    printf("Item not found.\n");
}

int main() {
    Warehouse* w = (Warehouse*)malloc(sizeof(Warehouse));
    w->head = NULL;
    w->items_count = 0;

    insert_item(w, "Apple", 10, 1.20);
    insert_item(w, "Banana", 5, 0.80);
    insert_item(w, "Orange", 7, 0.90);

    search_item(w, "Apple");
    search_item(w, "Banana");
    search_item(w, "Mango");

    return 0;
}