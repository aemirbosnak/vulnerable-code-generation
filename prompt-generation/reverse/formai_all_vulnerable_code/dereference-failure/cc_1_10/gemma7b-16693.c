//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store medical store data
typedef struct MedicalStoreData
{
    char name[50];
    char address[100];
    int phone_number;
    double total_amount;
    struct MedicalStoreData* next;
} MedicalStoreData;

// Function to insert a new node into the linked list
void insertNode(MedicalStoreData** head, char* name, char* address, int phone_number, double total_amount)
{
    MedicalStoreData* newNode = (MedicalStoreData*)malloc(sizeof(MedicalStoreData));
    strcpy(newNode->name, name);
    strcpy(newNode->address, address);
    newNode->phone_number = phone_number;
    newNode->total_amount = total_amount;
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

// Function to search for a node in the linked list
MedicalStoreData* searchNode(MedicalStoreData* head, char* name)
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

int main()
{
    MedicalStoreData* head = NULL;

    // Insert some nodes into the linked list
    insertNode(&head, "John Doe", "123 Main St.", 123456, 100.0);
    insertNode(&head, "Jane Doe", "456 Oak Ave.", 543214, 200.0);
    insertNode(&head, "Peter Pan", "123 Fairy Dust Lane", 984123, 300.0);

    // Search for a node in the linked list
    MedicalStoreData* foundNode = searchNode(head, "Jane Doe");

    // Print the found node's data
    if (foundNode)
    {
        printf("Name: %s\n", foundNode->name);
        printf("Address: %s\n", foundNode->address);
        printf("Phone Number: %d\n", foundNode->phone_number);
        printf("Total Amount: %.2lf\n", foundNode->total_amount);
    }

    return 0;
}