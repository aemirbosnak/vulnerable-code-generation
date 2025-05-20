//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

struct node {
    int data;
    struct node* next;
};

void insertAtTail(struct node** head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void scheduler(struct node* head) {
    struct node* current = head;
    struct node* next = NULL;
    int time = 0;

    while (current) {
        time = (time + current->data) % MAX;
        next = current->next;

        if (next) {
            next->data = time;
        }

        current = current->next;
    }

    head = current = head->next;

    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    struct node* head = NULL;
    insertAtTail(&head, 2);
    insertAtTail(&head, 3);
    insertAtTail(&head, 4);
    insertAtTail(&head, 5);

    scheduler(head);

    return 0;
}