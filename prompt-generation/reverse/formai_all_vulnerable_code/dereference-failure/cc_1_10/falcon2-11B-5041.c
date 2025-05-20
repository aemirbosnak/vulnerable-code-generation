//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the list
struct Node* insertAtBeginning(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head_ref;
    *head_ref = newNode;
    return *head_ref;
}

// Function to insert a new node at the end of the list
struct Node* insertAtEnd(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    struct Node* current = *head_ref;
    while (current->next!= NULL)
        current = current->next;
    current->next = newNode;
    return *head_ref;
}

// Function to delete a node from the list
struct Node* deleteNode(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    struct Node* prev = NULL;
    if (*head_ref == NULL)
        return *head_ref;
    if (current->data == data) {
        if (prev!= NULL)
            prev->next = current->next;
        else
            *head_ref = current->next;
        free(current);
        return *head_ref;
    }
    while (current->next!= NULL) {
        if (current->next->data == data) {
            prev->next = current->next;
            free(current->next);
            return *head_ref;
        }
        prev = current;
        current = current->next;
    }
    return *head_ref;
}

// Function to reverse the list
struct Node* reverseList(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* prev = NULL;
    struct Node* next = NULL;
    while (current!= NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
    return *head_ref;
}

// Function to print the list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current!= NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    head = insertAtBeginning(&head, 10);
    head = insertAtEnd(&head, 20);
    head = insertAtEnd(&head, 30);
    printList(head);
    printf("\n");
    head = reverseList(&head);
    printList(head);
    printf("\n");
    head = deleteNode(&head, 20);
    printList(head);
    return 0;
}