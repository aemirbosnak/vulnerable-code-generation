//MISTRAL-7B DATASET v1.0 Category: Educational ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    return head;
}

void printList(Node* head) {
    Node* current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    head = insertAtBeginning(head, 5);
    head = insertAtBeginning(head, 3);
    head = insertAtBeginning(head, 2);

    printList(head);

    free(head);

    return 0;
}