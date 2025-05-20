//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new linked list
struct Node* createLinkedList() {
    struct Node* head = NULL;
    return head;
}

// Function to insert a new node at the end of the list
void insertNode(struct Node** headRef, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = (*headRef);
    (*headRef) = newNode;
}

// Function to delete the first occurrence of a node with a given value from the list
void deleteNode(struct Node** headRef, int data) {
    struct Node* temp = *headRef;
    if (temp == NULL) {
        return;
    } else if (temp->data == data) {
        *headRef = (*headRef)->next;
        free(temp);
        return;
    }

    while (temp->next!= NULL && temp->next->data!= data) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        return;
    }

    temp->next = temp->next->next;
    free(temp->next);
}

// Function to print all the nodes in the linked list
void traverseList(struct Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    struct Node* head = createLinkedList();
    insertNode(&head, 5);
    insertNode(&head, 10);
    insertNode(&head, 15);
    insertNode(&head, 20);

    traverseList(head);

    deleteNode(&head, 10);

    traverseList(head);

    return 0;
}