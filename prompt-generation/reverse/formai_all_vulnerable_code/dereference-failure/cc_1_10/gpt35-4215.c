//FormAI DATASET v1.0 Category: Mailing list manager ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 50
#define MAX_NAME_LENGTH 30

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    struct Node* next;
} Node;

// function to add a new node at the end of the linked list
void addNode(Node** head_ref, char* name, char* email) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    Node* last = *head_ref;

    // populate the new node
    strncpy(new_node->name, name, MAX_NAME_LENGTH);
    strncpy(new_node->email, email, MAX_EMAIL_LENGTH);
    new_node->next = NULL;

    // if the linked list is empty, set the new node as the head node
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    // traverse the linked list to the end and add the new node
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// function to delete a node from the linked list
void deleteNode(Node** head_ref, char* email) {
    if (*head_ref == NULL) {
        return;
    }

    // special case: if the head needs to be deleted
    if (strcmp((*head_ref)->email, email) == 0) {
        Node* temp = *head_ref;
        *head_ref = (*head_ref)->next;
        free(temp);
        return;
    }

    Node* prev = *head_ref;
    Node* curr = (*head_ref)->next;

    // traverse the linked list to find the node to delete
    while (curr != NULL && strcmp(curr->email, email) != 0) {
        prev = curr;
        curr = curr->next;
    }

    // if the node to delete is found, delete it
    if (curr != NULL) {
        prev->next = curr->next;
        free(curr);
    }
}

// function to display all nodes in the linked list
void displayNodes(Node* head) {
    if (head == NULL) {
        printf("No nodes in the linked list.\n");
        return;
    }

    printf("Name\t\tEmail\n");
    printf("===========================================\n");
    while (head != NULL) {
        printf("%s\t\t%s\n", head->name, head->email);
        head = head->next;
    }
}

int main() {
    Node* head = NULL;
    int choice = 0;

    printf("Mailing List Manager\n");
    printf("====================\n");

    while (choice != 4) {
        printf("Choose an option:\n");
        printf("1. Add a new contact\n");
        printf("2. Delete a contact\n");
        printf("3. Display all contacts\n");
        printf("4. Quit\n");
        scanf("%d", &choice);

        char name[MAX_NAME_LENGTH];
        char email[MAX_EMAIL_LENGTH];

        switch (choice) {
            case 1:
                printf("Enter the name:\n");
                scanf("%s", name);
                printf("Enter the email: \n");
                scanf("%s", email);
                addNode(&head, name, email);
                break;

            case 2:
                printf("Enter the email to delete:\n");
                scanf("%s", email);
                deleteNode(&head, email);
                break;

            case 3:
                displayNodes(head);
                break;

            case 4:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    }

    return 0;
}