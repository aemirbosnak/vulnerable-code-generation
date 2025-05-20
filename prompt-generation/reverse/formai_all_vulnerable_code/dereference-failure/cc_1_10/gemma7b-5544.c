//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a medicine
struct medicine {
    char name[50];
    char dosage[50];
    int quantity;
    float price;
};

// Create a linked list of medicines
struct node {
    struct medicine data;
    struct node* next;
};

// Function to insert a medicine into the linked list
void insert(struct node** head, struct medicine medicine) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = medicine;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        (*head)->next = new_node;
    }
}

// Function to search for a medicine in the linked list
struct medicine* search(struct node* head, char* name) {
    while (head) {
        if (strcmp(head->data.name, name) == 0) {
            return &head->data;
        }
        head = head->next;
    }

    return NULL;
}

// Function to update the quantity of a medicine in the linked list
void update(struct node* head, char* name, int quantity) {
    struct medicine* medicine = search(head, name);

    if (medicine) {
        medicine->quantity = quantity;
    }
}

// Function to delete a medicine from the linked list
void delete(struct node* head, char* name) {
    struct node* previous = NULL;
    struct node* current = head;

    while (current) {
        if (strcmp(current->data.name, name) == 0) {
            if (previous) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }

    return;
}

// Main function
int main() {
    struct node* head = NULL;

    // Create some sample medicines
    struct medicine medicine1 = {"Acetaminophen", "500mg", 100, 2.50};
    insert(&head, medicine1);

    struct medicine medicine2 = {"Ibuprofen", "200mg", 50, 3.00};
    insert(&head, medicine2);

    struct medicine medicine3 = {"Tylenol", "500mg", 20, 2.25};
    insert(&head, medicine3);

    // Search for a medicine
    struct medicine* medicine = search(head, "Acetaminophen");

    if (medicine) {
        printf("Name: %s\n", medicine->name);
        printf("Dosage: %s\n", medicine->dosage);
        printf("Quantity: %d\n", medicine->quantity);
        printf("Price: %.2f\n", medicine->price);
    } else {
        printf("Medicine not found.\n");
    }

    // Update the quantity of a medicine
    update(head, "Ibuprofen", 75);

    // Search for the updated medicine
    medicine = search(head, "Ibuprofen");

    if (medicine) {
        printf("Name: %s\n", medicine->name);
        printf("Dosage: %s\n", medicine->dosage);
        printf("Quantity: %d\n", medicine->quantity);
        printf("Price: %.2f\n", medicine->price);
    } else {
        printf("Medicine not found.\n");
    }

    // Delete a medicine
    delete(head, "Tylenol");

    // Search for the deleted medicine
    medicine = search(head, "Tylenol");

    if (medicine) {
        printf("Medicine not found.\n");
    } else {
        printf("Medicine deleted successfully.\n");
    }

    return 0;
}