//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    struct Node* next;
    int data;
} Node;

void insert(Node* head, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }
}

void schedule(Node* head) {
    time_t now = time(NULL);
    struct Node* current = head;

    while (current) {
        time_t scheduledTime = current->data + now;

        if (scheduledTime <= now) {
            printf("Executing task: %d\n", current->data);
            current = current->next;
        } else {
            break;
        }
    }

    printf("All tasks completed.\n");
}

int main() {
    Node* head = NULL;
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);
    insert(head, 50);

    schedule(head);

    return 0;
}