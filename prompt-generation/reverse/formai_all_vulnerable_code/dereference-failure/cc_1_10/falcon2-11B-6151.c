//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return newNode;
    }
    Node* current = *head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = newNode;
    return *head;
}

Node* deleteNode(Node** head, int key) {
    Node* current = *head;
    Node* prev = NULL;
    if (current == NULL) {
        return NULL;
    }
    if (current->data == key) {
        *head = current->next;
        free(current);
        return *head;
    }
    while (current->next!= NULL) {
        if (current->next->data == key) {
            prev->next = current->next;
            free(current->next);
            return *head;
        }
        prev = current;
        current = current->next;
    }
    return *head;
}

void printList(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    printList(head); // 1 2 3
    deleteNode(&head, 2);
    printList(head); // 1 3
    return 0;
}