//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* current = *head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void deleteNode(Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node* current = *head;
    if (current->data == data) {
        *head = current->next;
        free(current);
        return;
    }
    while (current->next!= NULL) {
        if (current->next->data == data) {
            Node* temp = current->next;
            current->next = temp->next;
            free(temp);
            return;
        }
        current = current->next;
    }
    printf("Element not found!\n");
}

int main() {
    Node* head = NULL;
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    printList(head);
    deleteNode(&head, 3);
    printList(head);
    return 0;
}