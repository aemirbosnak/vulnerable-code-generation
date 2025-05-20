//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures
typedef struct Appointment {
    char *name;
    char *time;
    char *location;
} Appointment;

typedef struct Node {
    Appointment *data;
    struct Node *next;
} Node;

// Functions
Node *create_node(Appointment *data);
void insert_node(Node **head, Node *new_node);
void print_list(Node *head);
void free_list(Node *head);

// Main function
int main() {
    // Create a linked list to store the appointments
    Node *head = NULL;

    // Create some appointments
    Appointment *appt1 = malloc(sizeof(Appointment));
    appt1->name = "John Doe";
    appt1->time = "10:00 AM";
    appt1->location = "Cyberpunk City";

    Appointment *appt2 = malloc(sizeof(Appointment));
    appt2->name = "Jane Doe";
    appt2->time = "11:00 AM";
    appt2->location = "Neo-Tokyo";

    // Insert the appointments into the linked list
    insert_node(&head, create_node(appt1));
    insert_node(&head, create_node(appt2));

    // Print the appointments
    print_list(head);

    // Free the linked list
    free_list(head);

    return 0;
}

// Function to create a new node
Node *create_node(Appointment *data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node into the linked list
void insert_node(Node **head, Node *new_node) {
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Function to print the linked list
void print_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("Name: %s\n", current->data->name);
        printf("Time: %s\n", current->data->time);
        printf("Location: %s\n\n", current->data->location);
        current = current->next;
    }
}

// Function to free the linked list
void free_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        Node *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
}