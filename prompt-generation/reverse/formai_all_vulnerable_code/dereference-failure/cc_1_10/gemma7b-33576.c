//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store warehouse data
typedef struct WarehouseData
{
    char item_name[50];
    int quantity;
    float price;
    struct WarehouseData* next;
} WarehouseData;

// Create a function to insert a new item into the warehouse
void insertItem(WarehouseData* head)
{
    // Allocate memory for a new item
    WarehouseData* newNode = (WarehouseData*)malloc(sizeof(WarehouseData));

    // Get the item name, quantity, and price from the user
    printf("Enter item name: ");
    scanf("%s", newNode->item_name);

    printf("Enter quantity: ");
    scanf("%d", &newNode->quantity);

    printf("Enter price: ");
    scanf("%f", &newNode->price);

    // Insert the new item into the linked list
    newNode->next = head;
    head = newNode;
}

// Create a function to search for an item in the warehouse
void searchItem(WarehouseData* head)
{
    // Get the item name from the user
    char item_name[50];
    printf("Enter item name: ");
    scanf("%s", item_name);

    // Search for the item in the warehouse
    WarehouseData* currentItem = head;
    while (currentItem)
    {
        if (strcmp(currentItem->item_name, item_name) == 0)
        {
            // Print the item information
            printf("Item name: %s\n", currentItem->item_name);
            printf("Quantity: %d\n", currentItem->quantity);
            printf("Price: %.2f\n", currentItem->price);
            break;
        }
        currentItem = currentItem->next;
    }

    // If the item is not found, print an error message
    if (currentItem == NULL)
    {
        printf("Item not found.\n");
    }
}

// Create a function to update the quantity of an item in the warehouse
void updateQuantity(WarehouseData* head)
{
    // Get the item name from the user
    char item_name[50];
    printf("Enter item name: ");
    scanf("%s", item_name);

    // Search for the item in the warehouse
    WarehouseData* currentItem = head;
    while (currentItem)
    {
        if (strcmp(currentItem->item_name, item_name) == 0)
        {
            // Get the new quantity from the user
            int new_quantity;
            printf("Enter new quantity: ");
            scanf("%d", &new_quantity);

            // Update the item quantity
            currentItem->quantity = new_quantity;

            // Print the updated item information
            printf("Item name: %s\n", currentItem->item_name);
            printf("Quantity: %d\n", currentItem->quantity);
            printf("Price: %.2f\n", currentItem->price);
            break;
        }
        currentItem = currentItem->next;
    }

    // If the item is not found, print an error message
    if (currentItem == NULL)
    {
        printf("Item not found.\n");
    }
}

// Create a function to delete an item from the warehouse
void deleteItem(WarehouseData* head)
{
    // Get the item name from the user
    char item_name[50];
    printf("Enter item name: ");
    scanf("%s", item_name);

    // Search for the item in the warehouse
    WarehouseData* currentItem = head;
    WarehouseData* previousItem = NULL;
    while (currentItem)
    {
        if (strcmp(currentItem->item_name, item_name) == 0)
        {
            // If the item is the first item in the list, update the head of the list
            if (previousItem == NULL)
            {
                head = currentItem->next;
            }
            // Otherwise, update the previous item to point to the next item in the list
            else
            {
                previousItem->next = currentItem->next;
            }

            // Free the memory of the item
            free(currentItem);

            // Print the updated item list
            printf("Item name: %s\n", head->item_name);
            printf("Quantity: %d\n", head->quantity);
            printf("Price: %.2f\n", head->price);
            break;
        }
        previousItem = currentItem;
        currentItem = currentItem->next;
    }

    // If the item is not found, print an error message
    if (currentItem == NULL)
    {
        printf("Item not found.\n");
    }
}

int main()
{
    // Create a linked list to store the warehouse data
    WarehouseData* head = NULL;

    // Insert some items into the warehouse
    insertItem(head);
    insertItem(head);
    insertItem(head);

    // Search for an item in the warehouse
    searchItem(head);

    // Update the quantity of an item in the warehouse
    updateQuantity(head);

    // Delete an item from the warehouse
    deleteItem(head);

    return 0;
}