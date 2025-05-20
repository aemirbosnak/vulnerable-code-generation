//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the warehouse management system structure
typedef struct Warehouse {
    char item_name[50];
    int item_quantity;
    struct Warehouse* next;
} Warehouse;

// Create a new warehouse item
Warehouse* create_warehouse_item(char* item_name, int item_quantity) {
    Warehouse* new_item = (Warehouse*)malloc(sizeof(Warehouse));
    strcpy(new_item->item_name, item_name);
    new_item->item_quantity = item_quantity;
    new_item->next = NULL;
    return new_item;
}

// Insert a new warehouse item into the list
void insert_warehouse_item(Warehouse* head, char* item_name, int item_quantity) {
    Warehouse* new_item = create_warehouse_item(item_name, item_quantity);
    if (head == NULL) {
        head = new_item;
    } else {
        head->next = new_item;
        head = new_item;
    }
}

// Search for a warehouse item
Warehouse* search_warehouse_item(Warehouse* head, char* item_name) {
    while (head) {
        if (strcmp(head->item_name, item_name) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Update the quantity of a warehouse item
void update_warehouse_item_quantity(Warehouse* item, int new_quantity) {
    item->item_quantity = new_quantity;
}

// Delete a warehouse item
void delete_warehouse_item(Warehouse* head, char* item_name) {
    Warehouse* prev = NULL;
    Warehouse* current = head;

    while (current) {
        if (strcmp(current->item_name, item_name) == 0) {
            if (prev) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }

    return;
}

int main() {
    Warehouse* head = NULL;

    // Insert some warehouse items
    insert_warehouse_item(head, "Book", 10);
    insert_warehouse_item(head, "Pen", 20);
    insert_warehouse_item(head, "Pencil", 30);

    // Search for an item
    Warehouse* item = search_warehouse_item(head, "Pen");

    // Update item quantity
    update_warehouse_item_quantity(item, 15);

    // Delete an item
    delete_warehouse_item(head, "Pencil");

    // Print the items
    for (item = head; item; item = item->next) {
        printf("%s - %d\n", item->item_name, item->item_quantity);
    }

    return 0;
}