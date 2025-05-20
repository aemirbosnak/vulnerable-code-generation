//FormAI DATASET v1.0 Category: Linked list operations ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

// Representation of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    struct Node* temp = *head;
    if(*head == NULL) {
        *head = newNode;
        return;
    }
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to remove a node from the beginning of the list
void removeFromBeginning(struct Node** head) {
    struct Node* temp = *head;
    if(*head == NULL) {
        printf("List is empty.");
        return;
    }
    *head = (*head)->next;
    free(temp);
}

// Function to remove a node from the end of the list
void removeFromEnd(struct Node** head) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    if(*head == NULL) {
        printf("List is empty.");
        return;
    }
    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if(prev == NULL)
        *head = NULL;
    else
        prev->next = NULL;
    free(temp);
}

// Function to print the list
void printList(struct Node* head) {
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main() {
    struct Node* head = NULL;
    int choice, data;
    do {
        printf("\nEnter your choice:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Remove from the beginning\n");
        printf("4. Remove from the end\n");
        printf("5. Print the list\n");
        printf("6. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter the data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                removeFromBeginning(&head);
                break;
            case 4:
                removeFromEnd(&head);
                break;
            case 5:
                printf("List: ");
                printList(head);
                break;
            case 6:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice.");
        }
    } while(choice != 6);
    return 0;
}