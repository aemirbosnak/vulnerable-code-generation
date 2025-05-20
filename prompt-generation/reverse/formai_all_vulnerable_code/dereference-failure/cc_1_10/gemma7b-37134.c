//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store medical store items
typedef struct Item
{
    char name[20];
    int quantity;
    float price;
} Item;

// Create a linked list of medical store items
typedef struct Node
{
    Item item;
    struct Node* next;
} Node;

// Function to insert a new item into the linked list
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
            return;
        }
        prev = current;
        current = current->next;
    }

    return;
}

int main()
{
    // Create a linked list of medical store items
    Node* head = NULL;

    // Insert some items into the linked list
    Item item1 = {"Paracetamol", 100, 20.0};
    insertItem(&head, item1);

    Item item2 = {"Ibuprofen", 50, 15.0};
    insertItem(&head, item2);

    Item item3 = {"Tylenol", 75, 12.0};
    insertItem(&head, item3);

    // Search for an item in the linked list
    Node* item = searchItem(head, "Paracetamol");

    if (item)
    {
        printf("Item name: %s\n", item->item.name);
        printf("Item quantity: %d\n", item->item.quantity);
        printf("Item price: %.2f\n", item->item.price);
    }

    // Update the quantity of an item in the linked list
    updateQuantity(head, "Ibuprofen", 10);

    item = searchItem(head, "Ibuprofen");

    if (item)
    {
        printf("Updated item name: %s\n", item->item.name);
        printf("Updated item quantity: %d\n", item->item.quantity);
    }

    // Remove an item from the linked list
    removeItem(&head, "Tylenol");

    item = searchItem(head, "Tylenol");

    if (item == NULL)
    {
        printf("Item not found\n");
    }

    return 0;
}