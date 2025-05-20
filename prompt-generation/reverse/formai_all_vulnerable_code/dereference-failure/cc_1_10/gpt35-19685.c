//FormAI DATASET v1.0 Category: Data structures visualization ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
} Node;

void display(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = (Node*)malloc(sizeof(Node));
    head->value = 1;

    Node* tail = head;
    for (int i = 2; i <= 20; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->value = i;
        tail->next = newNode;
        tail = newNode;
    }
    tail->next = NULL;

    printf("Linked List: ");
    display(head);

    Node* temp1 = head->next;
    Node* temp2 = temp1->next;
    temp1->next = NULL;
    temp2->next = temp1;

    printf("After swapping 2nd and 3rd nodes: ");
    display(head);

    Node* newHead = (Node*)malloc(sizeof(Node));
    newHead->value = 100;
    newHead->next = head;
    head = newHead;

    printf("After adding a new node at the beginning: ");
    display(head);

    return 0;
}