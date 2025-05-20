//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

typedef struct node {
    int data;
    struct node* next;
} node;

void insert(node** head, int data) {
    node* newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
        *head = newNode;
    }
}

void scheduler(node** head) {
    int i = 0;
    node* current = *head;

    while (current) {
        sleep(current->data);
        printf("Process %d is completed\n", i);
        i++;
        current = current->next;
    }

    printf("All processes are completed\n");
}

int main() {
    node* head = NULL;

    insert(&head, 5);
    insert(&head, 3);
    insert(&head, 8);
    insert(&head, 2);
    insert(&head, 4);

    scheduler(&head);

    return 0;
}