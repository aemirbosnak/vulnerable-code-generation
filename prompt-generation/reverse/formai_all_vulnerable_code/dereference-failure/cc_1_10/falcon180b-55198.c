//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void printList(Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void surrealistLinkedList() {
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    head = createNode(42);
    second = createNode(13);
    third = createNode(7);

    head->next = second;
    second->next = third;
    third->next = head;

    printf("Surrealist Linked List:\n");
    printList(head);

    Node* temp = head;
    while (temp!= NULL) {
        if (temp->data % 2 == 0) {
            temp->data *= 3;
        } else {
            temp->data /= 2;
        }
        temp = temp->next;
    }

    printf("Surrealist Linked List after modification:\n");
    printList(head);
}

int main() {
    surrealistLinkedList();
    return 0;
}