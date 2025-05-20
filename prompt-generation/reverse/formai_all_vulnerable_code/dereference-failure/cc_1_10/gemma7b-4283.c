//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store medical store item information
typedef struct Item
{
    char name[50];
    int quantity;
    float price;
    struct Item* next;
} Item;

// Create a linked list to store medical store items
Item* head = NULL;

// Function to insert a new item into the linked list
void insertItem(char* name, int quantity, float price)
{
    // Allocate memory for the new item
    Item* newNode = (Item*)malloc(sizeof(Item));

    // Copy the item information into the new item
    strcpy(newNode->name, name);
    newNode->quantity = quantity;
    newNode->price = price;

    // If the linked list is empty, make the new item the head
    if (head == NULL)
    {
        head = newNode;
    }
    // Otherwise, insert the new item at the end
    else
    {
        Item* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to search for an item in the linked list
Item* searchItem(char* name)
{
    // Traverse the linked list to find the item
    Item* temp = head;
    while (temp)
    {
        if (strcmp(temp->name, name) == 0)
        {
            return temp;
        }
        temp = temp->next;
    }

    // Item not found
    return NULL;
}

// Function to update the quantity of an item in the linked list
void updateQuantity(char* name, int newQuantity)
{
    // Search for the item in the linked list
    Item* item = searchItem(name);

    // If the item is found, update its quantity
    if (item)
    {
        item->quantity = newQuantity;
    }
}

// Function to delete an item from the linked list
void deleteItem(char* name)
{
    // Search for the item in the linked list
    Item* item = searchItem(name);

    // If the item is found, delete it from the list
    if (item)
    {
        // If the item is the head of the list, update the head
        if (item == head)
        {
            head = item->next;
        }
        // Otherwise, delete the item from the list
        else
        {
            Item* temp = head;
            while (temp->next != item)
            {
                temp = temp->next;
            }
            temp->next = item->next;
        }

        // Free the memory allocated for the item
        free(item);
    }
}

int main()
{
    // Insert some items into the linked list
    insertItem("Acetaminophen", 100, 2.0);
    insertItem("Ibuprofen", 50, 2.5);
    insertItem("Tylenol", 75, 2.2);

    // Search for an item in the linked list
    Item* item = searchItem("Acetaminophen");

    // If the item is found, print its information
    if (item)
    {
        printf("Name: %s\n", item->name);
        printf("Quantity: %d\n", item->quantity);
        printf("Price: %.2f\n", item->price);
    }

    // Update the quantity of an item in the linked list
    updateQuantity("Ibuprofen", 60);

    // Search for the item again and print its updated information
    item = searchItem("Ibuprofen");
    printf("Name: %s\n", item->name);
    printf("Quantity: %d\n", item->quantity);
    printf("Price: %.2f\n", item->price);

    // Delete an item from the linked list
    deleteItem("Tylenol");

    // Search for the item again and print whether it has been deleted
    item = searchItem("Tylenol");
    if (item)
    {
        printf("Item not deleted\n");
    }
    else
    {
        printf("Item deleted\n");
    }

    return 0;
}