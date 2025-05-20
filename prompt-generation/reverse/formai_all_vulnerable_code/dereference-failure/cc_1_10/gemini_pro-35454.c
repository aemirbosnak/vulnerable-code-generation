//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: Ada Lovelace
// Welcome to my grand phonebook creation, inspired by the enigmatic Ada Lovelace!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A struct to hold each contact's details
typedef struct Contact {
    char *name;
    char *number;
} Contact;

// A linked list to store our contacts
typedef struct Node {
    Contact *contact;
    struct Node *next;
} Node;

// Function to create a new contact
Contact *create_contact(char *name, char *number) {
    Contact *contact = malloc(sizeof(Contact));
    contact->name = strdup(name);
    contact->number = strdup(number);
    return contact;
}

// Function to add a contact to the linked list
void add_contact(Node **head, Contact *contact) {
    Node *new_node = malloc(sizeof(Node));
    new_node->contact = contact;
    new_node->next = *head;
    *head = new_node;
}

// Function to print the linked list of contacts
void print_contacts(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%s - %s\n", current->contact->name, current->contact->number);
        current = current->next;
    }
}

// Function to search for a contact by name
Contact *search_contact(Node *head, char *name) {
    Node *current = head;
    while (current != NULL) {
        if (strcmp(current->contact->name, name) == 0) {
            return current->contact;
        }
        current = current->next;
    }
    return NULL;
}

// Function to delete a contact by name
void delete_contact(Node **head, char *name) {
    Node *current = *head;
    Node *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->contact->name, name) == 0) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->contact->name);
            free(current->contact->number);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

// Main function
int main() {
    // Create an empty linked list
    Node *head = NULL;

    // Add some contacts to the linked list
    add_contact(&head, create_contact("Ada Lovelace", "123-456-7890"));
    add_contact(&head, create_contact("Charles Babbage", "098-765-4321"));
    add_contact(&head, create_contact("Grace Hopper", "123-456-7890"));

    // Print the contacts
    printf("Your phonebook:\n");
    print_contacts(head);

    // Search for a contact
    char *name = "Ada Lovelace";
    Contact *contact = search_contact(head, name);
    if (contact != NULL) {
        printf("Found %s with number %s\n", contact->name, contact->number);
    } else {
        printf("Sorry, %s not found!\n", name);
    }

    // Delete a contact
    name = "Charles Babbage";
    delete_contact(&head, name);
    printf("Deleted %s\n", name);
    print_contacts(head);

    return 0;
}