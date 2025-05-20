//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a medicine
typedef struct Medicine
{
    char name[20];
    char dosage[20];
    int quantity;
    float price;
} Medicine;

// Create a linked list of medicines
struct Node
{
    Medicine medicine;
    struct Node* next;
};

// Function to insert a medicine into the linked list
void insertMedicine(struct Node** head, Medicine medicine)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->medicine = medicine;
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
struct Node* searchMedicine(struct Node* head, char* name)
{
    while (head)
    {
        if (strcmp(head->medicine.name, name) == 0)
        {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

// Function to update the quantity of a medicine in the linked list
void updateQuantity(struct Node* head, char* name, int quantity)
{
    struct Node* node = searchMedicine(head, name);

    if (node)
    {
        node->medicine.quantity = quantity;
    }
}

// Function to delete a medicine from the linked list
void deleteMedicine(struct Node* head, char* name)
{
    struct Node* previousNode = NULL;
    struct Node* node = head;

    while (node)
    {
        if (strcmp(node->medicine.name, name) == 0)
        {
            if (previousNode)
            {
                previousNode->next = node->next;
            }
            else
            {
                head = node->next;
            }
            free(node);
            return;
        }
        previousNode = node;
        node = node->next;
    }

    return;
}

int main()
{
    struct Node* head = NULL;

    // Create a few medicines
    Medicine medicine1 = {"Paracetamol", "500mg", 100, 5.0};
    insertMedicine(&head, medicine1);

    Medicine medicine2 = {"Ibuprofen", "200mg", 50, 7.0};
    insertMedicine(&head, medicine2);

    Medicine medicine3 = {"Acetaminophen", "500mg", 75, 6.0};
    insertMedicine(&head, medicine3);

    // Search for a medicine
    struct Node* node = searchMedicine(head, "Paracetamol");

    if (node)
    {
        printf("Name: %s\n", node->medicine.name);
        printf("Dosage: %s\n", node->medicine.dosage);
        printf("Quantity: %d\n", node->medicine.quantity);
        printf("Price: %.2f\n", node->medicine.price);
    }

    // Update the quantity of a medicine
    updateQuantity(head, "Ibuprofen", 10);

    // Search for the updated medicine
    node = searchMedicine(head, "Ibuprofen");

    if (node)
    {
        printf("Name: %s\n", node->medicine.name);
        printf("Dosage: %s\n", node->medicine.dosage);
        printf("Quantity: %d\n", node->medicine.quantity);
        printf("Price: %.2f\n", node->medicine.price);
    }

    // Delete a medicine
    deleteMedicine(head, "Acetaminophen");

    // Search for the deleted medicine
    node = searchMedicine(head, "Acetaminophen");

    if (node == NULL)
    {
        printf("Medicine not found.\n");
    }

    return 0;
}