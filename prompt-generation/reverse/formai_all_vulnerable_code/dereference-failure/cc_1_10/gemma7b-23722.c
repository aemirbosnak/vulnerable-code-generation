//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

typedef struct Item {
    char name[20];
    int quantity;
    struct Item* next;
} Item;

Item* head = NULL;

void add_item(char* name, int quantity) {
    Item* new_item = (Item*)malloc(sizeof(Item));
    strcpy(new_item->name, name);
    new_item->quantity = quantity;
    new_item->next = NULL;

    if (head == NULL) {
        head = new_item;
    } else {
        Item* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_item;
    }
}

void print_items() {
    Item* current = head;
    printf("Items:\n");
    while (current) {
        printf("%s - %d\n", current->name, current->quantity);
        current = current->next;
    }
}

void update_quantity(char* name, int new_quantity) {
    Item* current = head;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            current->quantity = new_quantity;
            return;
        }
        current = current->next;
    }
    printf("Item not found.\n");
}

int main() {
    add_item("Bread", 10);
    add_item("Meat", 5);
    add_item("Cheese", 2);
    print_items();

    update_quantity("Meat", 12);
    print_items();

    return 0;
}