//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a medicine
typedef struct Medicine {
    char name[50];
    int quantity;
    float price;
} Medicine;

// Create a linked list of medicines
typedef struct MedicineNode {
    Medicine medicine;
    struct MedicineNode* next;
} MedicineNode;

// Function to insert a medicine into the linked list
void insertMedicine(MedicineNode** head, Medicine medicine) {
    MedicineNode* newNode = (MedicineNode*)malloc(sizeof(MedicineNode));
    newNode->medicine = medicine;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

// Function to search for a medicine in the linked list
MedicineNode* searchMedicine(MedicineNode* head, char* name) {
    while (head) {
        if (strcmp(head->medicine.name, name) == 0) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

// Function to update the quantity of a medicine in the linked list
void updateQuantity(MedicineNode* head, char* name, int quantity) {
    MedicineNode* medicineNode = searchMedicine(head, name);

    if (medicineNode) {
        medicineNode->medicine.quantity = quantity;
    }
}

// Function to delete a medicine from the linked list
void deleteMedicine(MedicineNode** head, char* name) {
    MedicineNode* previousNode = NULL;
    MedicineNode* currentNode = *head;

    while (currentNode) {
        if (strcmp(currentNode->medicine.name, name) == 0) {
            if (previousNode) {
                previousNode->next = currentNode->next;
            } else {
                *head = currentNode->next;
            }
            free(currentNode);
            return;
        }
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    return;
}

int main() {
    // Create a linked list of medicines
    MedicineNode* head = NULL;

    // Insert some medicines into the linked list
    insertMedicine(&head, (Medicine){.name = "Acetaminophen", .quantity = 100, .price = 5.0});
    insertMedicine(&head, (Medicine){.name = "Ibuprofen", .quantity = 50, .price = 6.0});
    insertMedicine(&head, (Medicine){.name = "Tylenol", .quantity = 20, .price = 4.0});

    // Search for a medicine in the linked list
    MedicineNode* medicineNode = searchMedicine(head, "Acetaminophen");

    // If the medicine is found, update its quantity
    if (medicineNode) {
        updateQuantity(head, "Acetaminophen", 150);
    }

    // Delete a medicine from the linked list
    deleteMedicine(&head, "Tylenol");

    // Print the medicines in the linked list
    for (MedicineNode* node = head; node; node = node->next) {
        printf("%s: %d, $%.2f\n", node->medicine.name, node->medicine.quantity, node->medicine.price);
    }

    return 0;
}