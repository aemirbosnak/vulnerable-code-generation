//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store medical store data
typedef struct Medicine
{
    char name[20];
    int quantity;
    float price;
    struct Medicine* next;
} Medicine;

// Function to insert a new medicine into the linked list
void insertMedicine(Medicine** head, char* name, int quantity, float price)
{
    Medicine* newMedicine = (Medicine*)malloc(sizeof(Medicine));
    strcpy(newMedicine->name, name);
    newMedicine->quantity = quantity;
    newMedicine->price = price;
    newMedicine->next = NULL;

    if (*head == NULL)
    {
        *head = newMedicine;
    }
    else
    {
        (*head)->next = newMedicine;
    }
}

// Function to search for a medicine in the linked list
Medicine* searchMedicine(Medicine* head, char* name)
{
    while (head)
    {
        if (strcmp(head->name, name) == 0)
        {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

// Function to update the quantity of a medicine in the linked list
void updateQuantity(Medicine* head, char* name, int quantity)
{
    Medicine* medicine = searchMedicine(head, name);

    if (medicine)
    {
        medicine->quantity = quantity;
    }
}

// Function to delete a medicine from the linked list
void deleteMedicine(Medicine* head, char* name)
{
    Medicine* medicine = searchMedicine(head, name);

    if (medicine)
    {
        Medicine* prev = NULL;

        if (medicine == head)
        {
            head = medicine->next;
        }
        else
        {
            prev = head;
            head = head->next;
        }

        free(medicine);
    }
}

// Main function
int main()
{
    Medicine* head = NULL;

    // Insert some medicines
    insertMedicine(&head, "Acetaminophen", 100, 2.0);
    insertMedicine(&head, "Ibuprofen", 50, 3.0);
    insertMedicine(&head, "Tylenol", 75, 1.5);

    // Search for a medicine
    Medicine* medicine = searchMedicine(head, "Tylenol");

    if (medicine)
    {
        printf("Name: %s\n", medicine->name);
        printf("Quantity: %d\n", medicine->quantity);
        printf("Price: %.2f\n", medicine->price);
    }

    // Update the quantity of a medicine
    updateQuantity(head, "Acetaminophen", 150);

    // Search for the updated medicine
    medicine = searchMedicine(head, "Acetaminophen");

    if (medicine)
    {
        printf("Name: %s\n", medicine->name);
        printf("Quantity: %d\n", medicine->quantity);
        printf("Price: %.2f\n", medicine->price);
    }

    // Delete a medicine
    deleteMedicine(head, "Ibuprofen");

    // Search for the deleted medicine
    medicine = searchMedicine(head, "Ibuprofen");

    if (medicine == NULL)
    {
        printf("Medicine not found.\n");
    }

    return 0;
}