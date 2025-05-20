//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Product structure
typedef struct {
    char name[50];
    int stock;
    float price;
    struct product* next;
} product;

// Inventory structure
typedef struct {
    product* head;
} inventory;

// Initialize inventory
void init_inventory(inventory* inv) {
    inv->head = NULL;
}

// Add product to inventory
void add_product(inventory* inv, char name[50], int stock, float price) {
    product* new_product = (product*)malloc(sizeof(product));

    strcpy(new_product->name, name);
    new_product->stock = stock;
    new_product->price = price;
    new_product->next = inv->head;

    inv->head = new_product;
}

// Remove product from inventory
void remove_product(inventory* inv, char name[50]) {
    product* current = inv->head;
    product* previous = NULL;

    while (current != NULL && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Product not found.\n");
        return;
    }

    if (previous == NULL) {
        inv->head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
}

// Display inventory
void display_inventory(inventory inv) {
    product* current = inv.head;

    while (current != NULL) {
        printf("%s\tStock: %d\tPrice: %.2f\n", current->name, current->stock, current->price);
        current = current->next;
    }
}

int main() {
    inventory inv;
    init_inventory(&inv);

    add_product(&inv, "Apple", 10, 1.5);
    add_product(&inv, "Banana", 5, 0.8);
    add_product(&inv, "Orange", 15, 1.2);

    printf("Initial inventory:\n");
    display_inventory(inv);

    remove_product(&inv, "Banana");

    printf("\nAfter removing Banana:\n");
    display_inventory(inv);

    return 0;
}