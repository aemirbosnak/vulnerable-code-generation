//FormAI DATASET v1.0 Category: Mailing list manager ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Node structure for linked list*/
typedef struct Node {
    char email[50];
    struct Node *next;
}Node;

/*Function to create new node*/
Node* createNode(char* email) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->email, email);
    newNode->next = NULL;
    return newNode;
}

/*Function to add node to end of linked list*/
void addNode(Node** head_ref, char* email) {
    Node* newNode = createNode(email);
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    Node* curr = *head_ref;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
}

/*Function to remove node from linked list*/
void removeNode(Node** head_ref, char* email) {
    Node* curr = *head_ref;
    Node* prev = NULL;
    while(curr != NULL && strcmp(curr->email, email) != 0) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("%s not found in list\n", email);
        return;
    }
    if (prev == NULL) {
        *head_ref = curr->next;
    }
    else {
        prev->next = curr->next;
    }
    free(curr);
    printf("%s removed from list\n", email);
}

/*Function to print linked list*/
void printList(Node* head) {
    printf("Mailing List:\n");
    Node* curr = head;
    while(curr != NULL) {
        printf("%s\n", curr->email);
        curr = curr->next;
    }
}

int main() {
    Node* head = NULL;
    char email[50];
    int choice;
    do {
        /*Menu*/
        printf("\n1. Add email to list\n");
        printf("2. Remove email from list\n");
        printf("3. Print mailing list\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter email: ");
                scanf("%s", email);
                addNode(&head, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                scanf("%s", email);
                removeNode(&head, email);
                break;
            case 3:
                printList(head);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 4);

    return 0;
}