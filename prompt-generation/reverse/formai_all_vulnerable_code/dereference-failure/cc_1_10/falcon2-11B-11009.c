//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Node definition
struct Node {
    int data;
    struct Node* next;
};

// Function to initialize a node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node from the list
void deleteNode(struct Node** head, int data) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp!= NULL) {
        if (prev == NULL) {
            *head = temp->next;
            free(temp);
        } else {
            prev->next = temp->next;
            free(temp);
        }
    }
}

// Function to delete the entire list
void deleteList(struct Node** head) {
    struct Node* temp = *head;
    while (temp!= NULL) {
        struct Node* next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
}

int main() {
    struct Node* head = NULL;
    insertAtBeginning(&head, 1);
    insertAtEnd(&head, 2);
    insertAtBeginning(&head, 3);
    insertAtEnd(&head, 4);

    printList(head);

    printf("Deleting node 3\n");
    deleteNode(&head, 3);
    printList(head);

    printf("Deleting node 1\n");
    deleteNode(&head, 1);
    printList(head);

    printf("Deleting node 2\n");
    deleteNode(&head, 2);
    printList(head);

    printf("Deleting node 4\n");
    deleteNode(&head, 4);
    printList(head);

    printf("Deleting the entire list\n");
    deleteList(&head);
    printList(head);

    return 0;
}