//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store medical store items
struct item
{
    char name[20];
    int quantity;
    float price;
};

// Create a linked list to store medical store items
struct node
{
    struct item item_data;
    struct node* next;
};

// Function to insert a new item into the linked list
void insert_item(struct node** head, struct item item)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->item_data = item;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        (*head)->next = new_node;
    }
}

// Function to search for an item in the linked list
struct item* search_item(struct node* head, char item_name[])
{
    while (head)
    {
        if (strcmp(item_name, head->item_data.name) == 0)
        {
            return &head->item_data;
        }
        head = head->next;
    }

    return NULL;
}

// Function to update the quantity of an item in the linked list
void update_quantity(struct node* head, char item_name[], int new_quantity)
{
    struct item* item = search_item(head, item_name);

    if (item)
    {
        item->quantity = new_quantity;
    }
}

// Function to delete an item from the linked list
void delete_item(struct node** head, char item_name[])
{
    struct node* prev = NULL;
    struct node* current = *head;

    while (current)
    {
        if (strcmp(item_name, current->item_data.name) == 0)
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
    struct node* head = NULL;

    // Insert some items into the linked list
    struct item item1 = {"Paracetamol", 100, 20.0};
    insert_item(&head, item1);

    struct item item2 = {"Ibuprofen", 50, 15.0};
    insert_item(&head, item2);

    struct item item3 = {"Acetaminophen", 75, 12.0};
    insert_item(&head, item3);

    // Search for an item in the linked list
    struct item* item = search_item(head, "Paracetamol");

    if (item)
    {
        printf("Name: %s\n", item->name);
        printf("Quantity: %d\n", item->quantity);
        printf("Price: %.2f\n", item->price);
    }

    // Update the quantity of an item in the linked list
    update_quantity(head, "Ibuprofen", 75);

    item = search_item(head, "Ibuprofen");

    if (item)
    {
        printf("Name: %s\n", item->name);
        printf("Quantity: %d\n", item->quantity);
        printf("Price: %.2f\n", item->price);
    }

    // Delete an item from the linked list
    delete_item(&head, "Acetaminophen");

    item = search_item(head, "Acetaminophen");

    if (item)
    {
        printf("Name: %s\n", item->name);
        printf("Quantity: %d\n", item->quantity);
        printf("Price: %.2f\n", item->price);
    }

    return 0;
}