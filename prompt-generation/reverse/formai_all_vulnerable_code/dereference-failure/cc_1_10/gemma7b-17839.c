//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct node {
    int data;
    struct node* next;
};

void insert(struct node** head, int data) {
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

    while (current) {
        next = current->next;

        // Calculate the waiting time for the current node
        int waitingTime = 0;
        struct node* temp = head;
        while (temp && temp != current) {
            waitingTime++;
            temp = temp->next;
        }

        // Print the node's data and waiting time
        printf("Node data: %d, Waiting time: %d\n", current->data, waitingTime);

        current = next;
    }
}

int main() {
    struct node* head = NULL;
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);
    insert(head, 50);

    scheduler(head);

    return 0;
}