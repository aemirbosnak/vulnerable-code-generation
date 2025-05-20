//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of items in the warehouse
#define MAX_ITEMS 100

// Define the item structure
typedef struct Item {
    char name[20];
    int quantity;
    float price;
    struct Item* next;
} Item;

// Define the warehouse structure
typedef struct Warehouse {
    Item* head;
    Item* tail;
    int items_count;
} Warehouse;

// Function to insert an item into the warehouse
void insert_item(Warehouse* warehouse, Item* item) {
    if (warehouse->head == NULL) {
        warehouse->head = item;
        warehouse->tail = item;
    } else {
        warehouse->tail->next = item;
        warehouse->tail = item;
    }
    warehouse->items_count++;
}

// Function to search for an item in the warehouse
Item* search_item(Warehouse* warehouse, char* name) {
    Item* item = warehouse->head;
    while (item) {
        if (strcmp(item->name, name) == 0) {
            return item;
        }
        item = item->next;
    }
    return NULL;
}

// Function to update the quantity of an item in the warehouse
void update_quantity(Warehouse* warehouse, char* name, int quantity) {
    Item* item = search_item(warehouse, name);
    if (item) {
        item->quantity = quantity;
    }
}

// Function to remove an item from the warehouse
void remove_item(Warehouse* warehouse, char* name) {
    Item* item = search_item(warehouse, name);
    if (item) {
        Item* prev = NULL;
        Item* curr = warehouse->head;
        while (curr) {
            if (strcmp(curr->name, name) == 0) {
                if (prev) {
                    prev->next = curr->next;
                } else {
                    warehouse->head = curr->next;
                }
                warehouse->items_count--;
                free(item);
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
    return;
}

// Main function
int main() {
    // Create a warehouse
    Warehouse* warehouse = malloc(sizeof(Warehouse));
    warehouse->head = NULL;
    warehouse->tail = NULL;
    warehouse->items_count = 0;

    // Insert some items into the warehouse
    Item* item1 = malloc(sizeof(Item));
    strcpy(item1->name, "Item 1");
    item1->quantity = 10;
    item1->price = 10.0;
    insert_item(warehouse, item1);

    Item* item2 = malloc(sizeof(Item));
    strcpy(item2->name, "Item 2");
    item2->quantity = 20;
    item2->price = 20.0;
    insert_item(warehouse, item2);

    Item* item3 = malloc(sizeof(Item));
    strcpy(item3->name, "Item 3");
    item3->quantity = 30;
    item3->price = 30.0;
    insert_item(warehouse, item3);

    // Search for an item in the warehouse
    Item* item = search_item(warehouse, "Item 2");
    if (item) {
        printf("Item name: %s\n", item->name);
        printf("Item quantity: %d\n", item->quantity);
        printf("Item price: %.2f\n", item->price);
    }

    // Update the quantity of an item in the warehouse
    update_quantity(warehouse, "Item 1", 15);
    item = search_item(warehouse, "Item 1");
    if (item) {
        printf("Item name: %s\n", item->name);
        printf("Item quantity: %d\n", item->quantity);
    }

    // Remove an item from the warehouse
    remove_item(warehouse, "Item 3");
    item = search_item(warehouse, "Item 3");
    if (item) {
        printf("Item name: %s\n", item->name);
        printf("Item quantity: %d\n", item->quantity);
    }

    return 0;
}