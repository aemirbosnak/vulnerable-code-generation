//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store medicine information
typedef struct Medicine {
    char name[20];
    int quantity;
    float price;
} Medicine;

// Create a linked list to store medicines
typedef struct Node {
    Medicine medicine;
    struct Node* next;
} Node;

// Function to insert a medicine into the linked list
void insert(Node** head, Medicine medicine) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->medicine = medicine;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

// Function to search for a medicine in the linked list
Node* search(Node* head, char* name) {
    while (head) {
        if (strcmp(head->medicine.name, name) == 0) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

// Function to update the quantity of a medicine
void updateQuantity(Node* head, char* name, int quantity) {
    Node* medicineNode = search(head, name);

    if (medicineNode) {
        medicineNode->medicine.quantity = quantity;
    }
}

// Function to remove a medicine from the linked list
void removeMedicine(Node** head, char* name) {
    Node* medicineNode = search(head, name);

    if (medicineNode) {
        Node* prevNode = NULL;

        // If the medicine node is the first node in the list, update the head
        if (prevNode == NULL) {
            *head = medicineNode->next;
        } else {
            prevNode->next = medicineNode->next;
        }

        free(medicineNode);
    }
}

int main() {
    // Create a linked list to store medicines
    Node* head = NULL;

    // Insert some medicines into the linked list
    insert(&head, (Medicine){"Acetaminophen", 100, 2.5});
    insert(&head, (Medicine){"Ibuprofen", 50, 3.0});
    insert(&head, (Medicine){"Tylenol", 75, 2.2});

    // Search for a medicine
    Node* medicineNode = search(head, "Acetaminophen");

    // If the medicine is found, update its quantity
    if (medicineNode) {
        updateQuantity(head, "Acetaminophen", 120);
    }

    // Remove a medicine
    removeMedicine(&head, "Ibuprofen");

    // Print the medicines in the linked list
    for (Node* node = head; node; node = node->next) {
        printf("%s, %d, %.2f\n", node->medicine.name, node->medicine.quantity, node->medicine.price);
    }

    return 0;
}