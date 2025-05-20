//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: paranoid
#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct Item {
    char name[50];
    int quantity;
    double price;
    struct Item* next;
} Item;

Item* head = NULL;

void addItem(char* name, int quantity, double price) {
    Item* newItem = malloc(sizeof(Item));
    strcpy(newItem->name, name);
    newItem->quantity = quantity;
    newItem->price = price;
    newItem->next = head;
    head = newItem;
}

void searchItem(char* name) {
    Item* currentItem = head;
    while (currentItem) {
        if (strcmp(currentItem->name, name) == 0) {
            printf("Item name: %s\n", currentItem->name);
            printf("Quantity: %d\n", currentItem->quantity);
            printf("Price: %.2lf\n", currentItem->price);
            return;
        }
        currentItem = currentItem->next;
    }
    printf("Item not found.\n");
}

void updateItemQuantity(char* name, int newQuantity) {
    Item* currentItem = head;
    while (currentItem) {
        if (strcmp(currentItem->name, name) == 0) {
            currentItem->quantity = newQuantity;
            return;
        }
        currentItem = currentItem->next;
    }
    printf("Item not found.\n");
}

void removeItem(char* name) {
    Item* currentItem = head;
    Item* previousItem = NULL;
    while (currentItem) {
        if (strcmp(currentItem->name, name) == 0) {
            if (previousItem) {
                previousItem->next = currentItem->next;
            } else {
                head = currentItem->next;
            }
            free(currentItem);
            return;
        }
        previousItem = currentItem;
        currentItem = currentItem->next;
    }
    printf("Item not found.\n");
}

int main() {
    addItem("Paracetamol", 10, 2.0);
    addItem("Ibuprofen", 15, 2.5);
    addItem("Tefagen", 20, 3.0);
    addItem("Panadol", 12, 2.2);

    searchItem("Ibuprofen");
    updateItemQuantity("Paracetamol", 15);
    removeItem("Tefagen");

    searchItem("Paracetamol");

    return 0;
}