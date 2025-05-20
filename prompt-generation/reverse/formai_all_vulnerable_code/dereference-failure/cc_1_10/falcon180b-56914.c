//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 1000

// Node structure for linked list
typedef struct node {
    char name[50];
    char email[100];
    struct node* next;
} Node;

// Function to add a new subscriber to the list
void addSubscriber(Node** head, char* name, char* email) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->email, email);
    newNode->next = *head;
    *head = newNode;
}

// Function to remove a subscriber from the list
void removeSubscriber(Node** head, char* email) {
    Node* currNode = *head;
    Node* prevNode = NULL;

    while (currNode!= NULL && strcmp(currNode->email, email)!= 0) {
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (currNode == NULL) {
        printf("Subscriber not found.\n");
    } else {
        if (prevNode == NULL) {
            *head = currNode->next;
        } else {
            prevNode->next = currNode->next;
        }
        free(currNode);
    }
}

// Function to display the entire list of subscribers
void displayList(Node* head) {
    while (head!= NULL) {
        printf("Name: %s, Email: %s\n", head->name, head->email);
        head = head->next;
    }
}

// Main function
int main() {
    Node* head = NULL;

    // Add some subscribers
    addSubscriber(&head, "John Doe", "john.doe@example.com");
    addSubscriber(&head, "Jane Smith", "jane.smith@example.com");

    // Display the list
    printf("Initial list:\n");
    displayList(head);

    // Remove a subscriber
    removeSubscriber(&head, "john.doe@example.com");

    // Display the updated list
    printf("\nList after removing John Doe:\n");
    displayList(head);

    return 0;
}