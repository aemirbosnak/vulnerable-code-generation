//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

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

void schedule() {
    struct node* head = NULL;
    int i, j, time = 0, quantum = 3;
    int processes = rand() % MAX;

    for (i = 0; i < processes; i++) {
        insertAtTail(&head, rand() % MAX);
    }

    printf("Process Scheduling Simulator\n");
    printf("--------------------\n");

    while (!head) {
        printf("No processes to schedule\n");
        return;
    }

    printf("Time: %d\n", time);
    printf("Process in execution: %d\n", head->data);

    for (j = 0; j < quantum; j++) {
        time++;
        printf("Time: %d\n", time);
        printf("Process in execution: %d\n", head->data);
        sleep(1);
    }

    printf("Process completed: %d\n", head->data);
    printf("Time: %d\n", time);
}

int main() {
    schedule();
    return 0;
}