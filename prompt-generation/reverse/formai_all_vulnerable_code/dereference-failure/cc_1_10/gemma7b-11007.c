//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Warehouse Management System (WMS) structure
typedef struct wms_node {
    char item_name[50];
    int quantity;
    struct wms_node* next;
} wms_node;

// Function to insert a new item into the WMS
void insert_item(wms_node** head, char* item_name, int quantity) {
    // Allocate memory for the new node
    wms_node* new_node = (wms_node*)malloc(sizeof(wms_node));

    // Copy the item name and quantity into the new node
    strcpy(new_node->item_name, item_name);
    new_node->quantity = quantity;

    // If the head of the list is NULL, make the new node the head
    if (*head == NULL) {
        *head = new_node;
    } else {
        // Traverse the list until the last node is reached
        wms_node* last_node = *head;
        while (last_node->next) {
            last_node = last_node->next;
        }

        // Insert the new node at the end of the list
        last_node->next = new_node;
    }
}

// Function to search for an item in the WMS
wms_node* search_item(wms_node* head, char* item_name) {
    // Traverse the list until the item is found or the end of the list is reached
    while (head) {
        if (strcmp(head->item_name, item_name) == 0) {
            return head;
        } else {
            head = head->next;
        }
    }

    // Item not found
    return NULL;
}

// Function to update the quantity of an item in the WMS
void update_quantity(wms_node* head, char* item_name, int new_quantity) {
    // Search for the item in the WMS
    wms_node* item = search_item(head, item_name);

    // If the item is found, update its quantity
    if (item) {
        item->quantity = new_quantity;
    }
}

// Function to delete an item from the WMS
void delete_item(wms_node* head, char* item_name) {
    // Search for the item in the WMS
    wms_node* item = search_item(head, item_name);

    // If the item is found, delete it from the list
    if (item) {
        // If the item is the first item in the list, update the head of the list
        if (item == head) {
            head = item->next;
        } else {
            // Traverse the list until the item is found or the end of the list is reached
            wms_node* prev_item = NULL;
            wms_node* current_item = head;
            while (current_item) {
                if (strcmp(current_item->item_name, item_name) == 0) {
                    prev_item = current_item;
                    current_item = current_item->next;
                } else {
                    prev_item = current_item;
                    current_item = current_item->next;
                }
            }

            // If the item is found, delete it from the list
            if (prev_item) {
                prev_item->next = item->next;
            }
        }

        // Free the memory allocated for the item
        free(item);
    }
}

int main() {
    // Create a new WMS
    wms_node* head = NULL;

    // Insert some items into the WMS
    insert_item(&head, "Apple", 10);
    insert_item(&head, "Banana", 5);
    insert_item(&head, "Orange", 7);

    // Search for an item in the WMS
    wms_node* item = search_item(head, "Apple");
    if (item) {
        printf("Item: %s, Quantity: %d\n", item->item_name, item->quantity);
    }

    // Update the quantity of an item in the WMS
    update_quantity(head, "Banana", 12);
    item = search_item(head, "Banana");
    if (item) {
        printf("Item: %s, Quantity: %d\n", item->item_name, item->quantity);
    }

    // Delete an item from the WMS
    delete_item(head, "Orange");
    item = search_item(head, "Orange");
    if (item) {
        printf("Item: %s, Quantity: %d\n", item->item_name, item->quantity);
    }

    return 0;
}