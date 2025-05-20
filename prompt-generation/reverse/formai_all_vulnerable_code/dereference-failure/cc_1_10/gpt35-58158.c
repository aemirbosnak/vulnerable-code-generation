//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: peaceful
#include <stdio.h>

struct Item {
    int id;
    char name[50];
    int quantity;
    float pricePerUnit;
    struct Item *next;
};

struct Warehouse {
    struct Item *head;
    int numItems;
    float totalRevenue;
};

void addItem(struct Warehouse *wh, int id, char name[], int quantity, float pricePerUnit) {
    // Check if item already exists
    struct Item *temp = wh->head;
    while (temp != NULL) {
        if (temp->id == id) {
            // Item already exists, update quantity and price
            temp->quantity += quantity;
            temp->pricePerUnit = pricePerUnit;
            printf("Item already exists in the warehouse, quantity updated.\n");
            return;
        }
        temp = temp->next;
    }
    // Item does not exist, create new item
    struct Item *newItem = (struct Item*) malloc(sizeof(struct Item));
    newItem->id = id;
    strcpy(newItem->name, name);
    newItem->quantity = quantity;
    newItem->pricePerUnit = pricePerUnit;
    newItem->next = wh->head;
    wh->head = newItem;
    wh->numItems++;
    printf("Item added to the warehouse.\n");
}

void removeItem(struct Warehouse *wh, int id) {
    // Check if item exists
    struct Item *temp = wh->head;
    struct Item *prev = NULL;
    while (temp != NULL) {
        if (temp->id == id) {
            // Item found, remove from warehouse
            if (prev == NULL) {
                wh->head = temp->next;
            } else {
                prev->next = temp->next;
            }
            wh->numItems--;
            free(temp);
            printf("Item removed from the warehouse.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Item not found in the warehouse.\n");
}

void displayWarehouse(struct Warehouse wh) {
    printf("Total number of items in warehouse: %d\n", wh.numItems);
    printf("Total revenue generated: $%.2f\n", wh.totalRevenue);
    printf("Items in the warehouse:\n");
    struct Item *temp = wh.head;
    while (temp != NULL) {
        printf("ID: %d\n", temp->id);
        printf("Name: %s\n", temp->name);
        printf("Quantity: %d\n", temp->quantity);
        printf("Price per unit: $%.2f\n", temp->pricePerUnit);
        printf("-----------------\n");
        temp = temp->next;
    }
}

int main() {
    struct Warehouse wh = {NULL, 0, 0};
    addItem(&wh, 1001, "Apple", 50, 1.5);
    addItem(&wh, 1002, "Banana", 30, 2.0);
    addItem(&wh, 1003, "Orange", 40, 1.75);
    displayWarehouse(wh);
    removeItem(&wh, 1002);
    displayWarehouse(wh);
    return 0;
}