//Gemma-7B DATASET v1.0 Category: Benchmarking ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insertAtTail(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void printList(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

int main() {
    Node* head = NULL;

    clock_t start, end;
    double timeTaken;

    start = clock();
    for (int i = 0; i < 100000; i++) {
        insertAtTail(head, i);
    }
    end = clock();

    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time taken to insert %d nodes: %.2f seconds\n", 100000, timeTaken);

    printList(head);

    return 0;
}