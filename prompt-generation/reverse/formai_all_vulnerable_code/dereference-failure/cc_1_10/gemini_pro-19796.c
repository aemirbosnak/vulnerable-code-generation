//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures
typedef struct medicine {
    char name[50];
    char description[200];
    int quantity;
    float price;
} medicine_t;

typedef struct node {
    medicine_t data;
    struct node *next;
} node_t;

// Function prototypes
node_t *create_node(medicine_t medicine);
void add_node(node_t **head, node_t *new_node);
void print_list(node_t *head);
void search_medicine(node_t *head, char *name);
void delete_node(node_t **head, char *name);
void update_medicine(node_t *head, char *name, medicine_t new_medicine);

// Main function
int main() {
    // Create a linked list to store the medicines
    node_t *head = NULL;

    // Add some medicines to the list
    medicine_t medicine1 = {"Aspirin", "Pain reliever", 100, 10.0};
    medicine_t medicine2 = {"Ibuprofen", "Pain reliever", 50, 15.0};
    medicine_t medicine3 = {"Acetaminophen", "Pain reliever", 200, 5.0};
    add_node(&head, create_node(medicine1));
    add_node(&head, create_node(medicine2));
    add_node(&head, create_node(medicine3));

    // Print the list of medicines
    printf("List of medicines:\n");
    print_list(head);

    // Search for a medicine
    char *name = "Ibuprofen";
    search_medicine(head, name);

    // Delete a medicine
    name = "Acetaminophen";
    delete_node(&head, name);

    // Update a medicine
    medicine_t new_medicine = {"Ibuprofen", "Pain reliever", 75, 15.0};
    update_medicine(head, name, new_medicine);

    // Print the updated list of medicines
    printf("Updated list of medicines:\n");
    print_list(head);

    return 0;
}

// Function to create a new node
node_t *create_node(medicine_t medicine) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = medicine;
    new_node->next = NULL;
    return new_node;
}

// Function to add a new node to the list
void add_node(node_t **head, node_t *new_node) {
    if (*head == NULL) {
        *head = new_node;
    } else {
        node_t *current_node = *head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

// Function to print the list of medicines
void print_list(node_t *head) {
    node_t *current_node = head;
    while (current_node != NULL) {
        printf("%s (%s) - Quantity: %d, Price: %.2f\n", current_node->data.name, current_node->data.description, current_node->data.quantity, current_node->data.price);
        current_node = current_node->next;
    }
}

// Function to search for a medicine
void search_medicine(node_t *head, char *name) {
    node_t *current_node = head;
    while (current_node != NULL) {
        if (strcmp(current_node->data.name, name) == 0) {
            printf("Medicine found:\n");
            printf("%s (%s) - Quantity: %d, Price: %.2f\n", current_node->data.name, current_node->data.description, current_node->data.quantity, current_node->data.price);
            return;
        }
        current_node = current_node->next;
    }

    printf("Medicine not found.\n");
}

// Function to delete a medicine
void delete_node(node_t **head, char *name) {
    node_t *current_node = *head;
    node_t *previous_node = NULL;
    while (current_node != NULL) {
        if (strcmp(current_node->data.name, name) == 0) {
            if (previous_node == NULL) {
                *head = current_node->next;
            } else {
                previous_node->next = current_node->next;
            }
            free(current_node);
            return;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }

    printf("Medicine not found.\n");
}

// Function to update a medicine
void update_medicine(node_t *head, char *name, medicine_t new_medicine) {
    node_t *current_node = head;
    while (current_node != NULL) {
        if (strcmp(current_node->data.name, name) == 0) {
            current_node->data = new_medicine;
            return;
        }
        current_node = current_node->next;
    }

    printf("Medicine not found.\n");
}