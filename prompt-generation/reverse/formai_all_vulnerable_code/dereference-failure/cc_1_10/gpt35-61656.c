//FormAI DATASET v1.0 Category: Data structures visualization ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void printList(Node* head) {
    printf("Contents of the linked list: ");
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void insert(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void delete(Node** head, int data) {
    Node* currentNode = *head;
    Node* prevNode = NULL;
    while(currentNode != NULL && currentNode->data != data) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    if(currentNode == NULL) {
        printf("Value not found in linked list.\n");
        return;
    }

    if(prevNode == NULL) {
        *head = (*head)->next;
    } else {
        prevNode->next = currentNode->next;
    }

    free(currentNode);
    printf("Value deleted from linked list.\n");
}

int main() {
    Node* head = NULL;

    insert(&head, 7);
    insert(&head, 3);
    insert(&head, 9);
    insert(&head, 2);
    insert(&head, 8);

    printList(head);

    delete(&head, 3);

    printList(head);

    return 0;
}