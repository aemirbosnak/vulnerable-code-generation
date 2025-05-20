//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a node in the linked list
typedef struct node {
    char name[50];
    char date[20];
    char time[20];
    struct node *next;
} node;

// Function to create a new node
node *create_node(char *name, char *date, char *time) {
    node *new_node = (node *)malloc(sizeof(node));
    strcpy(new_node->name, name);
    strcpy(new_node->date, date);
    strcpy(new_node->time, time);
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node into the linked list
void insert_node(node **head, node *new_node) {
    if (*head == NULL) {
        *head = new_node;
    } else {
        node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Function to print the linked list
void print_list(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%s %s %s\n", current->name, current->date, current->time);
        current = current->next;
    }
}

// Function to free the linked list
void free_list(node *head) {
    node *current = head;
    while (current != NULL) {
        node *next = current->next;
        free(current);
        current = next;
    }
}

// Main function
int main() {
    // Create a new linked list
    node *head = NULL;

    // Insert some nodes into the linked list
    insert_node(&head, create_node("John Doe", "2023-03-08", "10:00 AM"));
    insert_node(&head, create_node("Jane Doe", "2023-03-09", "11:00 AM"));
    insert_node(&head, create_node("Peter Parker", "2023-03-10", "12:00 PM"));

    // Print the linked list
    printf("Appointments:\n");
    print_list(head);

    // Free the linked list
    free_list(head);

    return 0;
}