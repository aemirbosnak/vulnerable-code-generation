//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store medicine details
struct medicine
{
    char name[20];
    int quantity;
    float price;
};

// Create a linked list to store medicine details
struct node
{
    struct medicine data;
    struct node* next;
};

// Function to insert a node at the end of the linked list
void insertAtEnd(struct node** head, struct medicine medicine)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = medicine;
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

// Function to search for a medicine in the linked list
struct medicine* searchMedicine(struct node* head, char* name)
{
    while (head)
    {
        if (strcmp(head->data.name, name) == 0)
        {
            return &head->data;
        }
        head = head->next;
    }

    return NULL;
}

// Function to update the quantity of a medicine in the linked list
void updateQuantity(struct node* head, char* name, int quantity)
{
    struct medicine* medicine = searchMedicine(head, name);

    if (medicine)
    {
        medicine->quantity = quantity;
    }
}

// Function to remove a medicine from the linked list
void removeMedicine(struct node* head, char* name)
{
    struct node* previous = NULL;
    struct node* current = head;

    while (current)
    {
        if (strcmp(current->data.name, name) == 0)
        {
            if (previous)
            {
                previous->next = current->next;
            }
            else
            {
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

// Main function
int main()
{
    struct node* head = NULL;

    // Insert some medicines into the linked list
    insertAtEnd(&head, (struct medicine){"Acetaminophen", 100, 20.0});
    insertAtEnd(&head, (struct medicine){"Ibuprofen", 50, 15.0});
    insertAtEnd(&head, (struct medicine){"Tylenol", 75, 25.0});

    // Search for a medicine
    struct medicine* medicine = searchMedicine(head, "Acetaminophen");

    if (medicine)
    {
        printf("Name: %s\n", medicine->name);
        printf("Quantity: %d\n", medicine->quantity);
        printf("Price: %.2f\n", medicine->price);
    }

    // Update the quantity of a medicine
    updateQuantity(head, "Ibuprofen", 60);

    // Search for the updated medicine
    medicine = searchMedicine(head, "Ibuprofen");

    if (medicine)
    {
        printf("Name: %s\n", medicine->name);
        printf("Quantity: %d\n", medicine->quantity);
        printf("Price: %.2f\n", medicine->price);
    }

    // Remove a medicine
    removeMedicine(head, "Tylenol");

    // Search for the removed medicine
    medicine = searchMedicine(head, "Tylenol");

    if (medicine)
    {
        printf("Error: Medicine not found.\n");
    }

    return 0;
}