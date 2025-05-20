//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a medicine
typedef struct Medicine {
    char name[50];
    char dosage[50];
    int quantity;
    float price;
} Medicine;

// Create a linked list of medicines
typedef struct Node {
    Medicine medicine;
    struct Node* next;
} Node;

// Function to insert a medicine into the linked list
void insertMedicine(Node* head, Medicine medicine) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->medicine = medicine;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

// Function to search for a medicine in the linked list
Node* searchMedicine(Node* head, char* name) {
    while (head) {
        if (strcmp(head->medicine.name, name) == 0) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

// Function to update the quantity of a medicine in the linked list
void updateQuantity(Node* head, char* name, int quantity) {
    Node* medicineNode = searchMedicine(head, name);

    if (medicineNode) {
        medicineNode->medicine.quantity = quantity;
    }
}

// Function to delete a medicine from the linked list
void deleteMedicine(Node* head, char* name) {
    Node* previousNode = NULL;
    Node* medicineNode = searchMedicine(head, name);

    if (medicineNode) {
        if (previousNode) {
            previousNode->next = medicineNode->next;
        } else {
            head = medicineNode->next;
        }

        free(medicineNode);
    }
}

// Main function
int main() {
    // Create a linked list of medicines
    Node* head = NULL;

    // Insert some medicines into the linked list
    Medicine medicine1 = {"Acetaminophen", "500mg", 100, 5.0};
    insertMedicine(head, medicine1);

    Medicine medicine2 = {"Ibuprofen", "200mg", 50, 7.0};
    insertMedicine(head, medicine2);

    Medicine medicine3 = {"Tylenol", "250mg", 75, 6.0};
    insertMedicine(head, medicine3);

    // Search for a medicine in the linked list
    Node* medicineNode = searchMedicine(head, "Acetaminophen");

    if (medicineNode) {
        printf("Name: %s\n", medicineNode->medicine.name);
        printf("Dosage: %s\n", medicineNode->medicine.dosage);
        printf("Quantity: %d\n", medicineNode->medicine.quantity);
        printf("Price: %.2f\n", medicineNode->medicine.price);
    }

    // Update the quantity of a medicine in the linked list
    updateQuantity(head, "Ibuprofen", 100);

    medicineNode = searchMedicine(head, "Ibuprofen");

    if (medicineNode) {
        printf("Updated quantity: %d\n", medicineNode->medicine.quantity);
    }

    // Delete a medicine from the linked list
    deleteMedicine(head, "Tylenol");

    medicineNode = searchMedicine(head, "Tylenol");

    if (medicineNode) {
        printf("Tylenol has been deleted.\n");
    }

    return 0;
}