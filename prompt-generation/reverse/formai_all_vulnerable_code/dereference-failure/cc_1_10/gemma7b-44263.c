//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a medicine
typedef struct Medicine {
    char name[20];
    char dosage[20];
    int quantity;
    float price;
} Medicine;

// Create a linked list of medicines
typedef struct Node {
    Medicine medicine;
    struct Node* next;
} Node;

// Function to insert a medicine into the linked list
void insertMedicine(Node** head, Medicine medicine) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->medicine = medicine;
    newnode->next = NULL;

    if (*head == NULL) {
        *head = newnode;
    } else {
        (*head)->next = newnode;
        *head = newnode;
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
    Node* medicine = searchMedicine(head, name);
    if (medicine) {
        medicine->medicine.quantity = quantity;
    }
}

// Function to remove a medicine from the linked list
void removeMedicine(Node** head, char* name) {
    Node* previous = NULL;
    Node* current = *head;

    while (current) {
        if (strcmp(current->medicine.name, name) == 0) {
            if (previous) {
                previous->next = current->next;
            } else {
                *head = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }

    return;
}

int main() {
    Node* head = NULL;
    Medicine medicine1 = {"Acetaminophen", "500mg", 10, 2.50};
    insertMedicine(&head, medicine1);

    Medicine medicine2 = {"Ibuprofen", "200mg", 5, 3.25};
    insertMedicine(&head, medicine2);

    Medicine medicine3 = {"Tylenol", "500mg", 7, 2.75};
    insertMedicine(&head, medicine3);

    searchMedicine(head, "Acetaminophen") -> medicine.quantity = 15;
    updateQuantity(head, "Ibuprofen", 12);
    removeMedicine(&head, "Tylenol");

    Node* current = head;
    while (current) {
        printf("%s - %s - %d - %.2f\n", current->medicine.name, current->medicine.dosage, current->medicine.quantity, current->medicine.price);
        current = current->next;
    }

    return 0;
}