//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

typedef struct Node {
    int data;
    struct Node* next;
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

    head = newNode;
}

void print(Node* head) {
    Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void roundRobin(Node* head) {
    int i = 0;
    Node* current = head;
    time_t start = time(NULL);

    while (current) {
        printf("Process %d is running...\n", current->data);
        sleep(rand() % 5);
        i++;

        if (i == MAX) {
            i = 0;
            current = head;
        } else {
            current = current->next;
        }
    }

    time_t end = time(NULL);
    printf("Total time taken: %ld seconds\n", end - start);
}

int main() {
    Node* head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);

    roundRobin(head);

    return 0;
}