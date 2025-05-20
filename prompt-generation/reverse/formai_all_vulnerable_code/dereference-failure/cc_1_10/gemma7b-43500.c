//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
        *head = newNode;
    }
}

void roundRobin(struct Node* head) {
    int i = 0;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current) {
        next = current->next;
        current->next = head;
        i++;
        current = next;
        if (i == MAX) {
            i = 0;
        }
    }
}

int main() {
    struct Node* head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);

    roundRobin(head);

    struct Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}