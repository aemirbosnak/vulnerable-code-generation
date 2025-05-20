//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void enqueue(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }
}

int dequeue(Node* head) {
    if (head == NULL) {
        return -1;
    }

    int data = head->data;
    head = head->next;
    free(head);

    return data;
}

int main() {
    Node* head = NULL;

    enqueue(head, 10);
    enqueue(head, 20);
    enqueue(head, 30);
    enqueue(head, 40);
    enqueue(head, 50);

    printf("Elements of the queue:\n");
    for (Node* current = head; current; current = current->next) {
        printf("%d ", current->data);
    }

    printf("\n");

    int data = dequeue(head);
    if (data != -1) {
        printf("Data removed: %d\n", data);
    }

    data = dequeue(head);
    if (data != -1) {
        printf("Data removed: %d\n", data);
    }

    data = dequeue(head);
    if (data != -1) {
        printf("Data removed: %d\n", data);
    }

    printf("\n");

    printf("Elements of the queue after dequeue operations:\n");
    for (Node* current = head; current; current = current->next) {
        printf("%d ", current->data);
    }

    return 0;
}