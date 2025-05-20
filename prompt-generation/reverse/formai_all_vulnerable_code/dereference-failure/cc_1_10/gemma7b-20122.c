//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Define the Inventory Management System (IMS)
struct IMS {
    char item_name[20];
    int item_quantity;
    float item_price;
    struct IMS* next;
};

// Create a linked list of items
struct IMS* head = NULL;

// Function to insert an item into the linked list
void insert_item(char* name, int quantity, float price) {
    struct IMS* new_item = (struct IMS*)malloc(sizeof(struct IMS));

    strcpy(new_item->item_name, name);
    new_item->item_quantity = quantity;
    new_item->item_price = price;

    if (head == NULL) {
        head = new_item;
    } else {
        head->next = new_item;
        head = new_item;
    }
}

// Function to search for an item in the linked list
struct IMS* search_item(char* name) {
    struct IMS* current = head;

    while (current) {
        if (strcmp(current->item_name, name) == 0) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

// Function to update the quantity of an item in the linked list
void update_quantity(char* name, int new_quantity) {
    struct IMS* item = search_item(name);

    if (item) {
        item->item_quantity = new_quantity;
    }
}

// Function to delete an item from the linked list
void delete_item(char* name) {
    struct IMS* current = head;
    struct IMS* previous = NULL;

    while (current) {
        if (strcmp(current->item_name, name) == 0) {
            if (previous) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }

    return;
}

int main() {
    insert_item("Paracetamol", 100, 2.50);
    insert_item("Ibuprofen", 50, 3.00);
    insert_item("Tefagen", 20, 4.00);

    update_quantity("Paracetamol", 150);
    delete_item("Ibuprofen");

    struct IMS* item = search_item("Tefagen");

    if (item) {
        printf("Item name: %s\n", item->item_name);
        printf("Item quantity: %d\n", item->item_quantity);
        printf("Item price: %.2f\n", item->item_price);
    } else {
        printf("Item not found.\n");
    }

    return 0;
}