//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store medical store data
typedef struct Medicine
{
    char name[50];
    int quantity;
    float price;
} Medicine;

// Create a linked list to store medicines
typedef struct Node
{
    Medicine data;
    struct Node* next;
} Node;

// Function to insert a medicine into the linked list
void insertMedicine(Node** head, Medicine medicine)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
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
Medicine* searchMedicine(Node* head, char* name)
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
void updateQuantity(Node* head, char* name, int quantity)
{
    Medicine* medicine = searchMedicine(head, name);

    if (medicine)
    {
        medicine->quantity = quantity;
    }
}

// Function to delete a medicine from the linked list
void deleteMedicine(Node* head, char* name)
{
    Medicine* medicine = searchMedicine(head, name);

    if (medicine)
    {
        Node* prev = NULL;
        Node* current = head;

        while (current)
        {
            if (strcmp(current->data.name, name) == 0)
            {
                if (prev)
                {
                    prev->next = current->next;
                }
                else
                {
                    head = current->next;
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
    // Create a linked list of medicines
    Node* head = NULL;

    // Insert some medicines into the linked list
    insertMedicine(&head, (Medicine){"Acetaminophen", 100, 50.0});
    insertMedicine(&head, (Medicine){"Ibuprofen", 50, 60.0});
    insertMedicine(&head, (Medicine){"Aspirin", 75, 40.0});

    // Search for a medicine in the linked list
    Medicine* medicine = searchMedicine(head, "Acetaminophen");

    if (medicine)
    {
        // Print the name, quantity, and price of the medicine
        printf("Name: %s\n", medicine->name);
        printf("Quantity: %d\n", medicine->quantity);
        printf("Price: %.2f\n", medicine->price);
    }

    // Update the quantity of a medicine in the linked list
    updateQuantity(head, "Ibuprofen", 100);

    // Search for the updated medicine in the linked list
    medicine = searchMedicine(head, "Ibuprofen");

    if (medicine)
    {
        // Print the name, quantity, and price of the updated medicine
        printf("Name: %s\n", medicine->name);
        printf("Quantity: %d\n", medicine->quantity);
        printf("Price: %.2f\n", medicine->price);
    }

    // Delete a medicine from the linked list
    deleteMedicine(head, "Aspirin");

    // Search for the deleted medicine in the linked list
    medicine = searchMedicine(head, "Aspirin");

    if (medicine)
    {
        // Print an error message
        printf("Error: Medicine not found.\n");
    }

    return 0;
}