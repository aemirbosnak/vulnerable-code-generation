//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: retro
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

Node* createLinkedList() {
    Node* head = NULL;
    Node* newNode;
    int i;

    printf("Creating linked list of size %d\n", MAX_SIZE);

    for (i = 0; i < MAX_SIZE; i++) {
        newNode = createNode(i);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    return head;
}

void printLinkedList(Node* head) {
    Node* temp = head;

    printf("\nPrinting linked list:\n");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void freeLinkedList(Node* head) {
    Node* temp;

    printf("\nFreeing linked list:\n");

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;

    head = createLinkedList();
    printLinkedList(head);
    freeLinkedList(head);

    return 0;
}