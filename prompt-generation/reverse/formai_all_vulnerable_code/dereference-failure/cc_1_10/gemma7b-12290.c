//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store medical store data
typedef struct Medicine {
    char name[50];
    int quantity;
    float price;
} Medicine;

// Create a linked list of medicines
struct Node {
    Medicine data;
    struct Node* next;
};

// Function to insert a medicine into the linked list
void insert(struct Node** head, Medicine medicine) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = medicine;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

// Function to search for a medicine in the linked list
struct Node* search(struct Node* head, char* name) {
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
    struct Node* head = NULL;

    // Insert some medicines into the linked list
    insert(&head, (Medicine){.name = "Panadol", .quantity = 10, .price = 20.0});
    insert(&head, (Medicine){.name = "Ibuprofen", .quantity = 15, .price = 25.0});
    insert(&head, (Medicine){.name = "Paracetamol", .quantity = 20, .price = 30.0});

    // Search for a medicine in the linked list
    struct Node* foundNode = search(head, "Ibuprofen");

    // Print the details of the found medicine
    if (foundNode) {
        printf("Name: %s\n", foundNode->data.name);
        printf("Quantity: %d\n", foundNode->data.quantity);
        printf("Price: %.2f\n", foundNode->data.price);
    } else {
        printf("Medicine not found.\n");
    }

    return 0;
}