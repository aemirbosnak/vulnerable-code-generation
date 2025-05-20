//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for phonebook entry
typedef struct Node {
    char name[50];
    char phone[20];
    struct Node *next;
} Node;

// Function to create a new node
Node *createNode(char *name, char *phone) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new entry into the phonebook
void insertEntry(Node **head, char *name, char *phone) {
    Node *newNode = createNode(name, phone);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to search for a contact in the phonebook
Node *searchContact(Node *head, char *name) {
    Node *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to delete a contact from the phonebook
void deleteContact(Node **head, char *name) {
    if (*head == NULL) {
        printf("Phonebook is empty.\n");
        return;
    }
    if (strcmp((*head)->name, name) == 0) {
        *head = (*head)->next;
        free(*head);
    } else {
        Node *current = *head;
        Node *previous = NULL;
        while (current != NULL) {
            if (strcmp(current->name, name) == 0) {
                previous->next = current->next;
                free(current);
                break;
            }
            previous = current;
            current = current->next;
        }
    }
}

// Function to print the phonebook
void printPhonebook(Node *head) {
    if (head == NULL) {
        printf("Phonebook is empty.\n");
        return;
    }
    Node *current = head;
    while (current != NULL) {
        printf("%s: %s\n", current->name, current->phone);
        current = current->next;
    }
}

// Main function
int main() {
    Node *head = NULL;

    // Insert some entries into the phonebook
    insertEntry(&head, "John Doe", "555-123-4567");
    insertEntry(&head, "Jane Smith", "555-234-5678");
    insertEntry(&head, "Bill Jones", "555-345-6789");

    // Search for a contact in the phonebook
    Node *contact = searchContact(head, "John Doe");
    if (contact != NULL) {
        printf("Contact found: %s\n", contact->phone);
    } else {
        printf("Contact not found.\n");
    }

    // Delete a contact from the phonebook
    deleteContact(&head, "Jane Smith");

    // Print the phonebook
    printPhonebook(head);

    // Free the memory allocated for the phonebook
    while (head != NULL) {
        Node *current = head;
        head = head->next;
        free(current);
    }

    return 0;
}