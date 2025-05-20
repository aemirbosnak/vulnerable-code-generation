//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: cheerful
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

void printQueue(Node* head) {
    Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);

    printQueue(head);

    // CPU Scheduling Algorithm implementation

    int quantum = 2;
    int timeSlice = 0;
    Node* current = head;

    while (current) {
        timeSlice++;
        if (timeSlice % quantum == 0) {
            printf("Process %d is running...\n", current->data);
            timeSlice = 0;
        }
        current = current->next;
    }

    return 0;
}