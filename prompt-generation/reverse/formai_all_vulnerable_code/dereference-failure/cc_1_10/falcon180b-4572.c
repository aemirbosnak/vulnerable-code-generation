//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100

// Node structure for linked list
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    struct node* next;
} Node;

// Function to add a contact to the list
void addContact(Node** head, char* name, char* email) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->email, email);
    newNode->next = *head;
    *head = newNode;
    printf("%s added to the list.\n", name);
}

// Function to remove a contact from the list
void removeContact(Node** head, char* name) {
    Node* current = *head;
    Node* previous = NULL;

    while (current!= NULL && strcmp(current->name, name)!= 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("%s not found in the list.\n", name);
    } else {
        if (previous == NULL) {
            *head = current->next;
        } else {
            previous->next = current->next;
        }
        free(current);
        printf("%s removed from the list.\n", name);
    }
}

// Function to print the list
void printList(Node* head) {
    while (head!= NULL) {
        printf("%s (%s)\n", head->name, head->email);
        head = head->next;
    }
}

// Function to send an email to all contacts in the list
void sendEmail(Node* head, char* subject, char* message) {
    while (head!= NULL) {
        printf("Sending email to %s...\n", head->name);
        printf("Subject: %s\n", subject);
        printf("Message:\n%s\n", message);
        head = head->next;
    }
}

int main() {
    Node* head = NULL;

    // Add contacts to the list
    addContact(&head, "Romeo", "romeo@example.com");
    addContact(&head, "Juliet", "juliet@example.com");

    // Print the list
    printf("Mailing list:\n");
    printList(head);

    // Send an email to all contacts
    sendEmail(head, "A message from Romeo and Juliet", "Dear friend,\n\nWe wanted to share our love story with you.\n\nBest regards,\nRomeo and Juliet");

    return 0;
}