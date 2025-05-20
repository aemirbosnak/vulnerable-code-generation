//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createLinkedList(int size) {
    Node* head = NULL;
    Node* tail = NULL;
    int i;

    for (i = 0; i < size; i++) {
        Node* newNode = (Node*) malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("Error: Out of memory\n");
            exit(1);
        }

        newNode->data = i;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

void printLinkedList(Node* head) {
    Node* current = head;

    while (current!= NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

int main() {
    Node* linkedList = createLinkedList(10);
    printf("Linked List:\n");
    printLinkedList(linkedList);

    return 0;
}