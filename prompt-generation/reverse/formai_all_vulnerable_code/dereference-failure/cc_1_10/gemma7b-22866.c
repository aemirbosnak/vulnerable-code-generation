//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a medicine
typedef struct Medicine
{
    char name[50];
    char dosage[50];
    int quantity;
    float price;
} Medicine;

// Create a linked list of medicines
typedef struct MedicineNode
{
    Medicine medicine;
    struct MedicineNode* next;
} MedicineNode;

// Function to insert a medicine into the linked list
void insertMedicine(MedicineNode** head, Medicine medicine)
{
    MedicineNode* newNode = (MedicineNode*)malloc(sizeof(MedicineNode));
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
MedicineNode* searchMedicine(MedicineNode* head, char* name)
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
void updateQuantity(MedicineNode* head, char* name, int quantity)
{
    MedicineNode* medicineNode = searchMedicine(head, name);

    if (medicineNode)
    {
        medicineNode->medicine.quantity = quantity;
    }
}

// Function to delete a medicine from the linked list
void deleteMedicine(MedicineNode** head, char* name)
{
    MedicineNode* medicineNode = searchMedicine(*head, name);

    if (medicineNode)
    {
        MedicineNode* prev = NULL;

        if (medicineNode == *head)
        {
            *head = medicineNode->next;
        }
        else
        {
            prev = *head;

            while (prev->next)
            {
                if (prev->next == medicineNode)
                {
                    prev->next = medicineNode->next;
                    break;
                }
                prev = prev->next;
            }
        }

        free(medicineNode);
    }
}

int main()
{
    // Create a linked list of medicines
    MedicineNode* head = NULL;

    // Insert some medicines into the list
    insertMedicine(&head, (Medicine){.name = "Acetaminophen", .dosage = "500mg", .quantity = 100, .price = 2.5});
    insertMedicine(&head, (Medicine){.name = "Ibuprofen", .dosage = "200mg", .quantity = 50, .price = 3.0});
    insertMedicine(&head, (Medicine){.name = "Tylenol", .dosage = "250mg", .quantity = 75, .price = 2.0});

    // Search for a medicine and update its quantity
    updateQuantity(head, "Acetaminophen", 150);

    // Delete a medicine from the list
    deleteMedicine(&head, "Ibuprofen");

    // Print the list of medicines
    for (MedicineNode* current = head; current; current = current->next)
    {
        printf("%s, %s, %d, %f\n", current->medicine.name, current->medicine.dosage, current->medicine.quantity, current->medicine.price);
    }

    return 0;
}