//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store warehouse item information
typedef struct Item {
    char item_name[50];
    int quantity;
    double price;
    struct Item* next;
} Item;

// Function to insert a new item into the warehouse
void insert_item(Item* head, char* item_name, int quantity, double price) {
    Item* new_item = (Item*)malloc(sizeof(Item));
    strcpy(new_item->item_name, item_name);
    new_item->quantity = quantity;
    new_item->price = price;
    new_item->next = NULL;

    if (head == NULL) {
        head = new_item;
    } else {
        Item* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_item;
    }
}

// Function to search for an item in the warehouse
Item* search_item(Item* head, char* item_name) {
    Item* temp = head;
    while (temp) {
        if (strcmp(temp->item_name, item_name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to update the quantity of an item in the warehouse
void update_quantity(Item* head, char* item_name, int new_quantity) {
    Item* item = search_item(head, item_name);
    if (item) {
        item->quantity = new_quantity;
    }
}

// Function to delete an item from the warehouse
void delete_item(Item* head, char* item_name) {
    Item* item = search_item(head, item_name);
    if (item) {
        Item* prev = NULL;
        Item* temp = head;
        while (temp) {
            if (strcmp(temp->item_name, item_name) == 0) {
                if (prev) {
                    prev->next = temp->next;
                } else {
                    head = temp->next;
                }
                free(item);
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }
}

// Main function
int main() {
    Item* head = NULL;
    insert_item(head, "Item 1", 10, 10.0);
    insert_item(head, "Item 2", 20, 20.0);
    insert_item(head, "Item 3", 30, 30.0);

    Item* item = search_item(head, "Item 2");
    if (item) {
        printf("Item name: %s\n", item->item_name);
        printf("Quantity: %d\n", item->quantity);
        printf("Price: %.2lf\n", item->price);
    }

    update_quantity(head, "Item 1", 15);
    item = search_item(head, "Item 1");
    if (item) {
        printf("Updated quantity: %d\n", item->quantity);
    }

    delete_item(head, "Item 3");
    item = search_item(head, "Item 3");
    if (item == NULL) {
        printf("Item 3 deleted successfully\n");
    }

    return 0;
}