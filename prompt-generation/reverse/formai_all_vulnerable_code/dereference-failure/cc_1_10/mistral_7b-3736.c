//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    char name[50];
    int stock;
    float price;
} Item;

typedef struct {
    int id;
    Item *items;
    int size;
    int capacity;
} Inventory;

Inventory inv;

void initInventory() {
    inv.id = 1;
    inv.items = NULL;
    inv.size = 0;
    inv.capacity = 1;
}

void resizeInventory() {
    inv.items = realloc(inv.items, (inv.capacity + 1) * sizeof(Item));
}

void addItem(char *name, int stock, float price) {
    if (inv.size == inv.capacity) {
        resizeInventory();
    }

    strcpy(inv.items[inv.size].name, name);
    inv.items[inv.size].stock = stock;
    inv.items[inv.size].price = price;
    inv.size++;
}

bool searchItem(char *name) {
    for (int i = 0; i < inv.size; i++) {
        if (strcmp(inv.items[i].name, name) == 0) {
            return true;
        }
    }

    return false;
}

void displayInventory() {
    printf("ID\tItem Name\tStock\tPrice\n");

    for (int i = 0; i < inv.size; i++) {
        printf("%d\t%s\t%d\t%.2f\n", inv.id++, inv.items[i].name, inv.items[i].stock, inv.items[i].price);
    }
}

int main() {
    initInventory();

    addItem("Aspirin", 100, 5.00);
    addItem("Paracetamol", 50, 7.50);
    addItem("Ibuprofen", 25, 10.00);

    displayInventory();

    if (searchItem("Aspirin")) {
        printf("\nItem Found!\n");
    } else {
        printf("\nItem Not Found!\n");
    }

    return 0;
}