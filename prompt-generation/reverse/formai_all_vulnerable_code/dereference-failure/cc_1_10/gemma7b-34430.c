//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store a medicine's information
typedef struct Medicine {
    char name[20];
    int quantity;
    float price;
} Medicine;

// Create a linked list to store medicines
typedef struct Node {
    Medicine data;
    struct Node* next;
} Node;

// Function to insert a medicine into the linked list
void insertMedicine(Node** head, Medicine medicine) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = medicine;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

// Function to search for a medicine in the linked list
Medicine* searchMedicine(Node* head, char* name) {
    while (head) {
        if (strcmp(head->data.name, name) == 0) {
            return &head->data;
        }
        head = head->next;
    }

    return NULL;
}

// Function to update the quantity of a medicine in the linked list
void updateQuantity(Node* head, char* name, int quantity) {
    Medicine* medicine = searchMedicine(head, name);

    if (medicine) {
        medicine->quantity = quantity;
    }
}

// Function to delete a medicine from the linked list
void deleteMedicine(Node* head, char* name) {
    Medicine* medicine = searchMedicine(head, name);

    if (medicine) {
        Node* previousNode = NULL;

        while (head) {
            if (strcmp(head->data.name, name) == 0) {
                if (previousNode) {
                    previousNode->next = head->next;
                } else {
                    head = head->next;
                }
            } else {
                previousNode = head;
            }
        }

        free(medicine);
    }
}

int main() {
    // Create a linked list to store medicines
    Node* head = NULL;

    // Insert some medicines into the linked list
    insertMedicine(&head, (Medicine){.name = "Acetaminophen", .quantity = 100, .price = 20.0});
    insertMedicine(&head, (Medicine){.name = "Ibuprofen", .quantity = 50, .price = 15.0});
    insertMedicine(&head, (Medicine){.name = "Tylenol", .quantity = 20, .price = 12.0});

    // Search for a medicine in the linked list
    Medicine* medicine = searchMedicine(head, "Acetaminophen");

    if (medicine) {
        printf("Name: %s\n", medicine->name);
        printf("Quantity: %d\n", medicine->quantity);
        printf("Price: %.2f\n", medicine->price);
    } else {
        printf("Medicine not found.\n");
    }

    // Update the quantity of a medicine in the linked list
    updateQuantity(head, "Ibuprofen", 75);

    medicine = searchMedicine(head, "Ibuprofen");

    if (medicine) {
        printf("Name: %s\n", medicine->name);
        printf("Quantity: %d\n", medicine->quantity);
        printf("Price: %.2f\n", medicine->price);
    } else {
        printf("Medicine not found.\n");
    }

    // Delete a medicine from the linked list
    deleteMedicine(head, "Tylenol");

    medicine = searchMedicine(head, "Tylenol");

    if (medicine) {
        printf("Name: %s\n", medicine->name);
        printf("Quantity: %d\n", medicine->quantity);
        printf("Price: %.2f\n", medicine->price);
    } else {
        printf("Medicine not found.\n");
    }

    return 0;
}