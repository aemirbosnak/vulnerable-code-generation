//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Warehouse Management System (WMS) structure
typedef struct WMS
{
    char item_name[50];
    int quantity;
    struct WMS* next;
} WMS;

// Function to insert a new item into the WMS
void insert_item(WMS** head, char* item_name, int quantity)
{
    // Allocate memory for the new item
    WMS* new_item = (WMS*)malloc(sizeof(WMS));

    // Copy the item name and quantity into the new item
    strcpy(new_item->item_name, item_name);
    new_item->quantity = quantity;

    // If the head of the WMS is NULL, then this is the first item
    if (*head == NULL)
    {
        *head = new_item;
    }
    else
    {
        // Traverse the WMS until the last item is reached
        WMS* current_item = *head;
        while (current_item->next != NULL)
        {
            current_item = current_item->next;
        }

        // Insert the new item after the last item
        current_item->next = new_item;
    }
}

// Function to find an item in the WMS
WMS* find_item(WMS* head, char* item_name)
{
    // Traverse the WMS until the item is found or the end of the list is reached
    while (head != NULL)
    {
        if (strcmp(head->item_name, item_name) == 0)
        {
            return head;
        }
        head = head->next;
    }

    // Item not found
    return NULL;
}

// Main function
int main()
{
    // Create a new WMS
    WMS* head = NULL;

    // Insert items into the WMS
    insert_item(&head, "Apple", 10);
    insert_item(&head, "Banana", 20);
    insert_item(&head, "Orange", 30);

    // Find an item in the WMS
    WMS* item = find_item(head, "Banana");

    // If the item was found, print its name and quantity
    if (item != NULL)
    {
        printf("Item name: %s\n", item->item_name);
        printf("Quantity: %d\n", item->quantity);
    }

    return 0;
}