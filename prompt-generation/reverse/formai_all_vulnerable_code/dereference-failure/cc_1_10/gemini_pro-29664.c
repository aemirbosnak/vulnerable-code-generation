//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Task *next;
} Task;

Task *head, *tail;

void enqueue(int data) {
    Task *new_task = malloc(sizeof(Task));
    new_task->data = data;
    new_task->next = NULL;

    if (head == NULL) {
        head = tail = new_task;
    } else {
        tail->next = new_task;
        tail = new_task;
    }
}

int dequeue() {
    if (head == NULL) {
        return -1;
    }

    Task *temp = head;
    int data = temp->data;

    head = head->next;
    if (head == NULL) {
        tail = NULL;
    }

    free(temp);
    return data;
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    int data;
    while ((data = dequeue()) != -1) {
        printf("%d ", data);
    }

    printf("\n");
    return 0;
}