//FormAI DATASET v1.0 Category: Product Inventory System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct inventory {
    char name[20];
    int quantity;
    float price;
    struct inventory *next;
} inventory_t;

inventory_t *head = NULL;
inventory_t *curr = NULL;

inventory_t* create_inventory(char *name, int quantity, float price) {
    inventory_t *new_inv = (inventory_t*)malloc(sizeof(inventory_t));
    strncpy(new_inv->name, name, sizeof(new_inv->name));
    new_inv->quantity = quantity;
    new_inv->price = price;
    new_inv->next = NULL;
    return new_inv;
}

void insert_inventory(inventory_t *new_inv) {
    if (head == NULL) {
        head = new_inv;
        curr = new_inv;
    } else {
        curr->next = new_inv;
        curr = new_inv;
    }
}

void display_inventory() {
    printf("%-20s%-10s%-10s\n", "Name", "Quantity", "Price");
    printf("-----------------------------------------------\n");
    inventory_t *inv = head;
    while (inv != NULL) {
        printf("%-20s%-10d%-10.2f\n", inv->name, inv->quantity, inv->price);
        inv = inv->next;
    }
}

void search_inventory(char *query) {
    inventory_t *inv = head;
    while (inv != NULL) {
        if (strcmp(inv->name, query) == 0) {
            printf("%-20s%-10d%-10.2f\n", inv->name, inv->quantity, inv->price);
            return;
        }
        inv = inv->next;
    }
    printf("'%s' not found in inventory.\n", query);
}

int main() {
    inventory_t *inv1 = create_inventory("Milk", 10, 2.99);
    insert_inventory(inv1);
    inventory_t *inv2 = create_inventory("Eggs", 20, 0.99);
    insert_inventory(inv2);
    inventory_t *inv3 = create_inventory("Bread", 15, 1.99);
    insert_inventory(inv3);

    display_inventory();

    printf("\nEnter a product name to search for: ");
    char query[20];
    scanf("%s", query);
    search_inventory(query);

    return 0;
}