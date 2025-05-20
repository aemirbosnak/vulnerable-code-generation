//Gemma-7B DATASET v1.0 Category: Benchmarking ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1024

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insert(Node* head, int data) {
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

void traverse(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    time_t start, end;
    Node* head = NULL;

    start = time(NULL);

    for (int i = 0; i < MAX_SIZE; i++) {
        insert(head, i);
    }

    traverse(head);

    end = time(NULL);

    printf("Time taken: %ld seconds\n", end - start);

    return 0;
}