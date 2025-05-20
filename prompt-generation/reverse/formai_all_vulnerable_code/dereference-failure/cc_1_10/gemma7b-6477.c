//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a medicine
typedef struct Medicine {
    char name[20];
    char dosage[20];
    int quantity;
    double price;
} Medicine;

// Create a linked list of medicines
typedef struct Node {
    Medicine data;
    struct Node* next;
} Node;

// Function to insert a medicine into the linked list
void insert(Node** head, Medicine medicine) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = medicine;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        (*head)->next = new_node;
    }
}

// Function to search for a medicine in the linked list
Node* search(Node* head, char* name) {
    while (head) {
        if (strcmp(head->data.name, name) == 0) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

int main() {
    // Create a linked list of medicines
    Node* head = NULL;

    // Insert some medicines into the list
    insert(&head, (Medicine){.name = "Acetaminophen", .dosage = "500mg", .quantity = 10, .price = 2.5});
    insert(&head, (Medicine){.name = "Ibuprofen", .dosage = "200mg", .quantity = 20, .price = 3.0});
    insert(&head, (Medicine){.name = "Tylenol", .dosage = "500mg", .quantity = 15, .price = 2.7});

    // Search for a medicine in the list
    Node* found_node = search(head, "Acetaminophen");

    // Print the found medicine
    if (found_node) {
        printf("Name: %s\n", found_node->data.name);
        printf("Dosage: %s\n", found_node->data.dosage);
        printf("Quantity: %d\n", found_node->data.quantity);
        printf("Price: %.2lf\n", found_node->data.price);
    } else {
        printf("Medicine not found.\n");
    }

    return 0;
}