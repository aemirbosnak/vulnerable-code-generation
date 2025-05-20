//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAtTail(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }
}

void schedule() {
    Node* head = NULL;
    int i, j, k, quantum = 0, totalTime = 0;

    for (i = 0; i < MAX; i++) {
        insertAtTail(head, i);
    }

    while (!head->next) {
        printf("Process %d is running...\n", head->data);
        quantum++;
        head = head->next;

        if (quantum % 3 == 0) {
            printf("Context switch...\n");
        }

        totalTime++;
    }

    printf("Total time: %d\n", totalTime);
}

int main() {
    schedule();

    return 0;
}