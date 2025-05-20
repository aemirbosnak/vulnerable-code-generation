//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store inventory items
typedef struct Item
{
    char name[50];
    int quantity;
    float price;
} Item;

// Create a linked list to store inventory items
typedef struct Node
{
    Item item;
    struct Node* next;
} Node;

// Function to insert an item into the linked list
void insertItem(Node** head, Item item)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->item = item;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        (*head)->next = newNode;
    }
}

// Function to search for an item in the linked list
Node* searchItem(Node* head, char* name)
{
    while (head)
    {
        if (strcmp(head->item.name, name) == 0)
        {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

// Function to update the quantity of an item in the linked list
void updateQuantity(Node* head, char* name, int quantity)
{
    Node* item = searchItem(head, name);

    if (item)
    {
        item->item.quantity = quantity;
    }
}

// Function to remove an item from the linked list
void removeItem(Node** head, char* name)
{
    Node* item = searchItem(head, name);

    if (item)
    {
        Node* prev = NULL;
        Node* current = *head;

        while (current)
        {
            if (strcmp(current->item.name, name) == 0)
            {
                if (prev)
                {
                    prev->next = current->next;
                }
                else
                {
                    *head = current->next;
                }
                free(current);
            }
            prev = current;
            current = current->next;
        }
    }
}

// Main function
int main()
{
    // Create a linked list to store inventory items
    Node* head = NULL;

    // Insert some items into the linked list
    Item item1 = {"Item 1", 10, 10.0};
    insertItem(&head, item1);

    Item item2 = {"Item 2", 5, 20.0};
    insertItem(&head, item2);

    Item item3 = {"Item 3", 7, 30.0};
    insertItem(&head, item3);

    // Search for an item in the linked list
    Node* item = searchItem(head, "Item 2");

    if (item)
    {
        // Update the quantity of the item
        updateQuantity(head, "Item 2", 12);

        // Remove the item from the linked list
        removeItem(&head, "Item 2");
    }

    // Print the inventory items
    for (item = head; item; item = item->next)
    {
        printf("%s: %d, %f\n", item->item.name, item->item.quantity, item->item.price);
    }

    return 0;
}