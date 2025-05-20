//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNode(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void printList(Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void deleteNode(Node** head, int data) {
    Node* prev = NULL;
    Node* curr = *head;

    while (curr!= NULL && curr->data!= data) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Node not found\n");
        return;
    }

    if (prev == NULL) {
        *head = curr->next;
    } else {
        prev->next = curr->next;
    }

    free(curr);
}

void reverseList(Node** head) {
    Node* prev = NULL;
    Node* curr = *head;

    while (curr!= NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *head = prev;
}

int main() {
    Node* head = NULL;

    addNode(&head, 5);
    addNode(&head, 10);
    addNode(&head, 15);

    printf("Original list: ");
    printList(head);

    deleteNode(&head, 10);

    printf("List after deleting node with value 10: ");
    printList(head);

    reverseList(&head);

    printf("Reversed list: ");
    printList(head);

    return 0;
}