//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of items that can be stored in the store
#define MAX_ITEMS 100

// Define the structure of an item
typedef struct Item
{
    char name[50];
    int quantity;
    float price;
    struct Item* next;
} Item;

// Create a linked list of items
Item* head = NULL;

// Function to add an item to the store
void addItem(char* name, int quantity, float price)
{
    // Allocate memory for the new item
    Item* newNode = (Item*)malloc(sizeof(Item));

    // Copy the item name, quantity, and price into the new item
    strcpy(newNode->name, name);
    newNode->quantity = quantity;
    newNode->price = price;

    // If the head of the list is NULL, make the new item the head
    if (head == NULL)
    {
        head = newNode;
    }
    // Otherwise, traverse the list and insert the new item at the end
    else
    {
        Item* currentItem = head;
        while (currentItem->next != NULL)
        {
            currentItem = currentItem->next;
        }
        currentItem->next = newNode;
    }
}

// Function to remove an item from the store
void removeItem(char* name)
{
    // Traverse the list and find the item to remove
    Item* currentItem = head;
    Item* previousItem = NULL;
    while (currentItem && strcmp(currentItem->name, name) != 0)
    {
        previousItem = currentItem;
        currentItem = currentItem->next;
    }

    // If the item is found, remove it from the list
    if (currentItem)
    {
        // If the item is the head of the list, update the head
        if (previousItem == NULL)
        {
            head = currentItem->next;
        }
        // Otherwise, remove the item from the list
        else
        {
            previousItem->next = currentItem->next;
        }

        // Free the memory allocated for the item
        free(currentItem);
    }
}

// Function to list all items in the store
void listItems()
{
    // Traverse the list of items and print their names
    Item* currentItem = head;
    while (currentItem)
    {
        printf("%s, %d, %.2f\n", currentItem->name, currentItem->quantity, currentItem->price);
        currentItem = currentItem->next;
    }
}

// Function to update the quantity of an item
void updateQuantity(char* name, int quantity)
{
    // Traverse the list of items and find the item to update
    Item* currentItem = head;
    Item* previousItem = NULL;
    while (currentItem && strcmp(currentItem->name, name) != 0)
    {
        previousItem = currentItem;
        currentItem = currentItem->next;
    }

    // If the item is found, update its quantity
    if (currentItem)
    {
        currentItem->quantity = quantity;
    }
}

// Main function
int main()
{
    // Add some items to the store
    addItem("Acetaminophen", 100, 2.00);
    addItem("Ibuprofen", 50, 2.50);
    addItem("Tylenol", 75, 2.25);

    // List all items in the store
    listItems();

    // Remove an item from the store
    removeItem("Ibuprofen");

    // List all items in the store after removal
    listItems();

    // Update the quantity of an item
    updateQuantity("Acetaminophen", 125);

    // List all items in the store after quantity update
    listItems();

    return 0;
}