//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold the email addresses and their count
typedef struct node {
    char email[100];
    struct node* next;
} Node;

// Function declarations
Node* createNode(const char* email);
void addEmail(Node** head, const char* email);
void removeEmail(Node** head, const char* email);
void displayEmails(Node* head);
void freeList(Node** head);

// The grand main function to orchestrate our mailing list endeavor
int main() {
    Node* head = NULL;  // This shall be the illustrious head of our list
    int choice;
    char email[100];

    // A delightful loop to entertain user choices
    do {
        printf("\nWelcome to the Esteemed Mailing List Manager!\n");
        printf("1. Add an Email Address\n");
        printf("2. Remove an Email Address\n");
        printf("3. Display All Email Addresses\n");
        printf("4. Exit\n");
        printf("Please select an option (1-4): ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Kindly enter the email address to add: ");
                fgets(email, 100, stdin);
                email[strcspn(email, "\n")] = 0;  // Remove newline 
                addEmail(&head, email);
                printf("The email \"%s\" has been successfully added to our esteemed list.\n", email);
                break;
            case 2:
                printf("Alas, kindly enter the email address to remove: ");
                fgets(email, 100, stdin);
                email[strcspn(email, "\n")] = 0;  // Remove newline
                removeEmail(&head, email);
                printf("The email \"%s\" has been graciously removed from our list, if it did exist.\n", email);
                break;
            case 3:
                printf("Displaying our most cherished addresses:\n");
                displayEmails(head);
                break;
            case 4:
                printf("Exiting the grand assembly. Farewell!\n");
                break;
            default:
                printf("Oh dear! That is not a valid choice.\n");
                break;
        }
    } while (choice != 4);

    // Freeing the allocated memory before the final curtain
    freeList(&head);
    return 0;
}

// Function to create a new node for the linked list
Node* createNode(const char* email) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode) {
        strncpy(newNode->email, email, sizeof(newNode->email));
        newNode->next = NULL;
    }
    return newNode;
}

// Function to add an email to the linked list
void addEmail(Node** head, const char* email) {
    Node* newNode = createNode(email);
    newNode->next = *head;  // Insert at the head
    *head = newNode;
}

// Function to remove an email from the linked list
void removeEmail(Node** head, const char* email) {
    Node *temp = *head, *prev = NULL;

    while (temp != NULL && strcmp(temp->email, email) == 0) {
        *head = temp->next; // The head should now advance
        free(temp);
        temp = *head; // Move to the new head
    }

    while (temp != NULL) {
        while (temp != NULL && strcmp(temp->email, email) != 0) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) return;

        prev->next = temp->next; // Unlink the node
        free(temp); // Free memory
        temp = prev->next; // Move to the next node
    }
}

// Function to display all email addresses in the linked list
void displayEmails(Node* head) {
    if (head == NULL) {
        printf("The list is barren. No addresses to display.\n");
        return;
    }
    while (head != NULL) {
        printf("- %s\n", head->email);
        head = head->next;
    }
}

// Function to free the entire linked list
void freeList(Node** head) {
    Node* current = *head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL; // Clear the list
}