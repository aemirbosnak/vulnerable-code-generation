//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = (*head);
    (*head) = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* current = (*head);
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void deleteNode(struct Node** head, int data) {
    struct Node* current = (*head);
    while (current!= NULL && current->data!= data) {
        current = current->next;
    }
    if (current == NULL) {
        return;
    }
    if (current->next == NULL) {
        *head = NULL;
    } else {
        struct Node* temp = current->next;
        current->next = temp->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    printf("Linked List: ");
    struct Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    deleteNode(&head, 10);
    printf("Linked List after deleting 10: ");
    current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    return 0;
}