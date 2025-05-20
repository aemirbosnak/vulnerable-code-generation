//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: retro
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void linkedListTraversal(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    head = (Node*) malloc(sizeof(Node));
    if (head == NULL) {
        printf("Memory error\n");
        return 0;
    }
    head->data = 1;
    head->next = NULL;

    second = (Node*) malloc(sizeof(Node));
    if (second == NULL) {
        printf("Memory error\n");
        return 0;
    }
    second->data = 2;
    second->next = NULL;

    third = (Node*) malloc(sizeof(Node));
    if (third == NULL) {
        printf("Memory error\n");
        return 0;
    }
    third->data = 3;
    third->next = NULL;

    head->next = second;
    second->next = third;

    printf("Original list:\n");
    linkedListTraversal(head);

    Node* temp = head;
    head = head->next;
    temp->next = NULL;

    printf("List after deleting first node:\n");
    linkedListTraversal(head);

    return 0;
}