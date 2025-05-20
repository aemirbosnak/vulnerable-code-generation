//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100

// Node structure for linked list
typedef struct node {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    struct node* next;
} Node;

// Function to add a new subscriber to the mailing list
void addSubscriber(Node** head, char* name, char* email) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->email, email);
    newNode->next = *head;
    *head = newNode;
    printf("Subscriber added: %s (%s)\n", newNode->name, newNode->email);
}

// Function to remove a subscriber from the mailing list
void removeSubscriber(Node** head, char* email) {
    Node* current = *head;
    Node* previous = NULL;

    while (current!= NULL && strcmp(current->email, email)!= 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Subscriber not found.\n");
    } else {
        if (previous == NULL) {
            *head = current->next;
        } else {
            previous->next = current->next;
        }
        free(current);
        printf("Subscriber removed: %s (%s)\n", current->name, current->email);
    }
}

// Function to search for a subscriber in the mailing list
Node* searchSubscriber(Node* head, char* email) {
    Node* current = head;

    while (current!= NULL && strcmp(current->email, email)!= 0) {
        current = current->next;
    }

    return current;
}

// Function to display the entire mailing list
void displayMailingList(Node* head) {
    Node* current = head;

    while (current!= NULL) {
        printf("%s (%s)\n", current->name, current->email);
        current = current->next;
    }
}

// Main function
int main() {
    Node* head = NULL;

    // Add some subscribers
    addSubscriber(&head, "John Doe", "john@example.com");
    addSubscriber(&head, "Jane Smith", "jane@example.com");

    // Display the mailing list
    printf("Mailing list:\n");
    displayMailingList(head);

    // Remove a subscriber
    removeSubscriber(&head, "john@example.com");

    // Display the updated mailing list
    printf("\nMailing list after removal:\n");
    displayMailingList(head);

    return 0;
}