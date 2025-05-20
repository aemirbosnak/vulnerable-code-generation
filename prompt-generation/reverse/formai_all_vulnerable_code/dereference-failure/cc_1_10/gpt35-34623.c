//FormAI DATASET v1.0 Category: Data structures visualization ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} Node;

void printList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        printf("List contents:\n");
        while (head != NULL) {
            printf("%d ", head->val);
            head = head->next;
        }
        printf("\n");
    }
}

void insertNode(Node** headRef, int newVal) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->val = newVal;
    newNode->next = NULL;
    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        Node* currNode = *headRef;
        while (currNode->next != NULL) {
            currNode = currNode->next;
        }
        currNode->next = newNode;
    }
}

int main() {
    Node* head = NULL;

    printf("Before inserting any nodes:\n");
    printList(head);

    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);

    printf("After inserting nodes:\n");
    printList(head);

    return 0;
}