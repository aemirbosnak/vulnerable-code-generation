//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a contact
typedef struct contact {
    char name[50];
    char number[20];
    struct contact *next;
} contact;

// Function to create a new contact
contact *create_contact(char *name, char *number) {
    contact *new_contact = (contact *)malloc(sizeof(contact));
    strcpy(new_contact->name, name);
    strcpy(new_contact->number, number);
    new_contact->next = NULL;
    return new_contact;
}

// Function to add a contact to the phone book
void add_contact(contact **head, char *name, char *number) {
    contact *new_contact = create_contact(name, number);
    if (*head == NULL) {
        *head = new_contact;
    } else {
        contact *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_contact;
    }
}

// Function to search for a contact in the phone book
contact *search_contact(contact *head, char *name) {
    contact *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to delete a contact from the phone book
void delete_contact(contact **head, char *name) {
    contact *current = *head;
    contact *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

// Function to print the phone book
void print_phone_book(contact *head) {
    contact *current = head;
    while (current != NULL) {
        printf("%s: %s\n", current->name, current->number);
        current = current->next;
    }
}

// Main function
int main() {
    // Create a new phone book
    contact *head = NULL;

    // Add some contacts to the phone book
    add_contact(&head, "John Doe", "555-1212");
    add_contact(&head, "Jane Doe", "555-1213");
    add_contact(&head, "Bill Smith", "555-1214");
    add_contact(&head, "Mary Smith", "555-1215");

    // Search for a contact in the phone book
    contact *john_doe = search_contact(head, "John Doe");
    if (john_doe != NULL) {
        printf("Found John Doe: %s\n", john_doe->number);
    } else {
        printf("John Doe not found.\n");
    }

    // Delete a contact from the phone book
    delete_contact(&head, "Bill Smith");

    // Print the phone book
    print_phone_book(head);

    return 0;
}