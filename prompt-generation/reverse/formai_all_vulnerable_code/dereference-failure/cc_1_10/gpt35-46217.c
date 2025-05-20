//FormAI DATASET v1.0 Category: Mailing list manager ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100

// Define linked list node for mailing list
typedef struct _node {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    struct _node *next;
} Node;

// Function to add a new subscriber to the mailing list
void addSubscriber(Node **head, char name[], char email[]) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->email, email);
    newNode->next = *head;
    *head = newNode;
}

// Function to remove a subscriber from the mailing list
void removeSubscriber(Node **head, char email[]) {
    Node *curr = *head;
    Node *prev = NULL;
    while (curr != NULL) {
        if (strcmp(curr->email, email) == 0) {
            if (prev == NULL) {
                *head = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Subscriber with email %s not found\n", email);
}

// Function to print all subscribers in the mailing list
void printSubscribers(Node *head) {
    printf("Mailing List:\n");
    while (head != NULL) {
        printf("%s\t%s\n", head->name, head->email);
        head = head->next;
    }
}

// Main function to manage the mailing list
int main() {
    Node *head = NULL;
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    int choice;
    
    while (1) {
        printf("\nMailing List Manager\n");
        printf("--------------------\n");
        printf("1. Add Subscriber\n");
        printf("2. Remove Subscriber\n");
        printf("3. View Subscribers\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("\nEnter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                addSubscriber(&head, name, email);
                printf("\n%s added to mailing list\n", name);
                break;
                
            case 2:
                printf("\nEnter email: ");
                scanf("%s", email);
                removeSubscriber(&head, email);
                break;
                
            case 3:
                printSubscribers(head);
                break;
                
            case 4:
                printf("\nExiting Mailing List Manager\n");
                exit(0);
                break;
                
            default:
                printf("\nInvalid choice. Try again.\n");
                break;
        }
    }
    
    return 0;
}