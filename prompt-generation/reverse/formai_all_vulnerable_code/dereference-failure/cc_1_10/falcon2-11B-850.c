//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(Node** headRef, int data) {
    Node* newNode = createNode(data);
    Node* current = *headRef;

    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void delete(Node** headRef, int data) {
    Node* current = *headRef;
    Node* prev = NULL;

    if (*headRef == NULL) {
        return;
    }

    while (current!= NULL) {
        if (current->data == data) {
            if (prev == NULL) {
                *headRef = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

int main() {
    Node* head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    printList(head);
    printf("\n");
    delete(&head, 4);
    printList(head);
    printf("\n");
    delete(&head, 5);
    printList(head);
    printf("\n");
    delete(&head, 2);
    printList(head);
    printf("\n");
    return 0;
}