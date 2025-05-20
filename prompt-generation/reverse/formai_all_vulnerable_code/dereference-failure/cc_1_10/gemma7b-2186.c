//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAtTail(Node* head, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    head = newNode;
}

void printList(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

int main() {
    srand(time(NULL));

    Node* head = NULL;
    insertAtTail(head, 5);
    insertAtTail(head, 10);
    insertAtTail(head, 15);
    insertAtTail(head, 20);

    printList(head);

    int rand_num = rand() % MAX_SIZE;
    insertAtTail(head, rand_num);

    printList(head);

    return 0;
}