//FormAI DATASET v1.0 Category: Email Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of emails that can be stored
#define MAX_EMAILS 1000

// Define the maximum number of characters in each email
#define MAX_EMAIL_LENGTH 1000

// Define the structure of an email
typedef struct Email {
    char sender[50];
    char receiver[50];
    char subject[100];
    char message[MAX_EMAIL_LENGTH];
} Email;

// Define the structure of a node in the linked list
typedef struct Node {
    Email email;
    struct Node* next;
} Node;

// Initialize the head of the linked list
Node* head = NULL;

// Declare function prototypes
void createEmail();
void displayEmails();
void deleteEmail();

int main() {
    int choice;

    // Start the main loop
    while (1) {
        printf("\nDecentralized Email Client");
        printf("\n==========================");
        printf("\n1. Create an email");
        printf("\n2. Display all emails");
        printf("\n3. Delete an email");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: createEmail(); break;
            case 2: displayEmails(); break;
            case 3: deleteEmail(); break;
            case 4: exit(0);
            default: printf("\nInvalid choice!");
        }
    }

    return 0;
}

// Function to create an email
void createEmail() {
    // Check if the maximum number of emails has been reached
    if (countEmails() == MAX_EMAILS) {
        printf("\nCannot create any more emails.");
        return;
    }

    // Create a new email and add it to the linked list
    Email email;
    printf("\nEnter sender: "); scanf("%s", email.sender);
    printf("Enter receiver: "); scanf("%s", email.receiver);
    printf("Enter subject: "); scanf("%s", email.subject);
    printf("Enter message: "); scanf("%s", email.message);

    Node* newEmail = (Node*) malloc(sizeof(Node));
    newEmail->email = email;
    newEmail->next = NULL;

    if (head == NULL) {
        head = newEmail;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newEmail;
    }

    printf("\nEmail created successfully.");
}

// Function to display all emails
void displayEmails() {
    // Check if there are any emails to display
    if (head == NULL) {
        printf("\nNo emails to display.");
        return;
    }

    // Display all emails in the linked list
    Node* current = head;
    int emailCount = 1;

    while (current != NULL) {
        printf("\nEmail %d:", emailCount);
        printf("\nSender: %s", current->email.sender);
        printf("\nReceiver: %s", current->email.receiver);
        printf("\nSubject: %s", current->email.subject);
        printf("\nMessage: %s", current->email.message);
        current = current->next;
        emailCount++;
    }
}

// Function to delete an email
void deleteEmail() {
    // Check if there are any emails to delete
    if (head == NULL) {
        printf("\nNo emails to delete.");
        return;
    }

    // Prompt the user for the email number to delete
    int emailNum;
    printf("\nEnter email number to delete: ");
    scanf("%d", &emailNum);

    // Traverse the linked list and delete the email
    Node* previous = NULL;
    Node* current = head;
    int emailCount = 1;

    while (current != NULL && emailCount != emailNum) {
        previous = current;
        current = current->next;
        emailCount++;
    }

    if (current == NULL) {
        printf("\nInvalid email number.");
        return;
    }

    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    printf("\nEmail deleted successfully.");
}

// Function to count the number of emails
int countEmails() {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}